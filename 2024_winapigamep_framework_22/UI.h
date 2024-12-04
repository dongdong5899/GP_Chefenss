#pragma once
#include "Object.h"

class Texture;
class UI :
	public Object
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
	void SetTexture(Texture* _texture) { m_texture = _texture; }
	Texture* GetTexture() { return m_texture; }
	void SetScale(float _scale) { m_scale = _scale; }
	float GetScale() { return m_scale; }
private:
	Texture* m_texture;
	float m_scale;
};