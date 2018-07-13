#pragma once
#include <iostream>
#include <string>
#include "windows.h"

enum CommandID
{
	STU_COM_ERROER = 0,
	STU_COM_HELP,
	STU_COM_ADD,
	STU_COM_DEL,
	STU_COM_SEARCH,
	STU_COM_CHANGE,
	STU_COM_QUIT,
	STU_COM_ALL,
	STU_COM_SUM,
};



class StuManagerUIBase
{
public:
	StuManagerUIBase();
	~StuManagerUIBase();
	virtual void show();
	void waitUserCommand(const char* szTip);
	int getUserSclect();
private:
	int m_nUserSelect;
};

class CStuUIDirector;
class StuManagerMainUI : public StuManagerUIBase
{
public:
	StuManagerMainUI(CStuUIDirector* pDirector);
	~StuManagerMainUI();
	//软件循环
	virtual void show();
	//游戏主界面
	void onCommand();
	//Command处理
	void onComHelp();
	void pauseManager();
private:
	CStuUIDirector* m_pStuUIDirector;
};

class CStuUIDirector
{
public:
	CStuUIDirector();
	~CStuUIDirector(){}
	void addUI(StuManagerUIBase* pStuMagUi, int nIndex);
	void changeToUI(int nIndex);
private:
	StuManagerUIBase* m_pStuMagUI[STU_COM_SUM];
};

