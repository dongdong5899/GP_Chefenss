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
	void SetMoveDuration(float _duration) { m_moveDuration = _duration; }
	Vec2 GetEnemyPos() { return m_pos; }
	void ApplyDamage(int _damage);
	void Die();
private:
	int m_hp;
	float m_lastMoveTime;
	float m_moveDuration;
	Vec2 m_pos;
};

