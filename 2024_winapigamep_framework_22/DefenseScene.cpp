#include "pch.h"
#include "DefenseScene.h"
#include "MapManager.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "TimeManager.h"
#include "EnemyManager.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "EventManager.h"

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

#include "Waver.h"
#include "PlayerHealthUI.h"
#include "Button.h"
#include "Image.h"

DefenseScene::DefenseScene()
	: m_UpdateCool(0)
	, m_UpdateDuration(0.01f)
	, m_goldText(nullptr)
	, m_costText{ nullptr }
{
	SetBackgroundTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"GameBackground", L"Texture\\Background.bmp"));
	SetBackgroundScale(5.f);
}

DefenseScene::~DefenseScene()
{
}

void DefenseScene::Init()
{
	SetUI();
	GET_SINGLE(GameManager)->Init();

	Vec2 mapOffset = GET_SINGLE(MapManager)->GetMapOffset();
	PlayerHealthUI* playerHealth = new PlayerHealthUI();
	playerHealth->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x, SCREEN_HEIGHT / 2 + 210 + mapOffset.y });
	playerHealth->SetSize({ 650, 20 });
	AddObject(playerHealth, LAYER::UI);

	Waver* waver = new Waver();
	waver->SetWaveDuration(30.f);
	AddObject(waver, LAYER::DEFAULT);

	vector<Object*> createdObj = GET_SINGLE(MapManager)->CreateTiles();
	for (Object* pObj : createdObj)
	{
		AddObject(pObj, LAYER::BACKGROUND);
	}

}

void DefenseScene::Update()
{
	m_UpdateCool += GET_SINGLE(TimeManager)->GetDT();
	float time = GET_SINGLE(TimeManager)->GetTime();
	while (m_UpdateDuration < m_UpdateCool)
	{
		m_UpdateCool -= m_UpdateDuration;
		Scene::Update();
	}

	if (GET_KEYDOWN(KEY_TYPE::ESC)) {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::END);
		if (GET_SINGLE(UnitManager)->GetUnit()) {
			GET_SINGLE(UnitManager)->UnitDelete();
		}
		GET_SINGLE(UnitManager)->SetSelectMode(false);
	}

	if (GET_SINGLE(UnitManager)->GetSelectMode()) {
		GET_SINGLE(UnitManager)->UnitSelect();
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) && 
			GET_SINGLE(UnitManager)->GetUnitType() != UNIT_TYPE::END) {
			Unit* unit = GenerateUnit();
			if (unit) {
				GET_SINGLE(GameManager)->Buy(unit->GetUnitType());
				GET_SINGLE(UnitManager)->UnitDelete();
			}
		}
	}

	if (GET_KEYDOWN(KEY_TYPE::RBUTTON)) {
		UnitDelate();
	}
}

void DefenseScene::SetShortcut()
{
	if (GET_KEYDOWN(KEY_TYPE::NUM_1)) {
		SetUnitType(UNIT_TYPE::PAWN);
	}
	if (GET_KEYDOWN(KEY_TYPE::NUM_2)) {
		SetUnitType(UNIT_TYPE::KNIGHT);
	}
	if (GET_KEYDOWN(KEY_TYPE::NUM_3)) {
		SetUnitType(UNIT_TYPE::BISHOP);
	}
	if (GET_KEYDOWN(KEY_TYPE::NUM_4)) {
		SetUnitType(UNIT_TYPE::ROOK);
	}
	if (GET_KEYDOWN(KEY_TYPE::NUM_5)) {
		SetUnitType(UNIT_TYPE::QUEEN);
	}
}

void DefenseScene::SetCostTextColor(int index, COLORREF color)
{
	m_costText[index]->SetColor(color);
}

void DefenseScene::SetUnitType(UNIT_TYPE _unitType)
{
	if (GET_SINGLE(GameManager)->CanBuy(GET_SINGLE(UnitManager)->GetUnitCost(_unitType)))
	{
		GET_SINGLE(UnitManager)->SetSelectMode(true);
		GET_SINGLE(UnitManager)->SetUnitType(_unitType);
	}
	else {
		GET_SINGLE(UnitManager)->SetUnitType(UNIT_TYPE::END);
		if (GET_SINGLE(UnitManager)->GetUnit()) {
			GET_SINGLE(UnitManager)->UnitDelete();
		}
	}
}

Unit* DefenseScene::GenerateUnit()
{
	Unit* unit = GET_SINGLE(UnitManager)->UnitGenerate();
	if (unit != nullptr) {
		AddObject(unit,LAYER::PLAYER);
		return unit;
	}
	else {
		return nullptr;
	}
}

