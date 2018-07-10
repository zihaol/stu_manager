#include "StuManagerUI.h"
#include "StuSearchUI.h"
#include "StuAddUI.h"
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

		//������ӽ���
		CStuAddUI* pAddUI = new CStuAddUI(pStuDirector, pSqlOper);
		if (nullptr != pAddUI)
		{
			pStuDirector->addUI(pAddUI, STU_COM_ADD);
		}

		pStuDirector->changeToUI(STU_COM_HELP);
		delete pStuDirector;
		delete pMainUI;
		delete pSearchUI;
		delete pSqlOper;
		delete pAddUI;
	} while (false);

	//����ָ��
}

