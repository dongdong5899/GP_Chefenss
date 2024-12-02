#include "pch.h"
#include "DefenseScene.h"
#include "MapManager.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "TimeManager.h"
#include "EnemyManager.h"
#include "ResourceManager.h"

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

#include "TextPro.h"

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
	TextPro* pWaveText = new TextPro();
	pWaveText->SetText(L"Wave");
	pWaveText->SetPos({ SCREEN_WIDTH / 2, 50 });
	AddObject(pWaveText, LAYER::UI);

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

	if (GET_KEYDOWN(KEY_TYPE::CTRL)) {
		GET_SINGLE(UnitManager)->SetSelectMode(!GET_SINGLE(UnitManager)->GetSelectMode());
	}

	if (GET_SINGLE(UnitManager)->GetSelectMode()) {
		//GET_SINGLE(UnitManager)->UnitSelect();
		SetUnitType();
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) && 
			GET_SINGLE(UnitManager)->GetUnitType() != UNIT_TYPE::END) {
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
	}
	if (GET_KEYDOWN(KEY_TYPE::W)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::KNIGHT);
	}
	if (GET_KEYDOWN(KEY_TYPE::E)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::BISHOP);
	}
	if (GET_KEYDOWN(KEY_TYPE::R)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::ROOK);
	}
	if (GET_KEYDOWN(KEY_TYPE::T)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::QUEEN);
	}
	if (GET_KEYDOWN(KEY_TYPE::ESC)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::END);
	}
}

void DefenseScene::GenerateUnit()
{
	Unit* unit = GET_SINGLE(UnitManager)->UnitGenerate();
	if (unit != nullptr) {
		AddObject(unit,LAYER::PLAYER);
	}
}
