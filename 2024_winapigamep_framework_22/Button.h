#pragma once
#include "Component.h"
#include <functional>
using OnClick = std::function<void()>;
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
    OnClick onClick;
};

