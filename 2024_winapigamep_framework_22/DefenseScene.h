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
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
	TextPro* GetGoldText() { return m_goldText; }
	void SetCostTextColor(int index, COLORREF color);
private:
	void SetUnitType(UNIT_TYPE _unitType);
	Unit* GenerateUnit();
	void SetTexture(Texture* _texture) { m_backgroundTexture = _texture; }
	Texture* GetTexture() { return m_backgroundTexture; }
	float GetScale() { return m_backgroundScale; }
	void SetUI();
	void SetShortcut();
	
private:
	float m_lastUpdateTime;
	float m_UpdateDuration;
	Texture* m_backgroundTexture;
	float m_backgroundScale;
	TextPro* m_goldText;
	TextPro* m_costText[5];
};

