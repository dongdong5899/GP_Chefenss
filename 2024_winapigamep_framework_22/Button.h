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
    // Component을(를) 통해 상속됨
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    Action onClick;
};

