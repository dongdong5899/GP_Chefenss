#pragma once
#include "Action.h"
class GameManager
{
	DECLARE_SINGLE(GameManager);
public:
	
	void Init();
	int GetCoin() { return m_coin; }
	void SetCoin(int _coin);
	void AddCoin(int _add);
	bool CanBuy(int cost);
	void Buy(UNIT_TYPE _unitType);
	void CheckUnitCost();
	void Hit();
	void SetHealth(int _health) { m_health = _health; }
	int GetHealth() { return m_health; }
	void SetMaxHealth(int _health) { m_maxHealth = _health; }
	int GetMaxHealth() { return m_maxHealth; }
	void SetEndState(bool _isClear) { m_isClear = _isClear; }
	bool GetEndState() { return m_isClear; }
private:
	void UpdateShopText();
	void UpdateHealth();
	void Die();
private:
	int m_coin;
	int m_health;
	int m_maxHealth;
	bool m_isClear;
public:
	Action onHit;
};

