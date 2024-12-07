#pragma once
#include "Unit.h"
class Rook :
    public Unit
{
public:
    Rook();
    ~Rook();
public:
    void Update() override;
    vector<Road*> RangeCheck() override;
private:
    float xAttackRange[4] = { 1,0,-1,0 };
    float yAttackRange[4] = { 0,1,0,-1 };

};

