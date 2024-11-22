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

