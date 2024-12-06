#pragma once
#include "UI.h"
class TextPro : 
	public UI
{
public:
	TextPro();
	~TextPro();
public:
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
public:
	void SetColor(COLORREF _color) { m_color = _color; }
	void SetText(wstring _text) 
	{
		m_text = _text;
		m_length = _text.length();
	}
	void SetFontSize(int _size) { m_fontSize = _size; }
	void SetFormat(UINT _uint) { m_uint = _uint; }
private:
	COLORREF m_color;
	wstring m_text;
	int m_length;
	int m_fontSize;
	UINT m_uint;
};

