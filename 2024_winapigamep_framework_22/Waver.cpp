#include "pch.h"
#include "Waver.h"
#include "TextPro.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "Scene.h"
#include "EnemySpawner.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "Image.h"
#include "Button.h"

Waver::Waver()
	: m_waveText(nullptr)
	, m_waveDelayText(nullptr)
	, m_waveEndTime(0)
	, m_waveDuration(0)
	, m_currentWave(-1)
{
	Vec2 mapOffset = GET_SINGLE(MapManager)->GetMapOffset();
	m_waveText = new TextPro();
	m_waveText->SetText(L"Wave : " + std::to_wstring(m_currentWave + 1));
	m_waveText->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x, 100 + mapOffset.y });
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(m_waveText, LAYER::UI);
	m_waveDelayText = new TextPro();
	m_waveDelayText->SetText(L"���� ���̺���� : " + std::to_wstring(m_waveDuration));
	m_waveDelayText->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x, 120 + mapOffset.y });
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(m_waveDelayText, LAYER::UI);



	Image* stageSkipBtn = new Image();
	stageSkipBtn->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x + 180, SCREEN_HEIGHT / 2 + mapOffset.y - 230 });
	stageSkipBtn->SetSize({ 150, 35 });
	Texture* skipTexture = GET_SINGLE(ResourceManager)->
		TextureLoad(L"StageSkipBtn", L"Texture\\Unit_Card_Area.bmp");
	stageSkipBtn->SetImage(skipTexture, 0.6f);
	Button* button = new Button;
	button->onClick += [this]() { m_waveEndTime = 0; };
	stageSkipBtn->AddComponent(button);
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(stageSkipBtn, LAYER::UI);

	Vec2 skipTextPos = stageSkipBtn->GetPos();
	skipTextPos.y -= 9;
	TextPro* skipText = new TextPro;
	skipText->SetPos(skipTextPos);
	skipText->SetText(L"���� ���̺� ����");
	skipText->SetFontSize(15.f);
	skipText->SetColor(RGB(255, 0, 0));
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(skipText, LAYER::UI);
}

Waver::~Waver()
{
}

void Waver::Update()
{
	float time = GET_SINGLE(TimeManager)->GetTime();
	int remain = (float)round((m_waveEndTime + m_waveDuration - time));
	if (remain < 0) remain = 0;
	m_waveDelayText->SetText(L"���� ���̺���� : " + std::to_wstring(remain));
	if (!IsEnd())
	{
		if (remain == 0)
		{
			m_waveEndTime = time;
			m_waveText->SetText(L"Wave : " + std::to_wstring(++m_currentWave + 1));
			StartWave();
		}
	}
	else
	{
		/*if (GET_SINGLE(SceneManager)->GetCurrentScene()->GetObjectCount(LAYER::ENEMY) == 0) {
			GET_SINGLE(EventManager)->SceneChange(L"ClearScene");
		}*/
	}

	for (EnemySpawner* spawner : m_spawners)
	{
		if (spawner->IsEnd())
			m_deadSpawners.push_back(spawner);
		else
			spawner->Update();
	}
	for (EnemySpawner* deadSpawner : m_deadSpawners)
	{
		RemoveSpawner(deadSpawner);
		delete deadSpawner;
	}
	m_deadSpawners.clear();
}

void Waver::Render(HDC _hdc)
{
}

void Waver::StartWave()
{
	EnemySpawner* spawner = new EnemySpawner();
	wstring enemyDataStr = GetCurrentWaveEnemyVec();
	spawner->SetEnemySpawnVec(enemyDataStr);
	int spawnDelay = GetCurrentWaveSpawnDelay();
	spawner->SetEnemySpawnDelay(spawnDelay);
	AddSpawner(spawner);
}