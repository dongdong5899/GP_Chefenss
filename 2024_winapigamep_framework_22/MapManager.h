#pragma once

class Object;
class Tile;
class Road;
class MapManager
{
	DECLARE_SINGLE(MapManager);
public:
	void Init();
	void Update();
public:
	void SetMapSize(MAP_SIZE _mapSize);
	void SetMapOffset(Vec2 _offset) { m_offset = _offset; }
	Vec2 GetMapOffset() { return m_offset; }
	vector<Object*> CreateTiles();
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
		},
		{
			L"°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·",
			L"S°‡°‡°‡°‡°‡T2°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡T2°‡°‡°‡°‡T2°‡°‡°‡°‡°‡T°·",
			L"°·°·°·°·°·°·3°·°·°·°·°·°·°·°·°·°·°·°·°·3°·°·°·°·°·3°·°·°·°·°·°·3°·",
			L"°·°·°·T°‡0T2°‡°‡°‡°‡°‡T°·°·°·°·°·°·°‡°·°·°·°·°·°‡°·°·°·°·°·°·°‡°·",
			L"°·°·°·3°·°·°·°·°·°·°·°·°·3°·°·°·°·°·°·°‡°·T°‡°‡0T20T°‡°‡0T°·",
			L"°·°·°·°‡°·°·°·°·T°‡°‡°‡0T°·°·T°‡°‡0T°·3°·°·°·°·°·°·3°·°·°·°·°·",
			L"°·°·°·°‡°·°·°·°·3°·°·°·°·°·°·°·3°·°·°·°·°·°‡°·°·°·°·°·°·°‡°·°·°·°·°·",
			L"°·°·°·T2T°‡0T°·°·°·°·T°‡0T2°‡°‡°‡0T2°‡°‡°‡°‡°‡T2T2T°·",
			L"°·°·°·°·°·3°·°·°·°·°·°·°·3°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·3°·3°·",
			L"°·°·T°‡0T2T2°‡°‡°‡°‡T°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·T2T°·",
			L"°·°·3°·°·°·°·3°·°·°·°·°·3°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·3°·",
			L"°·°·°‡°·°·°·°·T2°‡°‡°‡°‡T2°‡°‡°‡°‡°‡°‡°‡T°·°·°·°·°·°·°·°·°·°·°‡°·",
			L"°·°·°‡°·°·°·°·°·°·°·°·°·°·3°·°·°·°·°·°·°·°·3°·°·°·°·°·°·°·°·°·°·°‡°·",
			L"°·°·T2°‡°‡°‡T°·°·°·°·°·T2°‡°‡°‡°‡°‡°‡°‡T2°‡°‡T°‡°‡°‡°‡°‡0T°·",
			L"°·°·3°·°·°·°·3°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·3°·°·°·°·°·°·°·°·",
			L"°·°·T2°‡°‡°‡T2°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡°‡T2°‡T°·°·°·°·°·",
			L"°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·3°·°·°·°·°·",
			L"°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·°·E°·°·°·°·°·",
		}
	};
	Vec2 m_offset;
};

