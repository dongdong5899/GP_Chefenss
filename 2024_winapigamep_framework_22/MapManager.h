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
			L"¡á¡á¡á¡á¡á¡á¡á¡á¡á",
			L"¡à¡à¡à¡à¡à¡á¡á¡á¡á",
			L"¡á¡à¡á¡á¡à¡á¡á¡à¡à",
			L"¡á¡à¡á¡á¡à¡á¡á¡à¡á",
			L"¡á¡à¡à¡à¡à¡à¡à¡à¡á",
			L"¡á¡á¡á¡á¡á¡á¡á¡á¡á",
		},
		{
			L"¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á",
			L"¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á",
			L"¡á¡á¡à¡á¡á¡á¡á¡á¡á¡à¡á¡á¡á¡á¡á",
			L"¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á",
			L"¡á¡á¡à¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡à¡á",
			L"¡á¡á¡à¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡á",
			L"¡á¡á¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á",
			L"¡á¡á¡á¡á¡á¡á¡á¡á¡à¡á¡á¡á¡á¡á¡á",
		}
	};
};

