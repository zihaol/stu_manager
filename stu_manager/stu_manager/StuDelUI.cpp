#include "StuManagerUI.h"
#include "StuDelUI.h"
#include "SQLOper.h"


CStuDelUI::CStuDelUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper)
	: m_pUIDirector(pUIDirector)
	, m_pSqlOper(pSqlOper)
{

}

CStuDelUI::~CStuDelUI()
{

}

void CStuDelUI::show()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "ѧ����ѯ����" <<endl;
	cout << "1:ɾ��" << endl;
	cout << "2:����" << endl;
	cout << "3:�˳�" << endl;
	waitUserCommand("����������:");
	onCommand();
}

void CStuDelUI::onUserDelCmd()
{
	//���ɾ��ѧ������
	char szSearch[128];
	memset(szSearch, 0, sizeof(szSearch));
	sprintf_s(szSearch, sizeof(szSearch), "DELETE FROM stu_info WHERE num = '%d'", getUserSclect());
	if (nullptr != m_pSqlOper)
	{
		m_pSqlOper->ExecSql(szSearch);
	}
	show();
	onCommand();
}

void CStuDelUI::onCommand()
{
	switch (getUserSclect())
	{
	case DEL_CMD_ADD:
		waitUserCommand("������ɾ��ѧ��id");
		onUserDelCmd();
		//onUserSearchCmd();
		//waitUserAddUserCommand();
		//onUserAddUserCmd();
		break;
	case DEL_CMD_RETURN:
		m_pUIDirector->changeToUI(STU_COM_HELP);
		break;
	case DEL_CMD_QUIT:
		break;
	default:
		break;
	}
}
