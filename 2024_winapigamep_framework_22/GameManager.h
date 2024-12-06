#pragma once
class GameManager
{
	DECLARE_SINGLE(GameManager);
public:
	
	void Init();
	int GetCoin() { return coin; }
	void SetCoin(int _coin);
	void AddCoin(int _add);
	bool CanBuy(int cost);
	void Buy(UNIT_TYPE _unitType);
	void CheckUnitCost();
	void Hit();
	void SetHealth(int _health) { m_health = _health; }
	int GetHealth() { return m_health; }
private:
	void UpdateShopText();
	void UpdateHealth();
	void Die();
private:
	int coin;
	int m_health;
};

