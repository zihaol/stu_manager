#include "StuManagerUI.h"
#include "StuSearchUI.h"
#include <iostream>
#include <stdio.h>
#include "SQLOper.h"

using namespace std;

CStuSearchUI::CStuSearchUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper)
	: m_pUIDirector(pUIDirector)
	, m_nUserSearchCmd(1)
	, m_pSqlOper(pSqlOper)
{

}

CStuSearchUI::~CStuSearchUI()
{

}

int CStuSearchUI::getUserSearchCmd()
{
	return m_nUserSearchCmd;
}


void CStuSearchUI::waitUserSearchCmd(const char* szTip)
{
	cout << szTip << endl;
	cin >> m_nUserSearchCmd;
}

void CStuSearchUI::onUserSearchCmd()
{
	//��Ӳ�ѯ����
	if (m_pSqlOper != NULL)
	{
		char szSearch[128];
		memset(szSearch, 0, sizeof(szSearch));
		sprintf_s(szSearch, sizeof(szSearch), "select * from stu_info where num = '%d'", getUserSearchCmd());
		m_pSqlOper->UpdateRecordSet(szSearch);

		//������
		//cout << (char*)(_bstr_t)m_pSqlOper->getData("name") << endl;
		m_pSqlOper->showRecord();
		show();
		onCommand();
	}
}

void CStuSearchUI::setSqlOper(CSQLOper* pSqlOper)
{
	m_pSqlOper = pSqlOper;
}

void CStuSearchUI::onCommand()
{
	do 
	{
		switch (getUserSclect())
		{
		case SEARCH_CMD_SEARCH:
			waitUserSearchCmd("���������id");
			onUserSearchCmd();
			break;
		case SEARCH_CMD_RETURN:
			m_pUIDirector->changeToUI(STU_COM_HELP);
			break;
		case SEARCH_CMD_QUIT:
			break;
		}
	} while (false);
}

void CStuSearchUI::show()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "ѧ����ѯ����" <<endl;
	cout << "1:��ѯ" << endl;
	cout << "2:����" << endl;
	cout << "3:�˳�" << endl;
	waitUserCommand("����������:");
	onCommand();
}


