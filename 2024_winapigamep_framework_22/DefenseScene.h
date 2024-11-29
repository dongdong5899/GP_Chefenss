#pragma once
#include "Scene.h"
class DefenseScene : public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	void Update() override;

private:
	void SetUnitType();
	void GenerateUnit();
};

