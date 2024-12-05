#pragma once
#include "Component.h"
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
	void ApplyDamage(int _damage) { m_currnetHealth -= _damage; }
	float GetHealthAmount() { return (float)m_currnetHealth / m_maxHealth; }
private:
	BRUSH_TYPE m_color;
	int m_maxHealth;
	int m_currnetHealth;
};

