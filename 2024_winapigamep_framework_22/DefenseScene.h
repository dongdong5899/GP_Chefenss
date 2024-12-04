#pragma once
#include "Scene.h"
class Texture;
class TextPro;
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

private:
	void SetUnitType();
	void GenerateUnit();
	void SetTexture(Texture* _texture) { m_backgroundTexture = _texture; }
	Texture* GetTexture() { return m_backgroundTexture; }
	float GetScale() { return m_backgroundScale; }
private:
	float m_lastUpdateTime;
	float m_UpdateDuration;
	Texture* m_backgroundTexture;
	float m_backgroundScale;
	TextPro* m_goldText;
};

