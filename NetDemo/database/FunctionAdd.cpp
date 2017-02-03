#include "stdafx.h"
#include "Function.h"

bool AddIDCARDAPPLY(tagIDCARDAPPLY  station, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			OutputDebugStringA(strError.c_str());
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt   =  NULL;
		std::string     lstrSQL  =  "INSERT INTO " T_IDCARDAPPLY " VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt, NULL) != SQLITE_OK)
		{
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		int insertCount = 1;
		const char* strData = "This is a test.";
		//7. 基于已有的SQL语句，迭代的绑定不同的变量数据
		for (int i = 0; i < insertCount; ++i) {
			//在绑定时，最左面的变量索引值是1。

			sqlite3_bind_text(lpStmt	, 0	, station.name.c_str()			, station.name.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 1	, station.gender.c_str()		, station.gender.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 2	, station.Nation.c_str()		, station.Nation.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 3	, station.Birthday.c_str()		, station.Birthday.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 4	, station.Address.c_str()		, station.Address.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 5	, station.IdNumber.c_str()		, station.IdNumber.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 6	, station.SigDepart.c_str()		, station.SigDepart.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 7	, station.SLH.c_str()			, station.SLH.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 8	, station.fpData.c_str()		, station.fpData.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 9	, station.fpFeature.c_str()		, station.fpFeature.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 10, station.XCZP.c_str()			, station.XCZP.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 11, station.XZQH.c_str()			, station.XZQH.size()				, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 12, station.sannerId.c_str()		, station.sannerId.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 13, station.scannerName.c_str()	, station.scannerName.size()		, SQLITE_TRANSIENT);
			sqlite3_bind_int(lpStmt		, 14, station.legal);
			sqlite3_bind_text(lpStmt	, 15, station.operatorID.c_str()	, station.operatorID.size()			, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 16, station.operatorName.c_str()	, station.operatorName.size()		, SQLITE_TRANSIENT);
			sqlite3_bind_text(lpStmt	, 17, station.opDate.c_str()		, station.opDate.size()				, SQLITE_TRANSIENT);

			if (sqlite3_step(lpStmt) != SQLITE_DONE) {
				strError = "插入数据库表" T_IDCARDAPPLY "失败";
				OutputDebugStringA(strError.c_str());
				break;
			}
			//重新初始化该sqlite3_stmt对象绑定的变量。
			sqlite3_reset(lpStmt);
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}