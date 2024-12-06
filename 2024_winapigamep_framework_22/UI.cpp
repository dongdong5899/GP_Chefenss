#include "pch.h"
#include "UI.h"
#include "Texture.h"

UI::UI()
	: m_texture()
	, m_scale(1)
	, m_isTransparent(false)
{
}

UI::~UI()
{
}

void UI::Update()
{
}

void UI::Render(HDC _hdc)
{
	Vec2 pos = GetPos();
	Texture* texture = GetTexture();
	if (texture != nullptr)
	{
		int width = texture->GetWidth();
		int height = texture->GetHeight();
		float textureScale = GetScale();

		if (m_isTransparent) {
			::TransparentBlt(_hdc
				, (int)(pos.x - width * textureScale / 2)
				, (int)(pos.y - height * textureScale / 2)
				, width * textureScale, height * textureScale
				, texture->GetTexDC()
				, 0, 0, width, height, RGB(255, 0, 255));
		}
		else {
			::StretchBlt(_hdc
				, (int)(pos.x - width * textureScale / 2)
				, (int)(pos.y - height * textureScale / 2)
				, width * textureScale, height * textureScale
				, texture->GetTexDC()
				, 0, 0, width, height,SRCCOPY);
		}
	}
	else
	{
		Vec2 size = GetSize();
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
	}
	//캐스트 영역 보여주기
	ComponentRender(_hdc);
	ComponentRender(_hdc);
	ComponentRender(_hdc);
}