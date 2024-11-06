#pragma once
#include "Object.h"
class Road :
    public Object
{
public:
	Road();
	~Road();
public:
	void Update() override;
	void Render(HDC _hdc) override;
};