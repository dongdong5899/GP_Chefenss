#pragma once
#include "Unit.h"
class Rook :
    public Unit
{
public:
    // Unit��(��) ���� ��ӵ�
    void Attack() override;
    void RangeCheck() override;
};

