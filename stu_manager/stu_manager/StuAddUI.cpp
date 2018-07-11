#include "StuManagerUI.h"
#include "StuAddUI.h"
#include <iostream>
#include <stdio.h>
#include "SQLOper.h"

using namespace std;

CStuAddUI::CStuAddUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper)
	: m_pUIDirector(pUIDirector)
	, m_pSqlOper(pSqlOper)
{

}

CStuAddUI::~CStuAddUI()
{

}

void CStuAddUI::show()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "学生查询功能" <<endl;
	cout << "1:添加" << endl;
	cout << "2:返回" << endl;
	cout << "3:退出" << endl;
	waitUserCommand("请输入命令:");
	onCommand();
}

void CStuAddUI::onUserAddUserCmd()
{
	//添加增加玩家代码
	char szSearch[128];
	memset(szSearch, 0, sizeof(szSearch));
	sprintf_s(szSearch, sizeof(szSearch), "INSERT INTO stu_info VALUES ('%d','%s','%d');", m_nID, m_strAddUserName.c_str(), m_nAge);
	if (nullptr != m_pSqlOper)
	{
		m_pSqlOper->ExecSql(szSearch);
	}
	show();
	onCommand();
}

void CStuAddUI::waitUserAddUserCommand()
{
	cout << "请输入玩家id" << endl;
	cin >> m_nID;
	cout << "请输入玩家name" << endl;
	cin >> m_strAddUserName;
	cout << "请输入玩家age" << endl;
	cin >> m_nAge;
	cout << "请输入玩家性别(0女1男)" << endl;
	int nSex;
	cin >> nSex;
	if (0 == nSex)
	{
		m_bBoy = false;
	}
	else
	{
		m_bBoy = true;
	}
}

void CStuAddUI::onCommand()
{
	do 
	{
		switch (getUserSclect())
		{
		case ADD_CMD_ADD:
			//waitUserSearchCmd("请输入玩家id");
			//onUserSearchCmd();
			waitUserAddUserCommand();
			onUserAddUserCmd();
			break;
		case ADD_CMD_RETURN:
			m_pUIDirector->changeToUI(STU_COM_HELP);
			break;
		case ADD_CMD_QUIT:
			break;
		}
	} while (false);
}

