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
    void Render(HDC _hdc) override;
    // Unit을(를) 통해 상속됨
    void Attack() override;
    void RangeCheck() override;
private:
    float xAttackRange[4] = { 1,0,-1,0 };
    float yAttackRange[4] = { 0,1,0,-1 };
};

