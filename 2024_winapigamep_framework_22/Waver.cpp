#include "pch.h"
#include "Waver.h"
#include "TextPro.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "Scene.h"
#include "EnemySpawner.h"
#include "MapManager.h"
#include <cmath>

Waver::Waver()
	: m_waveText(nullptr)
	, m_waveDelayText(nullptr)
	, m_waveEndTime(0)
	, m_waveDuration(0)
	, m_currentWave(-1)
{
	m_waveEndTime = GET_SINGLE(TimeManager)->GetTime();
	cout << GET_SINGLE(TimeManager)->GetTime() << endl;

	Vec2 mapOffset = GET_SINGLE(MapManager)->GetMapOffset();
	m_waveText = new TextPro();
	m_waveText->SetText(L"Wave : " + std::to_wstring(m_currentWave + 1));
	m_waveText->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x, 110 + mapOffset.y });
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(m_waveText, LAYER::UI);
	m_waveDelayText = new TextPro();
	m_waveDelayText->SetText(L"다음 웨이브까지 : " + std::to_wstring(m_waveDuration));
	m_waveDelayText->SetPos({ SCREEN_WIDTH / 2 + mapOffset.x, 130 + mapOffset.y });
	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(m_waveDelayText, LAYER::UI);
}

Waver::~Waver()
{
}

void Waver::Update()
{
	float time = GET_SINGLE(TimeManager)->GetTime();
	int remain = (float)round((m_waveEndTime + m_waveDuration - time));
	if (remain < 0) remain = 0;
	m_waveDelayText->SetText(L"다음 웨이브까지 : " + std::to_wstring(remain));
	if (remain == 0)
	{
		cout << GET_SINGLE(TimeManager)->GetTime() << endl;
		m_waveEndTime = time;
		m_waveText->SetText(L"Wave : " + std::to_wstring(++m_currentWave + 1));
		StartWave();
	}

	for (EnemySpawner* spawner : m_spawners)
	{
		if (spawner->IsEnd())
		{
			m_deadSpawners.push_back(spawner);
		}
		else
		{
			spawner->Update();
		}
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
	vector<UNIT_TYPE> enemyVec = GetCurrentWaveEnemyVec();
	spawner->SetEnemySpawnVec(enemyVec);
	int spawnDelay = GetCurrentWaveSpawnDelay();
	spawner->SetEnemySpawnDelay(spawnDelay);
	AddSpawner(spawner);
}