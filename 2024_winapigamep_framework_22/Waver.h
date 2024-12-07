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
        {200, L"P"},
        {50, L"PPP"},
        {50, L"PPPPPPPP"},
        {50, L"PPPPPB"},
        {50, L"PPBPPPPBPP"},//5
        {20, L"PPBPPBPPBPP"},
        {70, L"PBPBPBPBPBPB"},
        {30, L"BBBBBBBB"},
        {50, L"PBPBPBPB"},
        {50, L"N"},//10
        {40, L"PBPNPPBPBPBBPPBB"},
        {10, L"BBBBNBBBB"},
        {50, L"PBPBNPBPBNPBPBN"},
        {30, L"PNBPBBNBBPBNPBBNPBBPBNN"},
        {10, L"NNNNNN"},//15
        {60, L"RBBRBB"},
        {100, L"RNRNRN"},
        {100, L"RRRRRR"},
        {50, L"PBNRPBNRPBNR"},
        {50, L"Q"},//20
        {40, L"PNBRPBBRNBBPBNRPBBNPBRBPBNNR"},
        {10, L"PBNRPBNRPBNRPBNRPBNRPBNR"},
        {50, L"QQ"},
        {10, L"PPPBBBNNNRRRQQQ"},
        {50, L"QQQQQ"},//25
    };
    vector<EnemySpawner*> m_spawners;
    vector<EnemySpawner*> m_deadSpawners;
};

