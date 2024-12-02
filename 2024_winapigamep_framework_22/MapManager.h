#pragma once

class Tile;
class Road;
class MapManager
{
	DECLARE_SINGLE(MapManager);
public:
	void Init();
	void Update();
public:
	void SetMapMode(MAP_SIZE _mapSize);
	vector<wstring> GetMapStrData() { return m_currentMapStrVec; }
	vector<vector<Tile*>> GetMapTileData() { return m_currentMapTileVec; }
	void SetMapTileData(vector<vector<Tile*>> _tileData) { m_currentMapTileVec = _tileData; }
	int GetTileSize();
	Vec2 PosToMapPos(Vec2 _mapPos);
public:
	void SetStartRoad(Road* _startRoad) { m_startTile = _startRoad; }
	Road* GetStartRoad() { return m_startTile; }
private:
	Road* m_startTile;
	MAP_SIZE m_mapSize;
	vector<wstring> m_currentMapStrVec;
	vector<vector<Tile*>> m_currentMapTileVec;
	vector<vector<wstring>> m_mapStrVec =
	{
		{
			L"°·°·°·°·°·°·°·°·°·",
			L"ST2°‡T°·°·°·°·",
			L"°·3°·°·3°·°·TE",
			L"°·°‡°·°·°‡°·°·1°·",
			L"°·T2°‡T2°‡T°·",
			L"°·°·°·°·°·°·°·°·°·",
		},
		{
			L"°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·",
			L"S°‡T2°‡°‡°‡°‡°‡T°·°·°·°·°·",
			L"°·°·3°·°·°·°·°·°·3°·°·°·°·°·",
			L"°·°·T2°‡°‡°‡°‡0T2°‡°‡T°·",
			L"°·°·3°·°·°·°·°·°·°·°·°·°·3°·",
			L"°·°·°‡°·°·°·°·°·T°‡°‡°‡0T°·",
			L"°·°·°‡°·°·°·°·°·3°·°·°·°·°·°·",
			L"°·°·T2°‡°‡°‡°‡T°·°·°·°·°·°·",
			L"°·°·°·°·°·°·°·°·E°·°·°·°·°·°·",
		}
	};
};

