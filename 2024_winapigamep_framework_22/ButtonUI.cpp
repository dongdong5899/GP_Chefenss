#include "pch.h"
#include "ButtonUI.h"
#include "Button.h"

ButtonUI::ButtonUI()
{
	AddComponent<Button>();
	GetComponent<Button>()->onClick = [this]() { this->OnClick(); };
}

ButtonUI::~ButtonUI()
{
}

void ButtonUI::Render(HDC _hdc)
{
	Vec2 pos = GetPos();
	Vec2 size = GetSize();
	RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
}

void ButtonUI::OnClick()
{
	cout << "Click" << endl;
}
