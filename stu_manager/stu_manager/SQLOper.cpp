#include "SQLOper.h"

CSQLOper::CSQLOper()
	: m_pCurrentRecordSet(NULL)
	, m_pCommand(NULL)
	, m_pConnection(NULL)
{
	//初始化com组件
	::CoInitialize(NULL);
}

CSQLOper::~CSQLOper()
{
	if (m_pCurrentRecordSet != NULL)
	{
		m_pCurrentRecordSet->Close();
	}

	if (m_pConnection != NULL)
	{
		m_pConnection->Close();
	}

	::CoUninitialize();
}

bool CSQLOper::Open(const char* szServerAddress, const char* szDatabase, const char* szUserName, const char* szPassWord, long lOptions)
{
	bool bSuccess = true;
	do 
	{
		//出事化Connection组件
		_ConnectionPtr pConnection;
		m_pConnection = pConnection;
		m_pConnection.CreateInstance("ADODB.Connection");

		char szLinkInfo[128];
		memset(szLinkInfo, 0, sizeof(szLinkInfo));
		sprintf_s(szLinkInfo, sizeof(szLinkInfo),"Provider=SQLOLEDB;Server=%s;Database=%s;uid=%s;pwd=%s;", szServerAddress, szDatabase, szUserName, szPassWord);
		_bstr_t bstrLinkInfo = szLinkInfo;
		m_pConnection->Open(bstrLinkInfo, "", "", lOptions);
		if (nullptr == m_pConnection)
		{
			bSuccess = false;
			break;
		}

	} while (false);
	return bSuccess;
}

bool CSQLOper::IsLinkInitSuccess()
{
	bool bRet = false;
	do 
	{
		if (m_pConnection != NULL)
		{
			bRet = true;
		}
	} while (false);
	return bRet;
}


void CSQLOper::UpdateRecordSet(const char* szSqlCmd, enum CursorTypeEnum CurscorType, enum LockTypeEnum LockType, long lOptions)
{
	do 
	{
		if (!IsLinkInitSuccess())
		{
			break;
		}

		if (NULL != m_pCurrentRecordSet)
		{
			m_pCurrentRecordSet->Close();
		}

		//初始化
		_bstr_t bsrtCommand = szSqlCmd;
		if (NULL == m_pCurrentRecordSet)
		{
			_RecordsetPtr pCurrentRecordSet;
			m_pCurrentRecordSet = pCurrentRecordSet;
			m_pCurrentRecordSet.CreateInstance(_uuidof(Recordset));
		}


		m_pCurrentRecordSet->Open(bsrtCommand, m_pConnection.GetInterfacePtr(), CurscorType, LockType, lOptions);
	} while (false);
};

_variant_t CSQLOper::getData(long lLieNum)
{
	_variant_t nRet = (_variant_t)(_bstr_t)"未查询";
	do 
	{
		if (m_pCurrentRecordSet->EndOfFile || NULL == m_pCurrentRecordSet)
		{
			break;
		}

		nRet = m_pCurrentRecordSet->GetCollect(_variant_t(lLieNum));
	} while (false);
	return nRet;
}

_variant_t CSQLOper::getData(const char* szCollect)
{
	//_variant_t nRet = 0;
	_variant_t nRet = (_variant_t)(_bstr_t)"未查询";
	do 
	{
		if (m_pCurrentRecordSet->EndOfFile || NULL == m_pCurrentRecordSet)
		{
			break;
		}

		nRet = m_pCurrentRecordSet->GetCollect(szCollect);
	} while (false);
	return nRet;
}