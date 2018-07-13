#include "SQLOper.h"
#include <stdio.h>

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

void CSQLOper::searchStuInfo(int nID)
{
	do 
	{
		if (!IsLinkInitSuccess())
		{
			break;
		}

		if (nullptr == m_pCommand)
		{
			m_pCommand.CreateInstance(__uuidof(Command));
			m_pCommand->ActiveConnection = m_pConnection;
		}

		if (nullptr == m_pCommand)
		{
			break;
		}

		try
		{
			m_pCommand->CommandType = adCmdStoredProc;
			m_pCommand->CommandText = _bstr_t("searchStuIfno");
			_ParameterPtr parID;
			parID.CreateInstance(__uuidof(Parameter));
			parID = m_pCommand->CreateParameter(_bstr_t("nID"), DataTypeEnum::adInteger, adParamInput, sizeof(int));
			parID->Value = _variant_t(nID);
			m_pCommand->Parameters->Append(parID);


			//_ParameterPtr parOutName;
			//parOutName.CreateInstance(__uuidof(Parameter));
			//parOutName = m_pCommand->CreateParameter(_bstr_t("szName"), DataTypeEnum::adInteger, adParamOutput, 30);
			////parOutName->Value = _variant_t(nID);
			//m_pCommand->Parameters->Append(parOutName);

			m_pCurrentRecordSet = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);

		}
		catch(_com_error e)
		{
			char szError[128];
			memset(szError, 0, sizeof(szError));
			sprintf_s(szError,sizeof(szError),"%s",e.ErrorInfo());
			int a = 0;
		}
	}while(false);
}

void CSQLOper::delStuInfo(int nID)
{
	do 
	{
		if (!IsLinkInitSuccess())
		{
			break;
		}

		if (nullptr == m_pCommand)
		{
			m_pCommand.CreateInstance(__uuidof(Command));
			m_pCommand->ActiveConnection = m_pConnection;
		}

		if (nullptr == m_pCommand)
		{
			break;
		}

		try
		{
			//_bstr_t storproc("updateStuInfo");
			m_pCommand->CommandType = adCmdStoredProc;
			m_pCommand->CommandText = _bstr_t("delStuInfo");
			_ParameterPtr parID;
			parID.CreateInstance(__uuidof(Parameter));
			parID = m_pCommand->CreateParameter(_bstr_t("nID"), DataTypeEnum::adInteger, adParamInput, sizeof(int));
			parID->Value = _variant_t(nID);
			m_pCommand->Parameters->Append(parID);


			m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
		}
		catch(_com_error e)
		{
			char szError[128];
			memset(szError, 0, sizeof(szError));
			sprintf_s(szError,sizeof(szError),"%s",e.ErrorInfo());
			int a = 0;
		}
	}while(false);
}
void CSQLOper::addStuInfo(int nID, const char* szName, int nAge)
{
	do 
	{
		if (!IsLinkInitSuccess())
		{
			break;
		}

		if (nullptr == m_pCommand)
		{
			m_pCommand.CreateInstance(__uuidof(Command));
			m_pCommand->ActiveConnection = m_pConnection;
		}

		if (nullptr == m_pCommand)
		{
			break;
		}

		try
		{
			//_bstr_t storproc("updateStuInfo");
			m_pCommand->CommandType = adCmdStoredProc;
			m_pCommand->CommandText = _bstr_t("addStuInfo");
			_ParameterPtr parID;
			parID.CreateInstance(__uuidof(Parameter));
			parID = m_pCommand->CreateParameter(_bstr_t("nID"), DataTypeEnum::adInteger, adParamInput, sizeof(int));
			parID->Value = _variant_t(nID);
			m_pCommand->Parameters->Append(parID);


			_ParameterPtr parName;
			parName.CreateInstance(__uuidof(Parameter));
			parName = m_pCommand->CreateParameter(_bstr_t("strName"), DataTypeEnum::adVarWChar, adParamInput, 30);
			parName->Value = _variant_t(szName);
			m_pCommand->Parameters->Append(parName);

			_ParameterPtr parAge;
			parAge.CreateInstance(__uuidof(Parameter));
			parAge = m_pCommand->CreateParameter(_bstr_t("nAge"), DataTypeEnum::adInteger, adParamInput, sizeof(int));
			parAge->Value = _variant_t(nAge);
			m_pCommand->Parameters->Append(parAge);

			m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
		}
		catch(_com_error e)
		{
			char szError[128];
			memset(szError, 0, sizeof(szError));
			sprintf_s(szError,sizeof(szError),"%s",e.ErrorInfo());
			int a = 0;
		}
	}while(false);
}

