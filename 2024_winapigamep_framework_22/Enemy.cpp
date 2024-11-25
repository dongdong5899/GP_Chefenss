#include "pch.h"
#include "Road.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "MapManager.h"

const int dirX[4] = {1, 0, -1, 0};
const int dirY[4] = {0, 1, 0, -1};

Enemy::Enemy()
	: m_hp(5)
	, m_lastMoveTime(0)
	, m_moveDuration(0.25f)
	, m_road(nullptr)
{
	this->AddComponent<Collider>();
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	float time = GET_SINGLE(TimeManager)->GetTime();
	if (m_lastMoveTime + m_moveDuration < time)
	{
		m_lastMoveTime = time;

		cout << GetOwner();
		GetOwner()->SetAssignedEnemy(nullptr);
		Vec2 tilePos = GetOwner()->GetTilePos();

		for (int i = 0; i < 4; ++i)
		{
			Object* tile = GET_SINGLE(MapManager)->GetMapTileData()[tilePos.y + dirY[i]][tilePos.x + dirX[i]];
			Road* road = dynamic_cast<Road*>(tile);
			if (road != nullptr)
			{
				road->AssignEnemy(this);
				break;
			}
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
		if(m_hp <=0)
			GET_SINGLE(EventManager)->DeleteObject(this);
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
	cout << "Die\n";
}
