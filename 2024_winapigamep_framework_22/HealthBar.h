#pragma once
#include "Object.h"
class Enemy;
class HealthBar :
    public Object
{
public:
	HealthBar();
	~HealthBar();
public:
	virtual void Update() override;
public:
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
public:
	void SetColor(BRUSH_TYPE _color) { m_color = _color; }
	void SetAmount(float _amount) { m_amount = _amount; }
	float GetAmount() { return m_amount; }
	void SetOwner(Enemy* _owner) { m_owner = _owner; }
	Enemy* GetOwner() { return m_owner; }
private:
	Enemy* m_owner;
	BRUSH_TYPE m_color;
	float m_amount;
	int m_tileSize;
};
