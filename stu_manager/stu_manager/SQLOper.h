#pragma once

//#include <iostream>
#include "windows.h"

using namespace std;

#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF","EndOfFile")


class CSQLOper
{
public:
	CSQLOper();
	~CSQLOper();
	bool Open(const char* szServerAddress, const char* szDatabase, const char* szUserName, const char* szPassWord, long lOptions = adModeUnknown);
	bool IsLinkInitSuccess();
	//sql语句实现增删查改
	void UpdateRecordSet(const char* szSqlCmd, enum CursorTypeEnum CurscorType = adOpenDynamic, enum LockTypeEnum LockType = adLockOptimistic, long lOptions = adCmdText);
	_variant_t getData(long lLieNum);
	_variant_t getData(const char* szCollect);
	void ExecSql(const char* szSqlCmd, long lOptions = adCmdText);
	//存储过程实现
	void updateStuInfo(int nID, const char* szName, int nAge);
	void addStuInfo(int nID, const char* szName, int nAge);
	void delStuInfo(int nID);
	void searchStuInfo(int nID);
private:
	_ConnectionPtr				m_pConnection;
	_CommandPtr					m_pCommand;
	_RecordsetPtr				m_pCurrentRecordSet;
};

