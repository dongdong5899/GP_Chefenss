#include "pch.h"
#include "ButtonUI.h"
#include "Button.h"

ButtonUI::ButtonUI()
{
	//체크하고싶은애한테 이거 달아주면 됨
	AddComponent<Button>();
	//GetComponent를 UI만든곳에서 해서 하면 ButtonUI마다 다른 이벤트 실행 가능
	Button* button = GetComponent<Button>();
	//캐스트 사이즈 (물론 밖에서 다시 설정가능)
}

ButtonUI::~ButtonUI()
{
	//-=가 안됨;; 쩔수없음
	GetComponent<Button>()->onClick.Clear();
}

void ButtonUI::OnClick()
{
	cout << "Click" << endl;
}
