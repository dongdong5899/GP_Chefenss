#pragma once
#include "Component.h"
#include "Action.h"

class Health :
    public Component
{
public:
	Health();
	~Health();
public:
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
public:
	void SetMaxHealth(int _maxHealth, bool _isSetCurrentHealth);
	int GetHealth() { return m_currnetHealth; }
	void ApplyDamage(int _damage);
	bool IsDead() { return m_isDead; }
	float GetHealthAmount() { return (float)m_currnetHealth / m_maxHealth; }
public:
	Action onDieEvent;
private:
	bool m_isDead;
	int m_maxHealth;
	int m_currnetHealth;
};

