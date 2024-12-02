#pragma once
#include "Object.h"

typedef unsigned int UINT;
class UI :
	public Object
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Update() override;
};

