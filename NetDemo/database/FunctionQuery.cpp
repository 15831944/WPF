#include "stdafx.h"
#include "Function.h"

bool QueryIDCARDAPPLY(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError)
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
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt, NULL) != SQLITE_OK)
		{
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 18)
			{
				lcArray.push_back(tagIDCARDAPPLY());
				tagIDCARDAPPLY &lc	= lcArray.back();

				lc.name				= sqlite3_column_bytes(lpStmt, 0)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 0)))		: "";
				lc.gender			= sqlite3_column_bytes(lpStmt, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 1)))		: "";
				lc.Nation			= sqlite3_column_bytes(lpStmt, 2)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 2)))		: "";
				lc.Birthday			= sqlite3_column_bytes(lpStmt, 3)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 3)))		: "";
				lc.Address			= sqlite3_column_bytes(lpStmt, 4)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 4)))		: "";
				lc.IdNumber			= sqlite3_column_bytes(lpStmt, 5)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 5)))		: "";
				lc.SigDepart		= sqlite3_column_bytes(lpStmt, 6)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 6)))		: "";
				lc.SLH				= sqlite3_column_bytes(lpStmt, 7)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 7)))		: "";
				lc.fpData			= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.fpFeature		= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.XCZP				= sqlite3_column_bytes(lpStmt, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 10)))	: "";
				lc.XZQH				= sqlite3_column_bytes(lpStmt, 11)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 11)))	: "";
				lc.sannerId			= sqlite3_column_bytes(lpStmt, 12)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 12)))	: "";
				lc.scannerName		= sqlite3_column_bytes(lpStmt, 13)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 13)))	: "";
				lc.legal			= sqlite3_column_int(lpStmt, 14) ? true:false;
				lc.operatorID		= sqlite3_column_bytes(lpStmt, 15)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 15)))	: "";
				lc.operatorName		= sqlite3_column_bytes(lpStmt, 16)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 16)))	: "";
				lc.opDate			= sqlite3_column_bytes(lpStmt, 17)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 17)))	: "";

			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
