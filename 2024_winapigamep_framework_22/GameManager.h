#pragma once
class GameManager
{
	DECLARE_SINGLE(GameManager);
public:
	
	void Init();
	int GetCoin() { return coin; }
	void SetCoin(int _coin) { coin = _coin; }
	void AddCoin(int _add) { coin += _add; }
	bool CanBuy(int cost);
private:
	int coin;
};

