#pragma once

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
class CStuSearchUI : public StuManagerUIBase
{
public:
	CStuSearchUI(CStuUIDirector* pUIDirector);
	~CStuSearchUI();
	virtual void show();
	void onCommand();
private:
	CStuUIDirector* m_pUIDirector;
};

