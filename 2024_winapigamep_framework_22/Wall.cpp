#include "pch.h"
#include "Wall.h"
#include "GDISelector.h"

Wall::Wall():m_assignedUnit(nullptr)
{

}

Wall::~Wall()
{
}

void Wall::Update()
{
}

void Wall::Render(HDC _hdc)
{
	{
		GDISelector pen(_hdc, PEN_TYPE::GREEN);
		GDISelector brush(_hdc, BRUSH_TYPE::GREEN);
		Vec2 vPos = GetPos();
		Vec2 vSize = GetSize();
		RECT_RENDER(_hdc, vPos.x, vPos.y
			, vSize.x, vSize.y);
	}
	ComponentRender(_hdc);
}
