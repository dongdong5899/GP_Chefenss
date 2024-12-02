#pragma once
#include "Unit.h"
class Bishop :
    public Unit
{
public:
    Bishop();
    ~Bishop();
public:
    void Update() override;
    void Render(HDC _hdc) override;
    vector<Road*> RangeCheck() override;
    
private:
    float xAttackRange[4] = { -1,1,-1,1 };
    float yAttackRange[4] = { 1,1,-1,-1 };

};

