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
	void SetSelectMode(bool _selectMode);
	int GetUnitCost(UNIT_TYPE _unitType) { return m_unitCost[(int)_unitType]; }
	int GetUnitAtkDamage(UNIT_TYPE _unitType) { return m_unitAtkDamage[(int)_unitType];}
	int GetUnitAtkCool(UNIT_TYPE _unitType) { return m_unitAtkCool[(int)_unitType];}
	Unit* GetUnit() { return m_currentUnit; }
private:
	UNIT_TYPE m_currentUnitType;
	UNIT_TYPE m_prevUnitType;
	Unit* m_currentUnit;
	vector<int> m_unitCost = { 100,300,500,2000,5000 };
	vector<int> m_unitAtkDamage = { 1,2,2,5,7 };
	vector<int> m_unitAtkCool = { 70,50,30,90,60 };
	bool m_selectMode;
};

