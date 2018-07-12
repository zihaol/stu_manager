#include <iostream>
#include "SQLOper.h"
using namespace std;

int main()
{
	CSQLOper* pSqlOper = new CSQLOper;
	pSqlOper->Open("(Local)", "MY_DB", "sa", "123456");

	//²éÑ¯Óï¾ä
	//pSqlOper->UpdateRecordSet("select * from stu_info where num = '5'");
	//cout << (char*)(_bstr_t)pSqlOper->getData("name") << endl;

	//pSqlOper->UpdateRecordSet("select * from stu_info where num = '4'");
	//cout << (char*)(_bstr_t)pSqlOper->getData("name") << endl;

	pSqlOper->updateStuInfo(3, "abc", 11);
	delete pSqlOper;
	return 1;
}

