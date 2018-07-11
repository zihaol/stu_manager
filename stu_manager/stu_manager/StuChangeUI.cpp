#include "StuManagerUI.h"
#include "StuChangeUI.h"
#include <iostream>
#include <stdio.h>
#include "SQLOper.h"


CStuChangeUI::CStuChangeUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper)
	: m_pSqlOper(pSqlOper)
	, m_pUIDirector(pUIDirector)
	, m_nOperUserID(0)
	//, m_strChangeName(nullptr)
	, m_nAge(0)
{

}

CStuChangeUI::~CStuChangeUI()
{

}

void CStuChangeUI::show()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "学生查询功能" <<endl;
	cout << "1:修改" << endl;
	cout << "2:返回" << endl;
	cout << "3:退出" << endl;
	waitUserCommand("请输入命令:");
	onCommand();
}

void CStuChangeUI::onUserSearchCmd()
{
	char szChangeCommand[128];
	memset(szChangeCommand, 0, sizeof(szChangeCommand));
	sprintf_s(szChangeCommand, sizeof(szChangeCommand),"UPDATE stu_info SET name = '%s',age = '%d' WHERE num = '%d'", m_strChangeName.c_str(), m_nAge, m_nOperUserID);

	m_pSqlOper->ExecSql(szChangeCommand);
}

void CStuChangeUI::waitUserChangeCommand()
{
	cout << "请输入要修改学生id:" << endl;
	cin >> m_nOperUserID;
	cout << "请输入修改后的名字:" << endl;
	cin >> m_strChangeName;
	cout << "请输入修改后的年龄:" << endl;
	cin >> m_nAge;
}

void CStuChangeUI::onCommand()
{
	do 
	{
		switch (getUserSclect())
		{
		case CHANGE_CMD_ADD:
			//waitUserAddUserCommand();
			//onUserAddUserCmd();
			//waitUserCommand("请输入修改学生的id:");
			waitUserChangeCommand();
			onUserSearchCmd();
			show();
			onCommand();
			break;
		case  CHANGE_CMD_RETURN:
			m_pUIDirector->changeToUI(STU_COM_HELP);
			break;
		case  CHANGE_CMD_QUIT:
			break;
		}
	} while (false);
}
