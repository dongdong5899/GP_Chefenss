#include "pch.h"
#include "Image.h"
#include "SpriteRenderer.h"

Image::Image()
{
	AddComponent<SpriteRenderer>();
}

Image::~Image()
{
}

void Image::Update()
{
}

void Image::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Image::SetImage(Texture* _texure, float _scale, bool _isTransparent)
{
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->SetTexture(_texure);
	renderer->SetScale(_scale);
	if (_isTransparent) renderer->OnTransparent();
}
