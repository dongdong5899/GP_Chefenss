#include "pch.h"
#include "Button.h"
#include "Object.h"
#include "InputManager.h"

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
		if (onClick != nullptr && xDis < size.x && yDis < size.y)
		{
			onClick();
		}
	}
}

void Button::Render(HDC _hdc)
{
	Object* owner = GetOwner();
	Vec2 pos = owner->GetPos();
	Vec2 size = owner->GetSize();
	RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
}
