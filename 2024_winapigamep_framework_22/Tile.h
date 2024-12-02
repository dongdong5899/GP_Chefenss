#pragma once
#include "Object.h"
class Texture;
class Tile :
    public Object
{
public:
	Tile();
	virtual ~Tile();
public:
	virtual void Render(HDC _hdc) override;
public:
	Vec2 GetTilePos() { return m_tilePos; }
	void SetTilePos(Vec2 _tilePos) { m_tilePos = _tilePos; }
	Texture* GetTexture() { return m_uTexture; }
	void SetTexture(Texture* _texture) { m_uTexture = _texture; }
	float GetScale() { return m_vScale; }
	void SetScale(float _scale) { m_vScale = _scale; }
private:
	Vec2 m_tilePos;
	Texture* m_uTexture;
	float m_vScale;
};

