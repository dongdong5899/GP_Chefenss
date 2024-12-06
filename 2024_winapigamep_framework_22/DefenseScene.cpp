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
#include "ButtonUI.h"
#include "Button.h"

DefenseScene::DefenseScene()
	: m_lastUpdateTime(0)
	, m_UpdateDuration(0.01f)
	, m_backgroundTexture(nullptr)
	, m_backgroundScale(5.f)
	, m_goldText(nullptr)
	, m_costText{ nullptr }
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

	SetUI();

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
	SetShotcut();
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
	Vec2 mapOffset = GET_SINGLE(MapManager)->GetMapOffset();

	//buttonArea
	{
		ButtonUI* buttonArea = new ButtonUI();
		buttonArea->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x , SCREEN_HEIGHT / 2 + 320 + mapOffset.y });
		buttonArea->SetSize({ 0, 0 });
		buttonArea->SetScale(3.f);
		buttonArea->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"ButtonArea", L"Texture\\Unit_Card_Area.bmp"));
		AddObject(buttonArea, LAYER::UI);
	}

	//Pawn
	{
		ButtonUI* button_backGround = new ButtonUI();
		button_backGround->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x - 300, SCREEN_HEIGHT / 2 + 300 + mapOffset.y });
		button_backGround->SetSize({ 100, 100 });
		button_backGround->SetScale(3.f);
		button_backGround->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp"));
		AddObject(button_backGround, LAYER::UI);
		Button* buttonCompo = button_backGround->GetComponent<Button>();
		buttonCompo->onClick += [this]() {SetUnitType(UNIT_TYPE::PAWN); };

		ButtonUI* button_unit = new ButtonUI();
		Vec2 backgroundPos = button_backGround->GetPos();
		button_unit->SetPos({ backgroundPos.x,backgroundPos.y - 10 });
		button_unit->SetSize({ 0,0 });
		button_unit->SetScale(2.f);
		button_unit->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Pawn", L"Texture\\PlayerPawn.bmp"));
		AddObject(button_unit, LAYER::UI);

		m_costText[0] = new TextPro;
		m_costText[0]->SetPos({ backgroundPos.x,backgroundPos.y + 15 });
		m_costText[0]->SetText(L"100G");
		m_costText[0]->SetColor(RGB(255, 0, 0));
		AddObject(m_costText[0], LAYER::UI);

		TextPro* atkText = new TextPro();
		atkText->SetPos({backgroundPos.x,backgroundPos.y+55});
		atkText->SetColor(RGB(255, 255, 255));
		atkText->SetText(L"ATK : 1");
		AddObject(atkText, LAYER::UI);

		TextPro* atkspeedText = new TextPro();
		atkspeedText->SetPos({ backgroundPos.x,backgroundPos.y + 75 });
		atkspeedText->SetColor(RGB(255, 255, 255));
		atkspeedText->SetText(L"ATKCOOL : 50");
		AddObject(atkspeedText, LAYER::UI);
	}
	//Knight
	{
		ButtonUI* button_backGround = new ButtonUI();
		button_backGround->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x - 150, SCREEN_HEIGHT / 2 + 300 + mapOffset.y });
		button_backGround->SetSize({ 100, 100 });
		button_backGround->SetScale(3.f);
		button_backGround->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp"));
		AddObject(button_backGround, LAYER::UI);
		Button* buttonCompo = button_backGround->GetComponent<Button>();
		buttonCompo->onClick += [this]() {SetUnitType(UNIT_TYPE::KNIGHT); };

		ButtonUI* button_unit = new ButtonUI();
		Vec2 backgroundPos = button_backGround->GetPos();
		button_unit->SetPos({ backgroundPos.x,backgroundPos.y - 10 });
		button_unit->SetSize({ 0,0 });
		button_unit->SetScale(2.f);
		button_unit->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Knight", L"Texture\\PlayerKnight.bmp"));
		AddObject(button_unit, LAYER::UI);

		m_costText[1] = new TextPro;
		m_costText[1]->SetPos({ backgroundPos.x,backgroundPos.y + 15 });
		m_costText[1]->SetText(L"300");
		m_costText[1]->SetColor(RGB(255, 0, 0));
		AddObject(m_costText[1], LAYER::UI);

		TextPro* atkText = new TextPro();
		atkText->SetPos({ backgroundPos.x,backgroundPos.y + 55 });
		atkText->SetColor(RGB(255, 255, 255));
		atkText->SetText(L"ATK : 3");
		AddObject(atkText, LAYER::UI);

		TextPro* atkspeedText = new TextPro();
		atkspeedText->SetPos({ backgroundPos.x,backgroundPos.y + 75 });
		atkspeedText->SetColor(RGB(255, 255, 255));
		atkspeedText->SetText(L"ATKCOOL : 40");
		AddObject(atkspeedText, LAYER::UI);
	}
	//Bishop
	{
		ButtonUI* button_backGround = new ButtonUI();
		button_backGround->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x , SCREEN_HEIGHT / 2 + 300 + mapOffset.y });
		button_backGround->SetSize({ 100, 100 });
		button_backGround->SetScale(3.f);
		button_backGround->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp"));
		AddObject(button_backGround, LAYER::UI);
		Button* buttonCompo = button_backGround->GetComponent<Button>();
		buttonCompo->onClick += [this]() {SetUnitType(UNIT_TYPE::BISHOP); };

		ButtonUI* button_unit = new ButtonUI();
		Vec2 backgroundPos = button_backGround->GetPos();
		button_unit->SetPos({ backgroundPos.x,backgroundPos.y - 10 });
		button_unit->SetSize({ 0,0 });
		button_unit->SetScale(2.f);
		button_unit->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Bishop", L"Texture\\PlayerBishop.bmp"));
		AddObject(button_unit, LAYER::UI);

		m_costText[2] = new TextPro;
		m_costText[2]->SetPos({ backgroundPos.x,backgroundPos.y + 15 });
		m_costText[2]->SetText(L"500");
		m_costText[2]->SetColor(RGB(255, 0, 0));
		AddObject(m_costText[2], LAYER::UI);

		TextPro* atkText = new TextPro();
		atkText->SetPos({ backgroundPos.x,backgroundPos.y + 55 });
		atkText->SetColor(RGB(255, 255, 255));
		atkText->SetText(L"ATK : 3");
		AddObject(atkText, LAYER::UI);

		TextPro* atkspeedText = new TextPro();
		atkspeedText->SetPos({ backgroundPos.x,backgroundPos.y + 75 });
		atkspeedText->SetColor(RGB(255, 255, 255));
		atkspeedText->SetText(L"ATKCOOL : 30");
		AddObject(atkspeedText, LAYER::UI);


	}
	//Rook
	{
		ButtonUI* button_backGround = new ButtonUI();
		button_backGround->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x + 150, SCREEN_HEIGHT / 2 + 300 + mapOffset.y });
		button_backGround->SetSize({ 100, 100 });
		button_backGround->SetScale(3.f);
		button_backGround->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp"));
		AddObject(button_backGround, LAYER::UI);
		Button* buttonCompo = button_backGround->GetComponent<Button>();
		buttonCompo->onClick += [this]() {SetUnitType(UNIT_TYPE::ROOK); };

		ButtonUI* button_unit = new ButtonUI();
		Vec2 backgroundPos = button_backGround->GetPos();
		button_unit->SetPos({ backgroundPos.x,backgroundPos.y - 10 });
		button_unit->SetSize({ 0,0 });
		button_unit->SetScale(2.f);
		button_unit->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Rook", L"Texture\\PlayerRook.bmp"));
		AddObject(button_unit, LAYER::UI);

		m_costText[3] = new TextPro;
		m_costText[3]->SetPos({ backgroundPos.x,backgroundPos.y + 15 });
		m_costText[3]->SetText(L"2000");
		m_costText[3]->SetColor(RGB(255, 0, 0));
		AddObject(m_costText[3], LAYER::UI);

		TextPro* atkText = new TextPro();
		atkText->SetPos({ backgroundPos.x,backgroundPos.y + 55 });
		atkText->SetColor(RGB(255, 255, 255));
		atkText->SetText(L"ATK : 5");
		AddObject(atkText, LAYER::UI);

		TextPro* atkspeedText = new TextPro();
		atkspeedText->SetPos({ backgroundPos.x,backgroundPos.y + 75 });
		atkspeedText->SetColor(RGB(255, 255, 255));
		atkspeedText->SetText(L"ATKCOOL : 20");
		AddObject(atkspeedText, LAYER::UI);
	}
	//Queen
	{
		ButtonUI* button_backGround = new ButtonUI();
		button_backGround->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x + 300, SCREEN_HEIGHT / 2 + 300 + mapOffset.y });
		button_backGround->SetSize({ 100, 100 });
		button_backGround->SetScale(3.f);
		button_backGround->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp"));
		AddObject(button_backGround, LAYER::UI);
		ButtonUI* button_unit = new ButtonUI();
		Vec2 backgroundPos = button_backGround->GetPos();
		button_unit->SetPos({ backgroundPos.x,backgroundPos.y - 10 });
		button_unit->SetSize({ 0,0 });
		button_unit->SetScale(2.f);
		button_unit->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"Queen", L"Texture\\PlayerQueen.bmp"));
		AddObject(button_unit, LAYER::UI);

		m_costText[4] = new TextPro;
		m_costText[4]->SetPos({ backgroundPos.x,backgroundPos.y + 15 });
		m_costText[4]->SetText(L"5000");
		m_costText[4]->SetColor(RGB(255, 0, 0));
		AddObject(m_costText[4], LAYER::UI);

		Button* buttonCompo = button_backGround->GetComponent<Button>();
		buttonCompo->onClick += [this]() {SetUnitType(UNIT_TYPE::QUEEN); };

		TextPro* atkText = new TextPro();
		atkText->SetPos({ backgroundPos.x,backgroundPos.y + 55 });
		atkText->SetColor(RGB(255, 255, 255));
		atkText->SetText(L"ATK : 10");
		AddObject(atkText, LAYER::UI);

		TextPro* atkspeedText = new TextPro();
		atkspeedText->SetPos({ backgroundPos.x,backgroundPos.y + 75 });
		atkspeedText->SetColor(RGB(255, 255, 255));
		atkspeedText->SetText(L"ATKCOOL : 20");
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

void DefenseScene::SetShotcut()
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
				unit->SetAttackRoadColor(BRUSH_TYPE::WHITE, 0);
				GET_SINGLE(EventManager)->DeleteObject(unit);
			}
			else
				return;
		}
	}

}

void DefenseScene::SetCostTextColor(int index, COLORREF color)
{
	m_costText[index]->SetColor(color);
}
