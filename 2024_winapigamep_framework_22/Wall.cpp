#include "pch.h"
#include "Wall.h"
#include "GDISelector.h"
#include "ResourceManager.h"

Wall::Wall()
	: m_assignedUnit(nullptr)
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"Wall", L"Texture\\PlayerTile.bmp"));
}

Wall::~Wall()
{
}

void Wall::Update()
{
}
