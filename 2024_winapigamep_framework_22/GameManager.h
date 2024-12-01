#pragma once
class GameManager
{
	DECLARE_SINGLE(GameManager);
public:
	void AddGold(int gold) { m_gold += gold; }
	int GetGold() { return m_gold; }
private:
	int m_gold;

};

