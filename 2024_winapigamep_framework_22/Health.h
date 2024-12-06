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
	void SetMaxHealth(int _maxHealth, bool _isSetCurrentHealth) 
	{
		m_maxHealth = _maxHealth; 
		if (_isSetCurrentHealth)
			m_currnetHealth = m_maxHealth;
	}
	void SetColor(BRUSH_TYPE _color) { m_color = _color; }
	int GetHealth() { return m_currnetHealth; }
	void ApplyDamage(int _damage) 
	{
		if (m_isDead) return;

		m_currnetHealth -= _damage;
		if (m_currnetHealth <= 0)
		{
			m_currnetHealth = 0;
			onDieEvent.Invoke();
			m_isDead = true;
		}
	}
	bool IsDead() { return m_isDead; }
	float GetHealthAmount() { return (float)m_currnetHealth / m_maxHealth; }
public:
	Action onDieEvent;
private:
	BRUSH_TYPE m_color;
	bool m_isDead;
	int m_maxHealth;
	int m_currnetHealth;
};

