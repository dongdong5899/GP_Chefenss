#pragma once
#include "Object.h"
class TextPro;
class EnemySpawner;
class Waver :
    public Object
{
public:
    Waver();
    ~Waver();
public:
    void Update() override;
    void Render(HDC _hdc) override;
    void SetWaveDuration(float _duration) { m_waveDuration = _duration; }
private:
    void StartWave();
    wstring GetCurrentWaveEnemyVec() { return m_waveEnemyVec[m_currentWave].second; }
    int GetCurrentWaveSpawnDelay() { return m_waveEnemyVec[m_currentWave].first; }
    void AddSpawner(EnemySpawner* _spawner)
    {
        m_spawners.push_back(_spawner);
    }
    void RemoveSpawner(EnemySpawner* _spawner)
    {
        auto index = std::find(m_spawners.begin(), m_spawners.end(), _spawner);
        if (index != m_spawners.end())
        {
            m_spawners.erase(index);
        }
    }
    bool IsEnd() { return m_currentWave + 1 == m_waveEnemyVec.size(); }
private:
    TextPro* m_waveText;
    TextPro* m_waveDelayText;
    float m_waveEndTime;
    float m_waveDuration;
    int m_currentWave;
    vector<std::pair<int, wstring>> m_waveEnemyVec
    {
        {7, L"P"},
        {5, L"PPP"},
        {2, L"PPPPP"},
        {7, L"PPBP"},
        {5, L"PPPPBPPPPBPPP"},
        {10, L"BBB"},
        {5, L"PBPBPBPB"},
        {5, L"N"},
    };
    vector<EnemySpawner*> m_spawners;
    vector<EnemySpawner*> m_deadSpawners;
};

