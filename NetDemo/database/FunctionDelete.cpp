#include "stdafx.h"
#include "Function.h"

bool ExcuteSql(char* sqlStr, string &strError)
{
	bool bOk	= true;
	strError	= "";

	g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_WRITE);
	do
	{
		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}

		sqlite3_stmt   *lpStmt0		=  NULL;
		const char* beginSQL = "BEGIN TRANSACTION";
		if (sqlite3_prepare_v2(lpSQlite->Handle(), beginSQL, -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			if (lpStmt0) sqlite3_finalize(lpStmt0);
			bOk = false; char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			bOk = false;
			break;
		}

		if (sqlite3_step(lpStmt0) != SQLITE_DONE) {
			if (lpStmt0) sqlite3_finalize(lpStmt0);
			bOk = false; char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}
		if (lpStmt0) sqlite3_finalize(lpStmt0);

		std::string	lstrSQL	= sqlStr;

		sqlite3_stmt   *lpStmt1		=  NULL;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt1, NULL) != SQLITE_OK)
		{
			if (lpStmt1) sqlite3_finalize(lpStmt1);
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}
		int dd = sqlite3_step(lpStmt1);
		if (dd != SQLITE_ROW) {
			if (lpStmt1) sqlite3_finalize(lpStmt1);
			bOk = false; char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}
		if (lpStmt1) sqlite3_finalize(lpStmt1);

		sqlite3_stmt   *lpStmt2			=  NULL;
		const char*		commitSQL		= "COMMIT";
		if (sqlite3_prepare_v2(lpSQlite->Handle(), commitSQL, strlen(commitSQL), &lpStmt2, NULL) != SQLITE_OK) {
			if (lpStmt2) sqlite3_finalize(lpStmt2);
			bOk = false; char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		if (sqlite3_step(lpStmt2) != SQLITE_DONE) {
			if (lpStmt2) sqlite3_finalize(lpStmt2);
			bOk = false; char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}
		sqlite3_finalize(lpStmt2);


		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	g_ReadWriteLock.unlock();

	return bOk;
}
