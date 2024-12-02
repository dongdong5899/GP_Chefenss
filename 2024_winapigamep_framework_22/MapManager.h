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
		}
	};
};

