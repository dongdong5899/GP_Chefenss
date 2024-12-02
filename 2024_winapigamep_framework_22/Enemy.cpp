#include "pch.h"
#include "Road.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "MapManager.h"

int xDir[] = {-1, 0, 1, 0};
int yDir[] = {0, -1, 0, 1};

Enemy::Enemy()
	: m_hp(5)
	, m_moveDuration(5)
	, m_currnetUpdateCount(0)
	, m_road(nullptr)
	, m_movement{1, 0}
{
	this->AddComponent<Collider>();
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	m_currnetUpdateCount++;
	if (m_currnetUpdateCount >= m_moveDuration)
	{
		m_currnetUpdateCount = 0;

		GetOwner()->SetAssignedEnemy(nullptr);
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
			road->AssignEnemy(this);
		}
	}
}

void Enemy::Render(HDC _hdc)
{	
	//HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	//HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y
		, vSize.x, vSize.y);
	ComponentRender(_hdc);
	//SelectObject(_hdc, oldbrush); 
	//DeleteObject(brush);
}

void Enemy::EnterCollision(Collider* _other)
{
	std::cout << "Enter" << std::endl;
	Object* pOtherObj = _other->GetOwner();
	wstring str = pOtherObj->GetName();
	if (pOtherObj->GetName() == L"PlayerBullet")
	{
		m_hp -= 1;
		if (m_hp <= 0)
			Die();
	}
}

void Enemy::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}

void Enemy::Die()
{
	GET_SINGLE(EventManager)->DeleteObject(this);
	cout << "Die\n";
}
