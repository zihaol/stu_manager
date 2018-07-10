#pragma once
#include <string>

enum AddCmd
{
	ADD_CMD_ERROR,
	ADD_CMD_ADD,
	ADD_CMD_RETURN,
	ADD_CMD_QUIT,
	ADD_CMD_SUM,
};

class StuManagerUIBase;
class CStuUIDirector;
class CSQLOper;
class CStuAddUI : public StuManagerUIBase
{
public:
	CStuAddUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper);
	~CStuAddUI();
	virtual void show();
	void onCommand();
	void waitUserAddUserCommand();
	void onUserAddUserCmd();
private:
	CStuUIDirector*			m_pUIDirector;
	int						m_nUserSearchCmd;
	CSQLOper*				m_pSqlOper;
	//添加玩家信息
	std::string					m_strAddUserName;
	int						m_nID;
	int						m_nAge;
	bool					m_bBoy;
};

