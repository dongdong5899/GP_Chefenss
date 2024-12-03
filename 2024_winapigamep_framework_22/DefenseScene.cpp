#include "pch.h"
#include "DefenseScene.h"
#include "MapManager.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "TimeManager.h"
#include "EnemyManager.h"
#include "ResourceManager.h"
#include "GameManager.h"

#include "Object.h"
#include "Road.h"
#include "Wall.h"

#include "Enemy.h"
#include "PawnEnemy.h"
#include "BishopEnemy.h"
#include "KnightEnemy.h"
#include "RookEnemy.h"
#include "QueenEnemy.h"

#include "Texture.h"

#include "Waver.h"

DefenseScene::DefenseScene()
	: m_lastUpdateTime(0)
	, m_UpdateDuration(0.1f)
	, m_backgroundTexture(nullptr)
	, m_backgroundScale(1.2f)
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"Background", L"Texture\\Background.bmp"));
}

DefenseScene::~DefenseScene()
{
}

void DefenseScene::Init()
{
	Waver* waver = new Waver();
	waver->SetWaveDuration(30.f);
	AddObject(waver, LAYER::DEFAULT);

	GET_SINGLE(MapManager)->SetMapMode(MAP_SIZE::BIG);
	vector<Object*> createdObj = GET_SINGLE(MapManager)->CreateTiles();
	for (Object* pObj : createdObj)
	{
		AddObject(pObj, LAYER::BACKGROUND);
	}
}

void DefenseScene::Update()
{
	float time = GET_SINGLE(TimeManager)->GetTime();
	if (m_lastUpdateTime + m_UpdateDuration < time)
	{
		m_lastUpdateTime = time;
		Scene::Update();
	}

	if (GET_KEYDOWN(KEY_TYPE::A)) {
		Enemy* pEnemy = GET_SINGLE(EnemyManager)->CreateEnemy(UNIT_TYPE::PAWN);
		AddObject(pEnemy, LAYER::ENEMY);
	}
	else if (GET_KEYDOWN(KEY_TYPE::S)) {
		Enemy* pEnemy = GET_SINGLE(EnemyManager)->CreateEnemy(UNIT_TYPE::BISHOP);
		AddObject(pEnemy, LAYER::ENEMY);
	}
	else if (GET_KEYDOWN(KEY_TYPE::D)) {
		Enemy* pEnemy = GET_SINGLE(EnemyManager)->CreateEnemy(UNIT_TYPE::KNIGHT);
		AddObject(pEnemy, LAYER::ENEMY);
	}
	else if (GET_KEYDOWN(KEY_TYPE::F)) {
		Enemy* pEnemy = GET_SINGLE(EnemyManager)->CreateEnemy(UNIT_TYPE::ROOK);
		AddObject(pEnemy, LAYER::ENEMY);
	}
	else if (GET_KEYDOWN(KEY_TYPE::G)) {
		Enemy* pEnemy = GET_SINGLE(EnemyManager)->CreateEnemy(UNIT_TYPE::QUEEN);
		AddObject(pEnemy, LAYER::ENEMY);
	}

	SetUnitType();
	if (GET_SINGLE(UnitManager)->GetSelectMode()) {
		GET_SINGLE(UnitManager)->UnitSelect();
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) && 
			GET_SINGLE(UnitManager)->GetUnitType() != UNIT_TYPE::END) {
			if(GET_SINGLE(GameManager)->CanBuy(GET_SINGLE(UnitManager)->GetUnitCost()))
			GenerateUnit();
		}
	}


}

void DefenseScene::Render(HDC _hdc)
{
	Texture* texture = GetTexture();
	int width = texture->GetWidth();
	int height = texture->GetHeight();
	float textureScale = GetScale();
	
	::TransparentBlt(_hdc, -50, 0
		, width * textureScale, height * textureScale
		, texture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));

	Scene::Render(_hdc);
}


void DefenseScene::SetUnitType()
{
	if (GET_KEYDOWN(KEY_TYPE::Q)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::PAWN);
		GET_SINGLE(UnitManager)->SetSelectMode(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::W)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::KNIGHT);
		GET_SINGLE(UnitManager)->SetSelectMode(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::E)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::BISHOP);
		GET_SINGLE(UnitManager)->SetSelectMode(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::R)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::ROOK);
		GET_SINGLE(UnitManager)->SetSelectMode(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::T)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::QUEEN);
		GET_SINGLE(UnitManager)->SetSelectMode(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::ESC)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::END);
		GET_SINGLE(UnitManager)->UnitDelete();
		GET_SINGLE(UnitManager)->SetSelectMode(false);
	}
}

void DefenseScene::GenerateUnit()
{
	Unit* unit = GET_SINGLE(UnitManager)->UnitGenerate();
	if (unit != nullptr) {
		AddObject(unit,LAYER::PLAYER);
	}
}
