#pragma once
#include "Scene.h"
class Texture;
class TextPro;
class Unit;
class DefenseScene : public Scene
{
public:
	DefenseScene();
	~DefenseScene();
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	void SetShortcut();
	TextPro* GetGoldText() { return m_goldText; }
	void SetCostTextColor(int index, COLORREF color);
private:
	void SetUnitType(UNIT_TYPE _unitType);
	Unit* GenerateUnit();
	void SetUI();
	void UnitDelate();
	
private:
	float m_UpdateCool;
	float m_UpdateDuration;
	TextPro* m_goldText;
	TextPro* m_costText[5];
};

