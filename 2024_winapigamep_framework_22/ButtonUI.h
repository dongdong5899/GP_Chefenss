#pragma once
#include "UI.h"
class ButtonUI :
    public UI
{
public:
    ButtonUI();
    ~ButtonUI();
public:
    // UI��(��) ���� ��ӵ�
    void Render(HDC _hdc) override;
public:
    void OnClick();
};

