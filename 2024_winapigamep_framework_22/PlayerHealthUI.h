#pragma once
#include "Object.h"
class PlayerHealthUI :
    public Object
{
public:
	PlayerHealthUI();
	~PlayerHealthUI();
public:
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
public:
	int GetInterval() { return m_interval; }
	void SetMaxHealth(int _health) { m_maxHealth = _health; }
	int GetMaxHealth() { return m_maxHealth; }
	void SetHealth(int _health) { m_currentHealth = _health; }
	int GetHealth() { return m_currentHealth; }
	void HealthDown() { --m_currentHealth; }
	void SetVisualHealth(int _health) { m_visualHealth = _health; }
	int GetVisualHealth() { return m_visualHealth; }
private:
	int m_maxHealth;
	int m_visualHealth;
	int m_currentHealth;
	int m_interval;
};

