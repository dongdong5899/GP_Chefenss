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
private:
	void ChangeText();
private:
	int coin;
};

