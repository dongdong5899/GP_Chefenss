#pragma once
#include "Unit.h"
class Rook :
    public Unit
{
public:
    // Unit을(를) 통해 상속됨
    void Attack() override;
    void RangeCheck() override;
};

