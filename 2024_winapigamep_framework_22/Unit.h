#pragma once
#include "Object.h"
#include "Enemy.h"
#include "Road.h"
struct Stat
{
    float AttackCooldown;
    float AttackDamage;
};

class Texture;
class Unit :
    public Object
{
public:
    Unit();
    ~Unit();
    void Update() override;
    void Render(HDC _hdc) override;
public:
    virtual vector<Road*> RangeCheck() abstract;
    void Attack();
    bool AttackCoolTimeCheck(float fdt);
    void SetUnitType(UNIT_TYPE unitType) { m_unitType = unitType; }
    void SetDeploy(bool deploy) { isDeployed = deploy; }
public:
    Stat stat;
    vector<Enemy> enemyList;
    int cost;
    Vec2 m_tilePos;
    vector<Road*> attackRange;
    float attackCooldown;
    UNIT_TYPE m_unitType;
    std::string unitName,unitDescription;
    Texture* m_uTexture;
    int m_vScale;
    bool rangeCheck;
    bool isDeployed;
};

