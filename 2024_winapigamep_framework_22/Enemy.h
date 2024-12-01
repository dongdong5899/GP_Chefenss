#pragma once
#include <set>
#include "Object.h"
class Road;
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
	int GetModify() { return m_hp; }
	void SetOwner(Road* _road) { m_road = _road; }
	Road* GetOwner() { return m_road; }
	void SetMovement(Vec2 _movement) { m_movement = _movement; }
	Vec2 GetMovement() { return m_movement; }
	void PassRoad(Road* _road) { m_passedRoadSet.insert(_road); }
	bool IsPassedRoad(Road* _road) { return m_passedRoadSet.find(_road) != m_passedRoadSet.end(); }
	void ApplyDamage(int _damage) { m_hp -= _damage; }
	void Die();
private:
	int m_hp;
	float m_lastMoveTime;
	float m_moveDuration;
	Road* m_road;
	Vec2 m_movement;
	std::set<Road*> m_passedRoadSet;
};

