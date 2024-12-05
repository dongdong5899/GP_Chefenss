#include "pch.h"
#include "Tile.h"
#include "Texture.h"
#include "MapManager.h"
#include "GDISelector.h"

Tile::Tile()
	: m_tilePos{}
	, m_uTexture(nullptr)
	, m_vScale(0)
	, m_alpha(255)
	, m_fillColor()
{
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 16.5f;
	SetScale(size);
	SetColor(BRUSH_TYPE::RED);
}

Tile::~Tile()
{
}

void Tile::Render(HDC _hdc)
{
	ComponentRender(_hdc);
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	Texture* texture = GetTexture();
	int width = texture->GetWidth();
	int height = texture->GetHeight();
	float textureScale = GetScale();

	BLENDFUNCTION bfunc;
	bfunc.BlendOp = AC_SRC_OVER;
	bfunc.BlendFlags = 0;
	bfunc.SourceConstantAlpha = GetAlpha();
	bfunc.AlphaFormat = 0;

	{
		GDISelector brush(_hdc, GetColor());
		RECT_RENDER(_hdc, vPos.x, vPos.y, width * textureScale, height * textureScale);
	}

	AlphaBlend(_hdc
		, (int)(vPos.x - width * textureScale / 2)
		, (int)(vPos.y - height * textureScale / 2)
		, width * textureScale, height * textureScale
		, texture->GetTexDC()
		, 0, 0, width, height, bfunc);
}
