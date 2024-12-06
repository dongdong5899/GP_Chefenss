#include "pch.h"
#include "Button.h"
#include "Object.h"
#include "InputManager.h"
#include "GDISelector.h"

Button::Button()
	: onClick()
{
}

Button::~Button()
{
}

void Button::LateUpdate()
{
	Object* owner = GetOwner();
	Vec2 pos = owner->GetPos();
	Vec2 size = owner->GetSize();
	if (GET_KEYDOWN(KEY_TYPE::LBUTTON))
	{
		POINT mousePos = GET_MOUSEPOS;
		float xDis = abs(mousePos.x - pos.x);
		float yDis = abs(mousePos.y - pos.y);
		if (xDis < size.x / 2 && yDis < size.y / 2)
		{
			cout << "Click\n";
			onClick.Invoke();
		}
	}
}

void Button::Render(HDC _hdc)
{
	GDISelector pen(_hdc, PEN_TYPE::YELLOW);
	GDISelector brush(_hdc, BRUSH_TYPE::HOLLOW);
	Object* owner = GetOwner();
	Vec2 pos = owner->GetPos();
	Vec2 size = owner->GetSize();
	RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
}