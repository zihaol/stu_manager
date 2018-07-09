#include "StuManagerUI.h"
#include "StuSearchUI.h"
#include "SQLOper.h"

void main()
{
	do 
	{
		CStuUIDirector* pStuDirector = new CStuUIDirector();
		if (nullptr == pStuDirector)
		{
			break;
		}
		CSQLOper* pSqlOper = new CSQLOper;
		pSqlOper->Open("(Local)", "MY_DB", "sa", "123456");
		//����������
		StuManagerMainUI* pMainUI = new StuManagerMainUI(pStuDirector);
		if (nullptr != pMainUI)
		{
			pStuDirector->addUI(pMainUI, STU_COM_HELP);
		}

		//�������ҽ���
		CStuSearchUI* pSearchUI = new CStuSearchUI(pStuDirector, pSqlOper);
		if (nullptr != pSearchUI)
		{
			pStuDirector->addUI(pSearchUI, STU_COM_SEARCH);
		}

		pStuDirector->changeToUI(STU_COM_HELP);
		delete pStuDirector;
		delete pMainUI;
		delete pSearchUI;
		delete pSqlOper;
	} while (false);

	//����ָ��
}

