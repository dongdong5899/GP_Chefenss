#pragma once
#include <set>
#include "Object.h"
class Road;
class Texture;
class Enemy :
    public Object
{
public:
	Enemy();
	virtual ~Enemy();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void SetOwner(Road* _road) { m_road = _road; }
	Road* GetOwner() { return m_road; }
	void SetMovement(Vec2 _movement) { m_movement = _movement; }
	Vec2 GetMovement() { return m_movement; }
	void SetHP(int _hp) { m_hp = _hp; }
	int GetHP() { return m_hp; }
	void SetTexture(Texture* _texture) { m_uTexture = _texture; }
	Texture* GetTexture() { return m_uTexture; }
	void SetScale(float _scale) { m_vScale = _scale; }
	float GetScale() { return m_vScale; }
	void SetMoveDuration(int _count) { m_moveDuration = _count; }
	int GetMoveSpeed() { return m_moveDuration; }
	void ApplyDamage(int _damage) { m_hp -= _damage; }
	void Die();
private:
	void PassRoad(Road* _road) { m_passedRoadSet.insert(_road); }
	bool IsPassedRoad(Road* _road) { return m_passedRoadSet.find(_road) != m_passedRoadSet.end(); }
private:
	int m_hp;
	int m_moveDuration;
	int m_currnetUpdateCount;
	Texture* m_uTexture;
	float m_vScale;
	Road* m_road;
	Vec2 m_movement;
	std::set<Road*> m_passedRoadSet;
};

