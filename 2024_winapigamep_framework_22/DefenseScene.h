#pragma once
#include "Scene.h"
class DefenseScene : public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	void Update() override;

private:
	void SetUnitType();
	void GenerateUnit();
};

