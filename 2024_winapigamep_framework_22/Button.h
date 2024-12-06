#pragma once
#include "Component.h"
#include "Action.h"

class Button :
    public Component
{
public:
    Button();
    ~Button();
public:
    // Component��(��) ���� ��ӵ�
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    Action onClick;
};

