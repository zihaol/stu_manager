#pragma once
#include <string>

enum ChangeCmd
{
	CHANGE_CMD_ERROR,
	CHANGE_CMD_ADD,
	CHANGE_CMD_RETURN,
	CHANGE_CMD_QUIT,
	CHANGE_CMD_SUM,
};

class StuManagerUIBase;
class CStuUIDirector;
class CSQLOper;

class CStuChangeUI : public StuManagerUIBase
{
public:
	CStuChangeUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper);
	~CStuChangeUI();
	virtual void show();
	void onCommand();
	void waitUserChangeCommand();
	void onUserSearchCmd();
private:
	CStuUIDirector*			m_pUIDirector;
	CSQLOper*				m_pSqlOper;

	int m_nOperUserID;
	std::string m_strChangeName;
	int	m_nAge;
};
