#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Object.h"
void EventManager::Update()
{
	// 이전 프레임에서 등록해둔 
	for (Object* obj : m_vecDead)
	{
		if (obj != nullptr)
		{
			delete obj;
		}
	}
	m_vecDead.clear();

	if (m_changeScene != L"")
	{
		GET_SINGLE(SceneManager)->LoadScene(m_changeScene);
		m_changeScene = L"";
	}

	for (auto& eve : m_vecEvent)
		Excute(eve);
	m_vecEvent.clear();
}

void EventManager::DeleteObject(Object* _pObj)
{
	tEvent eve = {};
	eve.eveType = EVENT_TYPE::DELETE_OBJECT;
	eve.obj = _pObj;

	if (std::find(m_vecEvent.begin(), m_vecEvent.end(), eve) == m_vecEvent.end())
	{
		m_vecEvent.push_back(eve);
	}
}

void EventManager::SceneChange(wstring _sceneName)
{
	tEvent eve = {};
	eve.eveType = EVENT_TYPE::SCENE_CHANGE;
	eve.name = _sceneName;

	if (std::find(m_vecEvent.begin(), m_vecEvent.end(), eve) == m_vecEvent.end())
	{
		m_vecEvent.push_back(eve);
	}
}

void EventManager::Excute(const tEvent& _eve)
{
	switch (_eve.eveType)
	{
	case EVENT_TYPE::DELETE_OBJECT:
	{
		Object* pDeadObj = _eve.obj;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
	break;
	case EVENT_TYPE::CREATE_OBJECT:
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		m_changeScene = _eve.name;
		break;
	}
}
