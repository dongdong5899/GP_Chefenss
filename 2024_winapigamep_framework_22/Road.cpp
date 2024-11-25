#include "pch.h"
#include "Road.h"
#include "Enemy.h"
#include "GDISelector.h"

Road::Road()
{
}

Road::~Road()
{
}



void Road::Update()
{

}

void Road::Render(HDC _hdc)
{
	{
		GDISelector pen(_hdc, PEN_TYPE::BLUE);
		GDISelector brush(_hdc, BRUSH_TYPE::BLUE);
		Vec2 vPos = GetPos();
		Vec2 vSize = GetSize();
		RECT_RENDER(_hdc, vPos.x, vPos.y
			, vSize.x, vSize.y);
	}
	ComponentRender(_hdc);
}

void Road::AssignEnemy(Enemy* _enemy)
{
	SetAssignedEnemy(_enemy);
	_enemy->SetOwner(this);
	_enemy->SetPos(GetPos());
}
