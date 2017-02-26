#include "stdafx.h"
#include "Function.h"

bool QueryTable(string QuerySql, string &dataStr, string &strError)
{
	bool bOk	= true;
	strError	= "";
	dataStr	= "";
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

		char** pResult;
		int nRow;
		int nCol;
		if (sqlite3_get_table(lpSQlite->Handle(), QuerySql.c_str(), &pResult, &nRow, &nCol, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", QuerySql.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		int nIndex = nCol;
		for (int i=0; i<nRow; i++)
		{
			for (int j=0; j<nCol; j++)
			{
				dataStr	+= UTF8toASCII(pResult[j]);
				dataStr	+= ":";
				dataStr	+= UTF8toASCII(pResult[nIndex]);
				dataStr	+= ",";

				++nIndex;
			}
			dataStr += ";";
		}
		sqlite3_free_table(pResult);  //使用完后务必释放为记录分配的内存，否则会内存泄漏
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 16)
			{
				lcArray.push_back(tagZHIQIANSHUJU());
				tagZHIQIANSHUJU &lc	= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt, 3);
				lc.IP						= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu				= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi		= sqlite3_column_int(lpStmt, 6);
				lc.Riqi						= sqlite3_column_int64(lpStmt, 7);
				lc.Yewubianhao				= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.YuanZhengjianhaoma		= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Xingming					= sqlite3_column_bytes(lpStmt, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 10)))	: "";
				lc.Qianzhuzhonglei			= sqlite3_column_int(lpStmt, 11);
				lc.ZhikaZhuangtai			= sqlite3_column_int(lpStmt, 12);
				lc.Zhengjianhaoma			= sqlite3_column_bytes(lpStmt, 13)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 13)))	: "";
				lc.Jiekoufanhuijieguo		= sqlite3_column_bytes(lpStmt, 14)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 14)))	: "";
				lc.Lianxidianhua			= sqlite3_column_bytes(lpStmt, 15)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 15)))	: "";
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 13)
			{
				lcArray.push_back(tagSHOUZHENGSHUJU());
				tagSHOUZHENGSHUJU &lc	= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt, 1)	;
				lc.Jubianhao					= sqlite3_column_int(lpStmt, 2)	;
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt, 3)	;
				lc.IP							= sqlite3_column_int(lpStmt, 4)	;
				lc.Bendiyewu					= sqlite3_column_int(lpStmt, 5)	?  true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt, 6)	;
				lc.Riqi							= sqlite3_column_int64(lpStmt, 7);
				lc.Zhengjianleixing				= sqlite3_column_int(lpStmt, 8)	;
				lc.Zhengjianhaoma				= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Xingming						= sqlite3_column_bytes(lpStmt, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 10)))		: "";
				lc.Shoulibianhao				= sqlite3_column_bytes(lpStmt, 11)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 11)))		: "";
				lc.Shifoujiaofei				= sqlite3_column_int(lpStmt, 12)	?  true:false;
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 15)
			{
				lcArray.push_back(tagQIANZHUSHUJU());
				tagQIANZHUSHUJU &lc			= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt, 3);
				lc.IP						= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu				= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi		= sqlite3_column_int(lpStmt, 6);
				lc.Riqi						= sqlite3_column_int64(lpStmt, 7);
				lc.YuanZhengjianhaoma		= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.Xingming					= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Xingbie					= sqlite3_column_int(lpStmt, 10);
				lc.Chushengriqi				= sqlite3_column_int64(lpStmt, 11);
				lc.Lianxidianhua			= sqlite3_column_bytes(lpStmt, 12)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 12)))	: "";
				lc.Yewuleixing				= sqlite3_column_int(lpStmt, 13);
				lc.Shouliren				= sqlite3_column_bytes(lpStmt, 14)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 14)))	: "";
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 13)
			{
				lcArray.push_back(tagJIAOKUANSHUJU());
				tagJIAOKUANSHUJU &lc		= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt, 3);
				lc.IP							= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt, 7);
				lc.Zhishoudanweidaima			= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.Jiaokuantongzhishuhaoma		= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Jiaokuanrenxingming			= sqlite3_column_bytes(lpStmt, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 10)))	: "";
				lc.Yingkoukuanheji				= sqlite3_column_double(lpStmt, 11);
				lc.Jiaoyiriqi					= sqlite3_column_int64(lpStmt, 12);
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 12)
			{
				lcArray.push_back(tagCHAXUNSHUJU());
				tagCHAXUNSHUJU &lc				= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt, 3);
				lc.IP							= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt, 7);
				lc.Chaxunhaoma					= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.Chaxunleixing				= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Shifouchaxunchenggong		= sqlite3_column_int(lpStmt, 10)	? true:false;
				lc.Chuangjianshijian			= sqlite3_column_int64(lpStmt, 11);
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError)
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
			bOk = false;
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
				lcArray.push_back(tagYUSHOULISHUJU());
				tagYUSHOULISHUJU &lc	= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt, 3);
				lc.IP						= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu				= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi		= sqlite3_column_int(lpStmt, 6); 
				lc.Riqi						= sqlite3_column_int64(lpStmt, 7);
				lc.Yewubianhao				= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.Xingming					= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Lianxidianhua			= sqlite3_column_bytes(lpStmt, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 10)))	: "";
				lc.Chuguoshiyou				= sqlite3_column_bytes(lpStmt, 11)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 11)))	: "";
				lc.YuanZhengjianhaoma		= sqlite3_column_bytes(lpStmt, 12)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 12)))	: "";
				lc.Qianzhuzhonglei			= sqlite3_column_int(lpStmt, 13);
				lc.Xingbie					= sqlite3_column_int(lpStmt, 14);
				lc.Hukousuozaidi			= sqlite3_column_bytes(lpStmt, 15)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 15)))	: "";
				lc.Minzu					= sqlite3_column_bytes(lpStmt, 16)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 16)))	: "";
				lc.Chuangjianshijian		= sqlite3_column_int64(lpStmt, 17);
			}	   
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QuerySHEBEIZHUANGTAI(string QuerySql, std::vector<tagSHEBEIZHUANGTAI> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 9)
			{
				lcArray.push_back(tagSHEBEIZHUANGTAI());
				tagSHEBEIZHUANGTAI &lc	= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt, 3);
				lc.IP							= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt, 7);
				lc.Shifouzaixian				= sqlite3_column_bytes(lpStmt, 8) ? true:false;
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}

