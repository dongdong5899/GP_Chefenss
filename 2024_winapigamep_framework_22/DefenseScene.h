#pragma once
#include "Scene.h"
class DefenseScene : public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
private:
	Vec2 m_startPos;
};

