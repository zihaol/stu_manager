#include "StuManagerUI.h"
#include "StuShowAllUI.h"
#include <iostream>
#include <stdio.h>
#include "SQLOper.h"

using namespace std;

CStuAllUI::CStuAllUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper)
	: m_pUIDirector(pUIDirector)
	, m_nUserSearchCmd(1)
	, m_pSqlOper(pSqlOper)
{

}

CStuAllUI::~CStuAllUI()
{

}

void CStuAllUI::show()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "ѧ����Ϣ��ʾ����" <<endl;
	cout << "1:��ʾ" << endl;
	cout << "2:����" << endl;
	cout << "3:�˳�" << endl;
	waitUserCommand("����������:");
	onCommand();
}

void CStuAllUI::onCommand()
{
	do 
	{
		switch (getUserSclect())
		{
		case SHOWALL_CMD_SHOW:
			showAllStuInfo();
			break;
		case SHOWALL_CMD_RETURN:
			m_pUIDirector->changeToUI(STU_COM_HELP);
			break;
		case SHOWALL_CMD_QUIT:
			break;
		}
	} while (false);
}

void CStuAllUI::showAllStuInfo()
{
	//�����ʾ����
	if (m_pSqlOper != nullptr)
	{
		char szShowAll[128];
		memset(szShowAll, 0, sizeof(szShowAll));
		sprintf_s(szShowAll, sizeof(szShowAll), "select * from stu_info");
		m_pSqlOper->UpdateRecordSet(szShowAll);
		m_pSqlOper->showRecord();
	}
	show();
}

