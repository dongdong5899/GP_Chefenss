#pragma once
#include "UI.h"
class ButtonUI :
    public UI
{
public:
    ButtonUI();
    ~ButtonUI();
public:
    // UI을(를) 통해 상속됨
    void Render(HDC _hdc) override;
public:
    void OnClick();
};