void DefenseScene::SetUI()
{
	Image* exitBtn = new Image();
	exitBtn->SetPos({ 150, SCREEN_HEIGHT - 50 });
	exitBtn->SetSize({ 150, 40 });
	Texture* cardTexture = GET_SINGLE(ResourceManager)->
		TextureLoad(L"ButtonArea", L"Texture\\Unit_Card_Area.bmp");
	exitBtn->SetImage(cardTexture, 0.6f);

	Button* button = new Button;
	button->onClick += []() { GET_SINGLE(EventManager)->SceneChange(L"TitleScene"); };
	exitBtn->AddComponent(button);
	AddObject(exitBtn, LAYER::UI);

	TextPro* exitTxt = new TextPro;
	exitTxt->SetPos({ 150, SCREEN_HEIGHT - 60 });
	exitTxt->SetColor(RGB(255, 255, 255));
	exitTxt->SetText(L"그만하기");
	exitTxt->SetFontSize(20);
	AddObject(exitTxt, LAYER::UI);

	Vec2 mapOffset = GET_SINGLE(MapManager)->GetMapOffset();

	//buttonArea
	{
		Image* buttonArea = new Image();
		buttonArea->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x , SCREEN_HEIGHT / 2 + 310 + mapOffset.y });
		buttonArea->SetSize({ 0, 0 });
		Texture* backgroundTexture = GET_SINGLE(ResourceManager)->
			TextureLoad(L"ButtonArea", L"Texture\\Unit_Card_Area.bmp");
		buttonArea->SetImage(backgroundTexture, 3.f);
		AddObject(buttonArea, LAYER::UI);
	}

	wstring unitName[5] = {L"Pawn", L"Knight", L"Bishop", L"Rook", L"Queen"};
	for (int i = 0; i < 5; ++i)
	{
		UNIT_TYPE type = (UNIT_TYPE)i;

		Image* button_backGround = new Image();
		button_backGround->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x - 300 + 150 * i, SCREEN_HEIGHT / 2 + 290 + mapOffset.y });
		button_backGround->SetSize({ 72, 98 });
		Texture* cardTexture = GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp");
		button_backGround->SetImage(cardTexture, 3.f);

		Button* buttonCompo = new Button;
		buttonCompo->onClick += [this, type]() { SetUnitType(type); };
		button_backGround->AddComponent(buttonCompo);

		AddObject(button_backGround, LAYER::UI);

		Image* button_unit = new Image();
		Vec2 backgroundPos = button_backGround->GetPos();
		button_unit->SetPos({ backgroundPos.x,backgroundPos.y - 10 });
		Texture* unitTexture = GET_SINGLE(ResourceManager)->
			TextureLoad(unitName[i], L"Texture\\Player" + unitName[i] + L".bmp");
		button_unit->SetImage(unitTexture, 2.f, true);
		AddObject(button_unit, LAYER::UI);

		m_costText[i] = new TextPro;
		m_costText[i]->SetPos({ backgroundPos.x,backgroundPos.y + 15 });
		m_costText[i]->SetText(std::to_wstring(GET_SINGLE(UnitManager)->GetUnitCost(type)) + L"G");
		m_costText[i]->SetColor(RGB(255, 0, 0));
		AddObject(m_costText[i], LAYER::UI);

		TextPro* atkText = new TextPro();
		atkText->SetPos({ backgroundPos.x,backgroundPos.y + 55 });
		atkText->SetColor(RGB(255, 255, 255));
		atkText->SetText(L"ATK : " + std::to_wstring(GET_SINGLE(UnitManager)->GetUnitAtkDamage(type)));
		AddObject(atkText, LAYER::UI);

		TextPro* atkspeedText = new TextPro();
		atkspeedText->SetPos({ backgroundPos.x,backgroundPos.y + 75 });
		atkspeedText->SetColor(RGB(255, 255, 255));
		atkspeedText->SetText(L"ATKCOOL : 0." + std::to_wstring(GET_SINGLE(UnitManager)->GetUnitAtkCool(type) / 10) + L"s");
		AddObject(atkspeedText, LAYER::UI);
	}

	//goldText
	{
		m_goldText = new TextPro();
		m_goldText->SetText(L"Gold : " + std::to_wstring(GET_SINGLE(GameManager)->GetCoin()));
		m_goldText->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x, 140 + mapOffset.y });
		AddObject(m_goldText, LAYER::UI);
	}
}

void DefenseScene::UnitDelate()
{
	Vec2 mousePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();

	int mapWidth = map[1].size();
	int mapHeight = map.size();

	if (mousePos.x < 0 || mousePos.y < 0 || mousePos.x >= mapWidth || mousePos.y >= mapHeight) {
		return;
	}
	else {
		Tile* tile = map[mousePos.y][mousePos.x];

		Wall* wall = dynamic_cast<Wall*>(tile);
		if (wall) {
			Unit* unit = wall->GetAssignedUnit();
			if (unit) {
				GET_SINGLE(GameManager)->AddCoin(GET_SINGLE(UnitManager)->GetUnitCost(unit->GetUnitType()) / 2);
				wall->SetAssignedUnit(nullptr);
				unit->Die();
			}
			else
				return;
		}
	}

}