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
			L"S01กเ0กแกแกแกแ",
			L"กแ1กแกแ1กแกแ0E",
			L"กแกเกแกแกเกแกแ1กแ",
			L"กแ01กเ01กเ0กแ",
			L"กแกแกแกแกแกแกแกแกแ",
		},
		{
			L"กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ",
			L"Sกเ01กเกเกเกเกเ0กแกแกแกแกแ",
			L"กแกแ1กแกแกแกแกแกแ1กแกแกแกแกแ",
			L"กแกแ01กเกเกเกเ101กเกเ0กแ",
			L"กแกแ1กแกแกแกแกแกแกแกแกแกแ1กแ",
			L"กแกแกเกแกแกแกแกแ0กเกเกเ10กแ",
			L"กแกแ01กเกเกเกเ0กแกแกแกแกแกแ",
			L"กแกแกแกแกแกแกแกแEกแกแกแกแกแกแ",
		}
	};
};

