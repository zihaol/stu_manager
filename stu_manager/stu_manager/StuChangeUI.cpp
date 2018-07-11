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
	cout << "ѧ����ѯ����" <<endl;
	cout << "1:�޸�" << endl;
	cout << "2:����" << endl;
	cout << "3:�˳�" << endl;
	waitUserCommand("����������:");
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
	cout << "������Ҫ�޸�ѧ��id:" << endl;
	cin >> m_nOperUserID;
	cout << "�������޸ĺ������:" << endl;
	cin >> m_strChangeName;
	cout << "�������޸ĺ������:" << endl;
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
			//waitUserCommand("�������޸�ѧ����id:");
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
