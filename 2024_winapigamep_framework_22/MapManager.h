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
			L"กแกแกแกแกแกแกแกแกแ",
			L"กเกเกเกเกเกแกแกแกแ",
			L"กแกเกแกแกเกแกแกเกเ",
			L"กแกเกแกแกเกแกแกเกแ",
			L"กแกเกเกเกเกเกเกเกแ",
			L"กแกแกแกแกแกแกแกแกแ",
		},
		{
			L"กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ",
			L"กเกเกเกเกเกเกเกเกเกเกแกแกแกแกแ",
			L"กแกแกเกแกแกแกแกแกแกเกแกแกแกแกแ",
			L"กแกแกเกเกเกเกเกเกเกเกเกเกเกเกแ",
			L"กแกแกเกแกแกแกแกแกแกแกแกแกแกเกแ",
			L"กแกแกเกแกแกแกแกแกเกเกเกเกเกเกแ",
			L"กแกแกเกเกเกเกเกเกเกแกแกแกแกแกแ",
			L"กแกแกแกแกแกแกแกแกเกแกแกแกแกแกแ",
		}
	};
};

