#pragma once
#include "Object.h"
#include "Enemy.h"
#include "Road.h"
struct Stat
{
    int AttackCooldown;
    int AttackDamage;
};

class Texture;
class Unit :
    public Object
{
public:
    Unit();
    virtual ~Unit();
    void Update() override;
    void Render(HDC _hdc) override;
public:
    virtual vector<Road*> RangeCheck() abstract;
    void Attack();
    bool AttackCoolTimeCheck(float fdt);
    void SetUnitType(UNIT_TYPE unitType) { m_unitType = unitType; }
    void SetDeploy(bool deploy) { isDeployed = deploy; }
    void SetAttackDamage(int _damage) { stat.AttackDamage = _damage; }
    void SetAttackCooldown(int _cooldown) { stat.AttackCooldown = _cooldown; }
    UNIT_TYPE GetUnitType() { return m_unitType; }
private:
    void SetAttackRoadColor(BRUSH_TYPE _color, BYTE _alpha, bool _isUnconditional = false);
public:
    Stat stat;
    vector<Enemy> enemyList;
    Vec2 m_tilePos;
    vector<Road*> attackRange;
    UNIT_TYPE m_unitType;
    std::string unitName,unitDescription;
    Texture* m_uTexture;
    int m_vScale;
    bool rangeCheck;
    bool isDeployed;
private:
    int attackCooldown;
};

