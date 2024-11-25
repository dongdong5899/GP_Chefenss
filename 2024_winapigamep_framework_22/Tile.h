#pragma once
#include "Object.h"
class Tile :
    public Object
{
public:
	Tile();
	virtual ~Tile();
public:
	Vec2 GetTilePos() { return m_tilePos; }
	void SetTilePos(Vec2 _tilePos) { m_tilePos = _tilePos; }
private:
	Vec2 m_tilePos;
};

