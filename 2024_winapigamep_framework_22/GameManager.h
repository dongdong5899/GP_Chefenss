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
private:
	void ChangeText();
private:
	int coin;
};

