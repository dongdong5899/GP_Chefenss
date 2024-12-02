#pragma once
#include "Unit.h"
class Pawn :
    public Unit
{
public:
    Pawn();
    ~Pawn();
public:
    // Unit��(��) ���� ��ӵ�
    void Update() override;
    void Render(HDC _hdc) override;
    vector<Road*> RangeCheck() override;
private:
    float xAttackRange[4] = {1,0,-1,0};
    float yAttackRange[4] = { 0,1,0,-1};

};

