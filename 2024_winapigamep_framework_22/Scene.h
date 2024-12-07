#pragma once
class Texture;
class Object;
class Scene
{
public:
	Scene();
	virtual ~Scene(); // ���� �Ҹ���
public:
	virtual void Init() abstract;
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _hdc);
	virtual void Release();
public:
	void AddObject(Object* _obj, LAYER _type)
	{
		m_vecObj[(UINT)_type].push_back(_obj);
	}
	const vector<Object*>& GetLayerObjects(LAYER _type)
	{
		return m_vecObj[(UINT)_type];
	}
public:
	void SetBackgroundTexture(Texture* _texture) { m_backgroundTexture = _texture; }
	Texture* GetBackgroundTexture() { return m_backgroundTexture; }
	void SetBackgroundScale(float _scale) { m_backgroundScale = _scale; }
	float GetBackgroundScale() { return m_backgroundScale; }
	int GetObjectCount(LAYER _layer) { return m_vecObj[(int)_layer].size(); }
private:
	//Object m_obj;
	//Object* m_pObj;
	Texture* m_backgroundTexture;
	float m_backgroundScale;
	vector<Object*> m_vecObj[(UINT)LAYER::END];
};

