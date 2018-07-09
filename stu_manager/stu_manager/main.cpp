#include "StuManagerUI.h"
#include "StuSearchUI.h"

void main()
{
	do 
	{
		CStuUIDirector* pStuDirector = new CStuUIDirector();
		if (nullptr == pStuDirector)
		{
			break;
		}
		//创建主界面
		StuManagerMainUI* pMainUI = new StuManagerMainUI(pStuDirector);
		if (nullptr != pMainUI)
		{
			pStuDirector->addUI(pMainUI, STU_COM_HELP);
		}

		//创建查找界面
		CStuSearchUI* pSearchUI = new CStuSearchUI(pStuDirector);
		if (nullptr != pSearchUI)
		{
			pStuDirector->addUI(pSearchUI, STU_COM_SEARCH);
		}

		pStuDirector->changeToUI(STU_COM_HELP);
		delete pStuDirector;
		delete pMainUI;
		delete pSearchUI;
	} while (false);

	//销毁指针
}

