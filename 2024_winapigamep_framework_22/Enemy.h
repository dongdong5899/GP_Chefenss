#pragma once
#include "Object.h"
class Enemy :
    public Object
{
public:
	Enemy();
	~Enemy();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
public:
	Vec2 GetEnemyPos() { return m_pos; }
private:
	int m_hp;
	Vec2 m_pos;
};

