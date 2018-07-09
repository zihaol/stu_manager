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
	cout << "学生管理系统1.0.0" <<endl;
	cout << "1:查询" << endl;
	cout << "2:返回" << endl;
	cout << "3:退出" << endl;
	waitUserCommand("请输入命令:");
	onCommand();
}


