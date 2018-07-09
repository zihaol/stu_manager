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
		//����������
		StuManagerMainUI* pMainUI = new StuManagerMainUI(pStuDirector);
		if (nullptr != pMainUI)
		{
			pStuDirector->addUI(pMainUI, STU_COM_HELP);
		}

		//�������ҽ���
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

	//����ָ��
}

