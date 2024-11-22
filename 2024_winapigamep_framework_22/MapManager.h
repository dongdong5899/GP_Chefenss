#pragma once

class Object;
class MapManager
{
	DECLARE_SINGLE(MapManager);
public:
	void Init();
	void Update();
public:
	void SetMapMode(MAP_SIZE _mapSize);
	vector<wstring> GetMapStrData() { return m_currentMapStrVec; }
	vector<vector<Object*>> GetMapTileData() { return m_currentMapTileVec; }
	void SetMapTileData(vector<vector<Object*>> _tileData) { m_currentMapTileVec = _tileData; }
	int GetTileSize();
	Vec2 MapToPos(Vec2 _mapPos);
private:
	MAP_SIZE m_mapSize;
	vector<wstring> m_currentMapStrVec;
	vector<vector<Object*>> m_currentMapTileVec;
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