void CSQLOper::updateStuInfo(int nID, const char* szName, int nAge)
{
	do 
	{
		if (!IsLinkInitSuccess())
		{
			break;
		}

		if (nullptr == m_pCommand)
		{
			m_pCommand.CreateInstance(__uuidof(Command));
			m_pCommand->ActiveConnection = m_pConnection;
		}

		if (nullptr == m_pCommand)
		{
			break;
		}

		try
		{
			//_bstr_t storproc("updateStuInfo");
			m_pCommand->CommandType = adCmdStoredProc;
			m_pCommand->CommandText = _bstr_t("updateStuInfo");
			//m_pCommand->CommandText = storproc;
			
			//m_pCommand->Parameters->Refresh();

			//m_pCommand->Parameters->Item[_variant_t(_bstr_t("@nID"))]->Value = _variant_t(nID);

			//m_pCommand->Parameters->Item[_variant_t(_bstr_t("@strName"))]->Value = _variant_t("wsde");
			//m_pCommand->Parameters->Item[_variant_t(_bstr_t("@nAge"))]->Value = _variant_t(nAge);
			_ParameterPtr parID;
			parID.CreateInstance(__uuidof(Parameter));
			parID = m_pCommand->CreateParameter(_bstr_t("nID"), DataTypeEnum::adInteger, adParamInput, sizeof(int));
			parID->Value = _variant_t(nID);
			m_pCommand->Parameters->Append(parID);


			_ParameterPtr parName;
			parName.CreateInstance(__uuidof(Parameter));
			parName = m_pCommand->CreateParameter(_bstr_t("strName"), DataTypeEnum::adVarWChar, adParamInput, 30);
			parName->Value = _variant_t(szName);
			m_pCommand->Parameters->Append(parName);

			_ParameterPtr parAge;
			parAge.CreateInstance(__uuidof(Parameter));
			parAge = m_pCommand->CreateParameter(_bstr_t("nAge"), DataTypeEnum::adInteger, adParamInput, sizeof(int));
			parAge->Value = _variant_t(nAge);
			m_pCommand->Parameters->Append(parAge);

			m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
		}
		catch(_com_error e)
		{
			char szError[128];
			memset(szError, 0, sizeof(szError));
			sprintf_s(szError,sizeof(szError),"%s",e.ErrorInfo());
			int a = 0;
		}


	} while (false);
}

void CSQLOper::ExecSql(const char* szSqlCmd, long lOptions)
{
	do 
	{
		if (!IsLinkInitSuccess())
		{
			break;
		}

		if (nullptr == m_pCommand)
		{
			m_pCommand.CreateInstance(__uuidof(Command));
			m_pCommand->ActiveConnection = m_pConnection;
		}
		m_pCommand->CommandText = (_bstr_t)szSqlCmd;
		m_pCommand->Execute(NULL, NULL,adCmdText); 
	} while (false);
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

void CSQLOper::showRecord()
{
	while (!m_pCurrentRecordSet->EndOfFile)
	{
		printf("%d, %s, %d\n", (int)getData("num"), (char*)(_bstr_t)getData("name"), (int)getData("age"));
		m_pCurrentRecordSet->MoveNext();
	}
}

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