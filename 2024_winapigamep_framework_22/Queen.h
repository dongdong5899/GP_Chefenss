#pragma once
#include "Unit.h"
class Queen :
    public Unit
{
public:
    Queen();
    ~Queen();
public:
    void Update() override;
    void Render(HDC _hdc) override;
    vector<Road*> RangeCheck() override;

private:
    float xAttackRange[8] = { 1,0,-1,0,-1,1,-1,1 };
    float yAttackRange[8] = { 0,1,0,-1,1,1,-1,-1 };

};

