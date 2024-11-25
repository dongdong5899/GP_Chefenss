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
			L"°·°·°·°·°·°·°·°·°·",
			L"S°‡°‡°‡°‡°·°·°·°·",
			L"°·°‡°·°·°‡°·°·°‡E",
			L"°·°‡°·°·°‡°·°·°‡°·",
			L"°·°‡°‡°‡°‡°‡°‡°‡°·",
			L"°·°·°·°·°·°·°·°·°·",
		},
		{
			L"°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·",
			L"S°‡°‡°‡°‡°‡°‡°‡°‡°‡°·°·°·°·°·",
			L"°·°·°‡°·°·°·°·°·°·°‡°·°·°·°·°·",
			L"°·°·°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°·",
			L"°·°·°‡°·°·°·°·°·°·°·°·°·°·°‡°·",
			L"°·°·°‡°·°·°·°·°·°‡°‡°‡°‡°‡°‡°·",
			L"°·°·°‡°‡°‡°‡°‡°‡°‡°·°·°·°·°·°·",
			L"°·°·°·°·°·°·°·°·E°·°·°·°·°·°·",
		}
	};
};

