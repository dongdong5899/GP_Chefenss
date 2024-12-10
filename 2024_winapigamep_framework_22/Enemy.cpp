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
#include "SpriteRenderer.h"
#include "HealthBar.h"
#include "SceneManager.h"
#include "Scene.h"

int xDir[] = {-1, 0, 1, 0};
int yDir[] = {0, -1, 0, 1};

Enemy::Enemy()
	: m_moveDuration(5)
	, m_currnetUpdateCount(0)
	, m_road(nullptr)
	, m_healthBar(nullptr)
	, m_movement{1, 0}
	, m_cost(0)
	, m_hpIndex(0)
	, m_enemyDead(false)
{
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;

	AddComponent<SpriteRenderer>();
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->OnTransparent();
	renderer->SetScale(size);

	AddComponent<Health>();
	GetComponent<Health>()->onDieEvent += [this]() 
		{ 
			this->Die();
			GET_SINGLE(GameManager)->AddCoin(m_cost); 
		};

	m_healthBar = new HealthBar;
	m_healthBar->SetOwner(this);
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(m_healthBar, LAYER::UI);

	srand((unsigned int)time(NULL));
}

Enemy::~Enemy()
{
	GetComponent<Health>()->onDieEvent.Clear();
}

void Enemy::Update()
{
	if (IsEnemyDead()) return;

	m_currnetUpdateCount++;
	if (m_currnetUpdateCount >= m_moveDuration)
	{
		m_currnetUpdateCount = 0;

		Vec2 tilePos = GetOwner()->GetTilePos();

		vector<Vec2> nextMovement;
		wchar_t tileChar = GET_SINGLE(MapManager)->GetMapStrData()[tilePos.y][tilePos.x];
		if (tileChar == L'E')
		{
			GET_SINGLE(GameManager)->Hit();
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
}

void Enemy::Die()
{
	EnemyDie();
	GetOwner()->RemoveAssignedEnemy(this);
	GET_SINGLE(EventManager)->DeleteObject(m_healthBar);
	GET_SINGLE(EventManager)->DeleteObject(this);
}
