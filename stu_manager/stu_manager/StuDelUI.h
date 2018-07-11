#pragma once
//#include <string>

enum DelCmd
{
	DEL_CMD_ERROR,
	DEL_CMD_ADD,
	DEL_CMD_RETURN,
	DEL_CMD_QUIT,
	DEL_CMD_SUM,
};

class StuManagerUIBase;
class CStuUIDirector;
class CSQLOper;

class CStuDelUI : public StuManagerUIBase
{
public:
	CStuDelUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper);
	~CStuDelUI();
	virtual void show();
	void onCommand();
	void onUserDelCmd();
private:
	CStuUIDirector*			m_pUIDirector;
	CSQLOper*				m_pSqlOper;
};
