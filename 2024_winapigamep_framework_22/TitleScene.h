#pragma once
#include "Scene.h"
class TitleScene 
	: public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	virtual void Init() override;
	virtual void Update() override;
private:
	void Quit();
};

