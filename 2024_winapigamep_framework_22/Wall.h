#pragma once
#include "Tile.h"
class Unit;
class Wall :
    public Tile
{
public:
	Wall();
	~Wall();
public:
	void Update() override;
	Unit* GetAssignedUnit() { return m_assignedUnit; }
	void SetAssignedUnit(Unit* _unit) { m_assignedUnit = _unit; }
private:
	Unit* m_assignedUnit;
};

