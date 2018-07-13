#pragma once

//#include <string>
enum SearchCmd
{
	SEARCH_CMD_ERROR,
	SEARCH_CMD_SEARCH,
	SEARCH_CMD_RETURN,
	SEARCH_CMD_QUIT,
	SEARCH_CMD_SUM,
};

class StuManagerUIBase;
class CStuUIDirector;
class CSQLOper;
class CStuSearchUI : public StuManagerUIBase
{
public:
	CStuSearchUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper);
	~CStuSearchUI();
	virtual void show();
	void onCommand();
	int getUserSearchCmd();

	//²éÑ¯½Ó¿Ú
	void waitUserSearchCmd(const char* szTip);
	void onUserSearchCmd();
	void setSqlOper(CSQLOper* pSqlOper);
private:
	CStuUIDirector*			m_pUIDirector;
	int						m_nUserSearchCmd;
	CSQLOper*				m_pSqlOper;
};