bool QuerySHEBEIYICHANGSHUJU(string QuerySql, std::vector<tagSHEBEIYICHANGSHUJU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 11)
			{
				lcArray.push_back(tagSHEBEIYICHANGSHUJU());
				tagSHEBEIYICHANGSHUJU &lc	= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt, 3);
				lc.IP							= sqlite3_column_int(lpStmt, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt, 7);
				lc.Yichangshejimokuai			= sqlite3_column_bytes(lpStmt, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 8)))		: "";
				lc.Yichangyuanyin				= sqlite3_column_bytes(lpStmt, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 9)))		: "";
				lc.Yichangxiangxineirong		= sqlite3_column_bytes(lpStmt, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 10)))	: "";
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryGUANLIYUAN(string QuerySql, std::vector<tagGUANLIYUAN> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 6)
			{
				lcArray.push_back(tagGUANLIYUAN());
				tagGUANLIYUAN &lc		= lcArray.back();

				lc.Xuhao				= sqlite3_column_int(lpStmt, 0);
				lc.Yonghuming			= sqlite3_column_bytes(lpStmt, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 1)))		: "";
				lc.Mima					= sqlite3_column_bytes(lpStmt, 2)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 2)))		: "";
				lc.Youxiaoqikaishi		= sqlite3_column_int(lpStmt, 3);
				lc.Youxiaoqijieshu		= sqlite3_column_int(lpStmt, 4);
				lc.Quanxianjibie		= sqlite3_column_int(lpStmt, 5) ? true:false;
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryGUANLIYUANCAOZUOJILU(string QuerySql, std::vector<tagGUANLIYUANCAOZUOJILU> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 5)
			{
				lcArray.push_back(tagGUANLIYUANCAOZUOJILU());
				tagGUANLIYUANCAOZUOJILU &lc		= lcArray.back();

				lc.Xuhao				= sqlite3_column_int(lpStmt, 0);
				lc.Yonghuming			= sqlite3_column_bytes(lpStmt, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 1)))		: "";
				lc.Riqi					= sqlite3_column_int64(lpStmt, 2);
				lc.Caozuoleibie			= sqlite3_column_bytes(lpStmt, 3)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 3)))		: "";
				lc.Caozuoneirong		= sqlite3_column_bytes(lpStmt, 4)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 4)))		: "";
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QuerySHEBEIGUANLI(string QuerySql, std::vector<tagSHEBEIGUANLI> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 11)
			{
				lcArray.push_back(tagSHEBEIGUANLI());
				tagSHEBEIGUANLI &lc		= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt, 3);
				lc.IP						= sqlite3_column_int(lpStmt, 4);
				lc.Shebeichangjia			= sqlite3_column_bytes(lpStmt, 5)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 5)))		: "";;
				lc.Shebeimingcheng			= sqlite3_column_bytes(lpStmt, 6)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 6)))		: "";;
				lc.Shebeileixing			= sqlite3_column_bytes(lpStmt, 7)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 7)))		: "";;
				lc.Jingdu					= sqlite3_column_double(lpStmt, 8);
				lc.Weidu					= sqlite3_column_double(lpStmt, 9);
				lc.Chuangjianshijian		= sqlite3_column_int64(lpStmt, 10);
			}
		}	

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}
bool QueryYINGSHEBIAO(string QuerySql, std::vector<tagYINGSHEBIAO> &lcArray, string &strError)
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
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			OutputDebugStringA(strError.c_str());
			break;
		}

		while (sqlite3_step(lpStmt) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt) == 2)
			{
				lcArray.push_back(tagYINGSHEBIAO());
				tagYINGSHEBIAO &lc		= lcArray.back();

				lc.Bianhao					= sqlite3_column_int(lpStmt, 0);
				lc.Mingcheng				= sqlite3_column_bytes(lpStmt, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt, 1)))	: "";
			}
		}

		sqlite3_finalize(lpStmt);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);

	return bOk;
}