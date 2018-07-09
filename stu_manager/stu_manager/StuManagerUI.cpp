#include "StuManagerUI.h"

using namespace std;

CStuUIDirector::CStuUIDirector()
{
	memset(m_pStuMagUI, 0, sizeof(m_pStuMagUI));
}
void CStuUIDirector::addUI(StuManagerUIBase* pStuMagUi, int nIndex)
{
	do 
	{
		if (nIndex <= STU_COM_ERROER || nIndex >= STU_COM_SUM)
		{
			break;
		}

		if (nullptr != m_pStuMagUI[nIndex])
		{
			delete m_pStuMagUI[nIndex];
			m_pStuMagUI[nIndex] = nullptr;
		}

		m_pStuMagUI[nIndex] = pStuMagUi;

	} while (false);
}

void CStuUIDirector::changeToUI(int nIndex)
{
	do 
	{
		if (nIndex <= STU_COM_ERROER || nIndex >= STU_COM_SUM)
		{
			break;
		}

		if (nullptr == m_pStuMagUI[nIndex])
		{
			break;
		}

		m_pStuMagUI[nIndex]->show();
	} while (false);
}

StuManagerUIBase::StuManagerUIBase()
	: m_nUserSelect(STU_COM_ERROER)
{

}

StuManagerUIBase::~StuManagerUIBase()
{

}

void StuManagerUIBase::show()
{

}

void StuManagerUIBase::waitUserCommand(const char* szTip)
{
	cout << szTip << endl;
	cin >> m_nUserSelect;
}

int StuManagerUIBase::getUserSclect()
{
	return m_nUserSelect;
}


StuManagerMainUI::StuManagerMainUI(CStuUIDirector* pDirector)
	: m_pStuUIDirector(pDirector)
{

}

StuManagerMainUI::~StuManagerMainUI()
{

}

//软件循环
void StuManagerMainUI::show()
{
	onComHelp();
}

void StuManagerMainUI::pauseManager()
{
	system("pause");
}
void StuManagerMainUI::onComHelp()
{
	cout << "-------------------------------------------------------------"<<endl;
	cout << "学生管理系统1.0.0" <<endl;
	cout << "1:帮助" << endl;
	cout << "2:增加学生信息" << endl;
	cout << "3:删除学生信息" << endl;
	cout << "4:查找学生信息" << endl;
	cout << "5:更改学生信息" << endl;
	cout << "6:退出" << endl;
	waitUserCommand("请输入命令:");
	onCommand();
}

void StuManagerMainUI::onCommand()
{
	switch (getUserSclect())
	{
	case STU_COM_HELP:
	case STU_COM_SEARCH:
		//onComHelp();
		if (m_pStuUIDirector != NULL)
		{
			m_pStuUIDirector->changeToUI(getUserSclect());
		}
		break;
	case STU_COM_QUIT:
		break;
	case STU_COM_ERROER:
		cout << "Error Command" << endl;
		pauseManager();
		break;
	default:
		cout << "Don't have this command" << endl;
		pauseManager();
		break;
	}
}

