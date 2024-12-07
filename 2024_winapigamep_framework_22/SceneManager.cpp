#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "MapSelectScene.h"
#include "EventManager.h"
#include "DefenseScene.h"
void SceneManager::Init()
{
	m_pCurrentScene = nullptr;

	// �� ���
	RegisterScene(L"TitleScene",std::make_shared<TitleScene>());
	RegisterScene(L"MapSelectScene",std::make_shared<MapSelectScene>());
	RegisterScene(L"DefenseScene",std::make_shared<DefenseScene>());

	// �� �ε�
	GET_SINGLE(EventManager)->SceneChange(L"TitleScene");
}

void SceneManager::Update()
{
	if (m_pCurrentScene == nullptr)
		return;
	m_pCurrentScene->Update();
	m_pCurrentScene->LateUpdate();
}

void SceneManager::Render(HDC _hdc)
{
	if (m_pCurrentScene == nullptr)
		return;
	m_pCurrentScene->Render(_hdc);
}

void SceneManager::RegisterScene(const wstring& _sceneName, std::shared_ptr<Scene> _scene)
{
	if (_sceneName.empty() || _scene == nullptr)
		return;
	m_mapScenes.insert(m_mapScenes.end(), {_sceneName, _scene});
}

void SceneManager::LoadScene(const wstring& _sceneName)
{
	GET_SINGLE(EventManager)->ClearDeleteObject();
	// ���� ������
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Release();
		m_pCurrentScene = nullptr;
	}

	auto iter = m_mapScenes.find(_sceneName);
	if (iter != m_mapScenes.end())
	{
		m_pCurrentScene = iter->second;
		m_pCurrentScene->Init();
	}
}
