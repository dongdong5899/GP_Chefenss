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
	void SetText(wstring _text) { m_text = _text; }
	void SetFormat(UINT _uint) { m_uint = _uint; }
private:
	COLORREF m_color;
	wstring m_text;
	UINT m_uint;
};

