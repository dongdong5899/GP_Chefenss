#include "pch.h"
#include "Tile.h"
#include "Texture.h"
#include "MapManager.h"
#include "GDISelector.h"

Tile::Tile()
	: m_tilePos()
	, m_uTexture(nullptr)
	, m_vScale(0)
{
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 16.5f;
	SetScale(size);
	SetColor(PEN_TYPE::RED);
}

Tile::~Tile()
{
}

void Tile::Render(HDC _hdc)
{
	{
		GDISelector pen(_hdc, GetColor());
		ComponentRender(_hdc);
		Vec2 vPos = GetPos();
		Vec2 vSize = GetSize();
		Texture* texture = GetTexture();
		int width = texture->GetWidth();
		int height = texture->GetHeight();
		float textureScale = GetScale();
		::TransparentBlt(_hdc
			, (int)(vPos.x - width * textureScale / 2)
			, (int)(vPos.y - height * textureScale / 2)
			, width * textureScale, height * textureScale
			, texture->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
}
