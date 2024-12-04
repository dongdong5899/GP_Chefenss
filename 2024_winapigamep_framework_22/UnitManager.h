#pragma once
#include "Unit.h"
class UnitManager
{
	DECLARE_SINGLE(UnitManager);

public:
	void Init();
	void Update();
public:
	void SetUnitType(UNIT_TYPE _unitType) { m_currentUnitType = _unitType; }
	UNIT_TYPE GetUnitType() { return m_currentUnitType; }
	Unit* TypeUnitGenerate();
	Unit* UnitGenerate();
	void UnitSelect();
	void UnitDelete();
	bool GetSelectMode() { return m_selectMode; }
	void SetSelectMode(bool _selectMode) { m_selectMode = _selectMode; }
	int GetUnitCost();
	Unit* GetUnit() { return m_currentUnit; }
private:
	UNIT_TYPE m_currentUnitType;
	UNIT_TYPE m_prevUnitType;
	Unit* m_currentUnit;
	vector<int> unitCost = { 100,300,500,2000,5000 };
	bool m_selectMode;
};

