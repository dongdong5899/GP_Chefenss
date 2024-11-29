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

