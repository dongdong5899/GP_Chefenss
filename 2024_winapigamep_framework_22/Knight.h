#pragma once
#include "Unit.h"
class Knight :
    public Unit
{
public:
    Knight();
    ~Knight();
public:
    void Update() override;
    void Render(HDC _hdc) override;
    vector<Road*> RangeCheck() override;
private:
    float xAttackRange[8] = { -2,-1, 1,2,2,1,-1,-2};
    float yAttackRange[8] = { 1, 2,2,1,-1,-2,-2,-1};

    
};

