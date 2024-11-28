#pragma once
class Tile;
class UnitManager
{
	DECLARE_SINGLE(UnitManager);

public:
	void Init();
	void Update();
public:
	void SetUnitType(UNIT_TYPE _unitType) { m_currentUnit = _unitType; }
	UNIT_TYPE GetUnitType() { return m_currentUnit; }
private:
	UNIT_TYPE m_currentUnit;
};

