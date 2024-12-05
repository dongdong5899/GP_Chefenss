#include "pch.h"
#include "Road.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "MapManager.h"
#include "Texture.h"
#include "Health.h"
#include "GameManager.h"

int xDir[] = {-1, 0, 1, 0};
int yDir[] = {0, -1, 0, 1};

Enemy::Enemy()
	: m_hp(5)
	, m_moveDuration(5)
	, m_uTexture(nullptr)
	, m_vScale(1)
	, m_currnetUpdateCount(0)
	, m_road(nullptr)
	, m_movement{1, 0}
{
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	SetScale(size);

	AddComponent<Health>();
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (GetHP() == 0) return;
	m_currnetUpdateCount++;
	if (m_currnetUpdateCount >= m_moveDuration)
	{
		m_currnetUpdateCount = 0;

		Vec2 tilePos = GetOwner()->GetTilePos();

		vector<Vec2> nextMovement;
		wchar_t tileChar = GET_SINGLE(MapManager)->GetMapStrData()[tilePos.y][tilePos.x];
		if (tileChar == L'E')
		{
			Die();
			return;
		}
		else if (tileChar == L'T')
		{
			for (int i = 0; i < 4; ++i)
			{
				wchar_t turnTileChar = GET_SINGLE(MapManager)->GetMapStrData()[tilePos.y + yDir[i]][tilePos.x + xDir[i]];
				if (turnTileChar == L'E')
				{
					SetMovement({ xDir[i], yDir[i] });
					nextMovement.clear();
					break;
				}
				if (turnTileChar == (L'0' + i))
				{
					Object* tile = GET_SINGLE(MapManager)->GetMapTileData()[tilePos.y + yDir[i]][tilePos.x + xDir[i]];
					Road* road = dynamic_cast<Road*>(tile);
					if (road != nullptr && !IsPassedRoad(road))
					{
						nextMovement.push_back({ xDir[i], yDir[i] });
					}
				}
			}
		}
		if (nextMovement.size() != 0)
		{
			int index = rand() % nextMovement.size();
			SetMovement(nextMovement[index]);
		}

		Vec2 movement = GetMovement();
		Object* tile = GET_SINGLE(MapManager)->GetMapTileData()[tilePos.y + movement.y][tilePos.x + movement.x];
		Road* road = dynamic_cast<Road*>(tile);
		if (road != nullptr)
		{
			PassRoad(road);
			GetOwner()->RemoveAssignedEnemy(this);
			road->AddAssignedEnemy(this);
		}
	}
}

void Enemy::Render(HDC _hdc)
{
	ComponentRender(_hdc);
	Vec2 vPos = GetPos();
	Texture* texture = GetTexture();
	int width = texture->GetWidth();
	int height = texture->GetHeight();
	float textureScale = GetScale();
	::TransparentBlt(_hdc
		, (int)(vPos.x - width * textureScale / 2)
		, (int)(vPos.y - height * textureScale / 2)
		, width * textureScale, height * textureScale
		, texture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
}

void Enemy::ApplyDamage(int _damage)
{
	int hp = GetHP();
	hp -= _damage;
	if (hp < 0) hp = 0;
	SetHP(hp);

	if (hp <= 0)
		Die();
}

void Enemy::Die()
{
	GetOwner()->RemoveAssignedEnemy(this);
	GET_SINGLE(EventManager)->DeleteObject(this);
	GET_SINGLE(GameManager)->AddCoin(cost);
}
