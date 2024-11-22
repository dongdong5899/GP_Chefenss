#pragma once
class MapManager
{
	DECLARE_SINGLE(MapManager);
public:
	void Init();
	void Update();
public:
	void SetMapSize(MAP_SIZE _mapSize);
	vector<wstring> GetMap() { return m_currentMapStrVec; }
	int GetTileSize();
private:
	MAP_SIZE m_mapSize;
	vector<wstring> m_currentMapStrVec;
	vector<vector<wstring>> m_mapStrVec =
	{
		{
			L"����������",
			L"����������",
			L"����������",
			L"����������",
			L"����������",
			L"����������",
		},
		{
			L"����������������",
			L"����������������",
			L"����������������",
			L"����������������",
			L"����������������",
			L"����������������",
			L"����������������",
			L"����������������",
		}
	};
};

