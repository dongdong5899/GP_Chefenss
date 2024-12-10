#include "pch.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Object.h"

SpriteRenderer::SpriteRenderer()
	: m_offset{}
	, m_texture(nullptr)
	, m_scale(1.f)
	, m_alpha(255)
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
	Vec2 vPos = owner->GetPos();
	vPos += GetOffset();
	Texture* texture = GetTexture();
	if (texture != nullptr)
	{
		int width = texture->GetWidth();
		int height = texture->GetHeight();
		float textureScale = GetScale();

		BLENDFUNCTION bfunc;
		bfunc.BlendOp = AC_SRC_OVER;
		bfunc.BlendFlags = 0;
		bfunc.SourceConstantAlpha = GetAlpha();
		bfunc.AlphaFormat = AC_SRC_ALPHA;

		if (IsTransparent()) {
			::TransparentBlt(_hdc
				, (int)(vPos.x - width * textureScale / 2)
				, (int)(vPos.y - height * textureScale / 2)
				, width * textureScale, height * textureScale
				, texture->GetTexDC()
				, 0, 0, width, height, RGB(255, 0, 255));
			if (GetAlpha() > 0)
			{
				::AlphaBlend(_hdc
					, (int)(vPos.x - width * textureScale / 2)
					, (int)(vPos.y - height * textureScale / 2)
					, width * textureScale, height * textureScale
					, texture->GetTexDC()
					, 0, 0, width, height, bfunc);
			}
		}
		else {
			::StretchBlt(_hdc
				, (int)(vPos.x - width * textureScale / 2)
				, (int)(vPos.y - height * textureScale / 2)
				, width * textureScale, height * textureScale
				, texture->GetTexDC()
				, 0, 0, width, height, SRCCOPY);
		}
	}
	else
	{
		Vec2 size = owner->GetSize();
		RECT_RENDER(_hdc, vPos.x, vPos.y, size.x, size.y);
	}
}
