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
	cout << "学生查询功能" <<endl;
	cout << "1:删除" << endl;
	cout << "2:返回" << endl;
	cout << "3:退出" << endl;
	waitUserCommand("请输入命令:");
	onCommand();
}

void CStuDelUI::onUserDelCmd()
{
	//添加删除学生代码
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
		waitUserCommand("请输入删除学生id");
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
