#pragma once
#include "Unit.h"
class Pawn :
    public Unit
{
public:
    // Unit��(��) ���� ��ӵ�
    void Attack() override;
    void RangeCheck() override;
private:
    float xAttackRange[4] = {1,0,-1,0};
    float yAttackRange[4] = { 0,1,0,-1};
};

