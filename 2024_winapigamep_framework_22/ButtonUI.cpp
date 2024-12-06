#include "pch.h"
#include "ButtonUI.h"
#include "Button.h"

ButtonUI::ButtonUI()
{
	//üũ�ϰ���������� �̰� �޾��ָ� ��
	AddComponent<Button>();
	//GetComponent�� UI��������� �ؼ� �ϸ� ButtonUI���� �ٸ� �̺�Ʈ ���� ����
	Button* button = GetComponent<Button>();
	//ĳ��Ʈ ������ (���� �ۿ��� �ٽ� ��������)
}

ButtonUI::~ButtonUI()
{
	//-=�� �ȵ�;; ¿������
	GetComponent<Button>()->onClick.Clear();
}

void ButtonUI::OnClick()
{
	cout << "Click" << endl;
}
