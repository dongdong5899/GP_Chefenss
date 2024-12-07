#include "pch.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Object.h"

SpriteRenderer::SpriteRenderer()
	: m_offset{}
	, m_texture(nullptr)
	, m_scale(1.f)
	, m_isTransparent(false)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::LateUpdate()
{
}

void SpriteRenderer::Render(HDC _hdc)
{
	Object* owner = GetOwner();
	Vec2 pos = owner->GetPos();
	pos += GetOffset();
	Texture* texture = GetTexture();
	if (texture != nullptr)
	{
		int width = texture->GetWidth();
		int height = texture->GetHeight();
		float textureScale = GetScale();

		if (IsTransparent()) {
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
				, 0, 0, width, height, SRCCOPY);
		}
	}
	else
	{
		Vec2 size = owner->GetSize();
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
	}
}
