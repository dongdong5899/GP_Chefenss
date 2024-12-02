#pragma once
#include "Scene.h"
class DefenseScene : public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	void Update() override;

private:
	void ResetTimer(float _updateDuration) 
	{ 
		m_lastUpdateTime = 0; 
		m_UpdateDuration = _updateDuration; 
	}
	void SetUnitType();
	void GenerateUnit();
	bool WallChecker();
private:
	float m_lastUpdateTime;
	float m_UpdateDuration;
};

