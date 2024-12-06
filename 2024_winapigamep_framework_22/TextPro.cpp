#include "pch.h"
#include "TextPro.h"
#include "GDISelector.h"

TextPro::TextPro()
	: m_uint(DT_CENTER | DT_NOCLIP)
	, m_text(L"")
	, m_fontSize(20)
	, m_length(0)
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
	/*HFONT hFont = CreateFont(m_fontSize, m_fontSize, 0, 0, 0, false, false, false
		, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("NeoµÕ±Ù¸ð pro"));
	HFONT defaultFont = (HFONT)SelectObject(_hdc, hFont);*/

	SetTextColor(_hdc, m_color);
	SetBkMode(_hdc, TRANSPARENT);
	Vec2 pos = GetPos();
	Vec2 size = GetSize();
	RECT rect = RECT_MAKE(pos.x, pos.y, size.x, size.y);
	DrawText(_hdc, m_text.c_str(), m_length, &rect, m_uint);
	
	//SelectObject(_hdc, defaultFont);
}
