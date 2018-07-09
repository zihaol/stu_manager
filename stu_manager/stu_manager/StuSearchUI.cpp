#include "StuManagerUI.h"
#include "StuSearchUI.h"
#include <iostream>

using namespace std;

CStuSearchUI::CStuSearchUI(CStuUIDirector* pUIDirector)
	: m_pUIDirector(pUIDirector)
{

}

CStuSearchUI::~CStuSearchUI()
{

}

void CStuSearchUI::onCommand()
{
	do 
	{
		switch (getUserSclect())
		{
		case SEARCH_CMD_SEARCH:
			break;
		case SEARCH_CMD_RETURN:
			m_pUIDirector->changeToUI(STU_COM_HELP);
			break;
		}
	} while (false);
}

void CStuSearchUI::show()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "ѧ������ϵͳ1.0.0" <<endl;
	cout << "1:��ѯ" << endl;
	cout << "2:����" << endl;
	cout << "3:�˳�" << endl;
	waitUserCommand("����������:");
	onCommand();
}


