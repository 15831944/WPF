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


		std::string     lstrSQL  =  " INSERT INTO "
			T_IDCARDAPPLY 						"("
			T_IDCARDAPPLY_NAME					","
			T_IDCARDAPPLY_GENDER				","
			T_IDCARDAPPLY_NATION				","
			T_IDCARDAPPLY_BIRTHDAY				","
			T_IDCARDAPPLY_ADDRESS				","
			T_IDCARDAPPLY_IDNUMBER				","
			T_IDCARDAPPLY_SIGDEPART				","
			T_IDCARDAPPLY_SLH					","
			T_IDCARDAPPLY_FPDATA				","
			T_IDCARDAPPLY_FPFEATURE				","
			T_IDCARDAPPLY_XCZP					","
			T_IDCARDAPPLY_XZQH					","
			T_IDCARDAPPLY_SANNERID				","
			T_IDCARDAPPLY_SCANNERNAME			","
			T_IDCARDAPPLY_LEGAL					","
			T_IDCARDAPPLY_OPERATORID			","
			T_IDCARDAPPLY_OPERATORNAME			","
			T_IDCARDAPPLY_OPDATE				")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
			;

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

			sqlite3_bind_text(lpStmt	, 1	, station.name.c_str()			, station.name.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 2	, station.gender.c_str()		, station.gender.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 3	, station.Nation.c_str()		, station.Nation.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 4	, station.Birthday.c_str()		, station.Birthday.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 5	, station.Address.c_str()		, station.Address.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 6	, station.IdNumber.c_str()		, station.IdNumber.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 7	, station.SigDepart.c_str()		, station.SigDepart.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 8	, station.SLH.c_str()			, station.SLH.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 9	, station.fpData.c_str()		, station.fpData.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 10, station.fpFeature.c_str()		, station.fpFeature.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 11, station.XCZP.c_str()			, station.XCZP.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 12, station.XZQH.c_str()			, station.XZQH.size()				, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 13, station.sannerId.c_str()		, station.sannerId.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 14, station.scannerName.c_str()	, station.scannerName.size()		, SQLITE_STATIC);
			sqlite3_bind_int(lpStmt		, 15, station.legal);
			sqlite3_bind_text(lpStmt	, 16, station.operatorID.c_str()	, station.operatorID.size()			, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 17, station.operatorName.c_str()	, station.operatorName.size()		, SQLITE_STATIC);
			sqlite3_bind_text(lpStmt	, 18, station.opDate.c_str()		, station.opDate.size()				, SQLITE_STATIC);

			int dd = sqlite3_step(lpStmt);
			if (dd != SQLITE_ROW) {
				char ch[512] ={ 0 };
				sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
				strError = ch;
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