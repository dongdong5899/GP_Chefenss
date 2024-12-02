#include "pch.h"
#include "TextPro.h"
#include "GDISelector.h"

TextPro::TextPro()
	: m_text(L"")
	, m_uint(DT_CENTER | DT_NOCLIP)
	, m_color(RGB(0, 0, 0))
{
}

TextPro::~TextPro()
{
}

void TextPro::Update()
{
}

void TextPro::Render(HDC _hdc)
{
	{
		//글자 사이즈
		SetTextColor(_hdc, m_color);
		SetBkMode(_hdc, TRANSPARENT);
		Vec2 pos = GetPos();
		Vec2 size = GetSize();
		RECT rect = RECT_MAKE(pos.x, pos.y, size.x, size.y);
		DrawText(_hdc, m_text.c_str(), m_text.length(), &rect, m_uint);
	}
}
