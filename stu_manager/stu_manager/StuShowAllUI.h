#pragma once

enum ShowAllCmd
{
	SHOWALL_CMD_ERROR,
	SHOWALL_CMD_SHOW,
	SHOWALL_CMD_RETURN,
	SHOWALL_CMD_QUIT,
	SHOWALL_CMD_SUM,
};


class StuManagerUIBase;
class CStuUIDirector;
class CSQLOper;


class CStuAllUI : public StuManagerUIBase
{
public:
	CStuAllUI(CStuUIDirector* pUIDirector, CSQLOper* pSqlOper);
	~CStuAllUI();
	virtual void show();
	void onCommand();
	void showAllStuInfo();

private:
	CStuUIDirector*			m_pUIDirector;
	int						m_nUserSearchCmd;
	CSQLOper*				m_pSqlOper;
};