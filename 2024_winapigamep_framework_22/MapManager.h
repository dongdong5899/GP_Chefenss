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
			L"กแกแกแกแกแกแกแกแกแ",
			L"ST2กเTกแกแกแกแ",
			L"กแ3กแกแ3กแกแTE",
			L"กแกเกแกแกเกแกแ1กแ",
			L"กแT2กเT2กเTกแ",
			L"กแกแกแกแกแกแกแกแกแ",
		},
		{
			L"กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ",
			L"SกเT2กเกเกเกเกเTกแกแกแกแกแ",
			L"กแกแ3กแกแกแกแกแกแ3กแกแกแกแกแ",
			L"กแกแT2กเกเกเกเ0T2กเกเTกแ",
			L"กแกแ3กแกแกแกแกแกแกแกแกแกแ3กแ",
			L"กแกแกเกแกแกแกแกแTกเกเกเ0Tกแ",
			L"กแกแกเกแกแกแกแกแ3กแกแกแกแกแกแ",
			L"กแกแT2กเกเกเกเTกแกแกแกแกแกแ",
			L"กแกแกแกแกแกแกแกแEกแกแกแกแกแกแ",
		},
		{
			L"กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ",
			L"SกเกเกเกเกเT2กเกเกเกเกเกเกเกเกเกเกเกเT2กเกเกเกเT2กเกเกเกเกเTกแ",
			L"กแกแกแกแกแกแ3กแกแกแกแกแกแกแกแกแกแกแกแกแ3กแกแกแกแกแ3กแกแกแกแกแกแ3กแ",
			L"กแกแกแTกเ0T2กเกเกเกเกเTกแกแกแกแกแกแกเกแกแกแกแกแกเกแกแกแกแกแกแกเกแ",
			L"กแกแกแ3กแกแกแกแกแกแกแกแกแ3กแกแกแกแกแกแกเกแTกเกเ0T20Tกเกเ0Tกแ",
			L"กแกแกแกเกแกแกแกแTกเกเกเ0TกแกแTกเกเ0Tกแ3กแกแกแกแกแกแ3กแกแกแกแกแ",
			L"กแกแกแกเกแกแกแกแ3กแกแกแกแกแกแกแ3กแกแกแกแกแกเกแกแกแกแกแกแกเกแกแกแกแกแ",
			L"กแกแกแT2Tกเ0TกแกแกแกแTกเ0T2กเกเกเ0T2กเกเกเกเกเT2T2Tกแ",
			L"กแกแกแกแกแ3กแกแกแกแกแกแกแ3กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ3กแ3กแ",
			L"กแกแTกเ0T2T2กเกเกเกเTกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแT2Tกแ",
			L"กแกแ3กแกแกแกแ3กแกแกแกแกแ3กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ3กแ",
			L"กแกแกเกแกแกแกแT2กเกเกเกเT2กเกเกเกเกเกเกเTกแกแกแกแกแกแกแกแกแกแกเกแ",
			L"กแกแกเกแกแกแกแกแกแกแกแกแกแ3กแกแกแกแกแกแกแกแ3กแกแกแกแกแกแกแกแกแกแกเกแ",
			L"กแกแT2กเกเกเTกแกแกแกแกแT2กเกเกเกเกเกเกเT2กเกเTกเกเกเกเกเ0Tกแ",
			L"กแกแ3กแกแกแกแ3กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ3กแกแกแกแกแกแกแกแ",
			L"กแกแT2กเกเกเT2กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเT2กเTกแกแกแกแกแ",
			L"กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ3กแกแกแกแกแ",
			L"กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแEกแกแกแกแกแ",
		}
	};
	Vec2 m_offset;
};

