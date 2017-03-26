#include "stdafx.h"
#include "Function.h"

bool QueryTable(string QuerySql, string &dataStr, string &strError)
{

	bool bOk	= true;
	strError	= "";
	dataStr		= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}

		char** pResult;
		int nRow;
		int nCol;
		if (sqlite3_get_table(lpSQlite->Handle(), ASCIItoUTF8(QuerySql).c_str(), &pResult, &nRow, &nCol, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}
		g_ReadWriteLock.unlock();

		int nIndex = nCol;
		for (int i=0; i<nRow; i++)
		{
			for (int j=0; j<nCol; j++)
			{
				dataStr	+= UTF8toASCII(pResult[j]);
				dataStr	+= ":";
				if (pResult[nIndex] != NULL)
					dataStr	+= UTF8toASCII(pResult[nIndex]);
				dataStr	+= ",";

				++nIndex;
			}
			dataStr += ";";
		}
		sqlite3_free_table(pResult);  //使用完后务必释放为记录分配的内存，否则会内存泄漏
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}

		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 16)
			{
				lcArray.push_back(tagZHIQIANSHUJU());
				tagZHIQIANSHUJU &lc	= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt0, 3);
				lc.IP						= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu				= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi		= sqlite3_column_int(lpStmt0, 6);
				lc.Riqi						= sqlite3_column_int64(lpStmt0, 7);
				lc.Yewubianhao				= sqlite3_column_bytes(lpStmt0, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 8)))		: "";
				lc.YuanZhengjianhaoma		= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Xingming					= sqlite3_column_bytes(lpStmt0, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 10)))	: "";
				lc.Qianzhuzhonglei			= sqlite3_column_int(lpStmt0, 11);
				lc.ZhikaZhuangtai			= sqlite3_column_int(lpStmt0, 12);
				lc.Zhengjianhaoma			= sqlite3_column_bytes(lpStmt0, 13)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 13)))	: "";
				lc.Jiekoufanhuijieguo		= sqlite3_column_bytes(lpStmt0, 14)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 14)))	: "";
				lc.Lianxidianhua			= sqlite3_column_bytes(lpStmt0, 15)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 15)))	: "";
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 13)
			{
				lcArray.push_back(tagSHOUZHENGSHUJU());
				tagSHOUZHENGSHUJU &lc	= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt0, 1)	;
				lc.Jubianhao					= sqlite3_column_int(lpStmt0, 2)	;
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt0, 3)	;
				lc.IP							= sqlite3_column_int(lpStmt0, 4)	;
				lc.Bendiyewu					= sqlite3_column_int(lpStmt0, 5)	?  true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt0, 6)	;
				lc.Riqi							= sqlite3_column_int64(lpStmt0, 7);
				lc.Zhengjianleixing				= sqlite3_column_int(lpStmt0, 8)	;
				lc.Zhengjianhaoma				= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Xingming						= sqlite3_column_bytes(lpStmt0, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 10)))		: "";
				lc.Shoulibianhao				= sqlite3_column_bytes(lpStmt0, 11)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 11)))		: "";
				lc.Shifoujiaofei				= sqlite3_column_int(lpStmt0, 12)	?  true:false;
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 15)
			{
				lcArray.push_back(tagQIANZHUSHUJU());
				tagQIANZHUSHUJU &lc			= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt0, 3);
				lc.IP						= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu				= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi		= sqlite3_column_int(lpStmt0, 6);
				lc.Riqi						= sqlite3_column_int64(lpStmt0, 7);
				lc.YuanZhengjianhaoma		= sqlite3_column_bytes(lpStmt0, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 8)))		: "";
				lc.Xingming					= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Xingbie					= sqlite3_column_int(lpStmt0, 10);
				lc.Chushengriqi				= sqlite3_column_int64(lpStmt0, 11);
				lc.Lianxidianhua			= sqlite3_column_bytes(lpStmt0, 12)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 12)))	: "";
				lc.Yewuleixing				= sqlite3_column_int(lpStmt0, 13);
				lc.Shouliren				= sqlite3_column_bytes(lpStmt0, 14)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 14)))	: "";
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 13)
			{
				lcArray.push_back(tagJIAOKUANSHUJU());
				tagJIAOKUANSHUJU &lc		= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt0, 3);
				lc.IP							= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt0, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt0, 7);
				lc.Zhishoudanweidaima			= sqlite3_column_bytes(lpStmt0, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 8)))		: "";
				lc.Jiaokuantongzhishuhaoma		= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Jiaokuanrenxingming			= sqlite3_column_bytes(lpStmt0, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 10)))	: "";
				lc.Yingkoukuanheji				= sqlite3_column_double(lpStmt0, 11);
				lc.Jiaoyiriqi					= sqlite3_column_int64(lpStmt0, 12);
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 12)
			{
				lcArray.push_back(tagCHAXUNSHUJU());
				tagCHAXUNSHUJU &lc				= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt0, 3);
				lc.IP							= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt0, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt0, 7);
				lc.Chaxunhaoma					= sqlite3_column_bytes(lpStmt0, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 8)))		: "";
				lc.Chaxunleixing				= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Shifouchaxunchenggong		= sqlite3_column_int(lpStmt0, 10)	? true:false;
				lc.Chuangjianshijian			= sqlite3_column_int64(lpStmt0, 11);
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 18)
			{
				lcArray.push_back(tagYUSHOULISHUJU());
				tagYUSHOULISHUJU &lc	= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt0, 3);
				lc.IP						= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu				= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi		= sqlite3_column_int(lpStmt0, 6); 
				lc.Riqi						= sqlite3_column_int64(lpStmt0, 7);
				lc.Yewubianhao				= sqlite3_column_bytes(lpStmt0, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 8)))		: "";
				lc.Xingming					= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Lianxidianhua			= sqlite3_column_bytes(lpStmt0, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 10)))	: "";
				lc.Chuguoshiyou				= sqlite3_column_bytes(lpStmt0, 11)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 11)))	: "";
				lc.YuanZhengjianhaoma		= sqlite3_column_bytes(lpStmt0, 12)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 12)))	: "";
				lc.Qianzhuzhonglei			= sqlite3_column_int(lpStmt0, 13);
				lc.Xingbie					= sqlite3_column_int(lpStmt0, 14);
				lc.Hukousuozaidi			= sqlite3_column_bytes(lpStmt0, 15)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 15)))	: "";
				lc.Minzu					= sqlite3_column_bytes(lpStmt0, 16)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 16)))	: "";
				lc.Chuangjianshijian		= sqlite3_column_int64(lpStmt0, 17);
			}	   
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QuerySHEBEIZHUANGTAI(string QuerySql, std::vector<tagSHEBEIZHUANGTAI> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 9)
			{
				lcArray.push_back(tagSHEBEIZHUANGTAI());
				tagSHEBEIZHUANGTAI &lc	= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt0, 3);
				lc.IP							= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt0, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt0, 7);
				lc.Shifouzaixian				= sqlite3_column_bytes(lpStmt0, 8) ? true:false;
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}

bool QuerySHEBEIYICHANGSHUJU(string QuerySql, std::vector<tagSHEBEIYICHANGSHUJU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 11)
			{
				lcArray.push_back(tagSHEBEIYICHANGSHUJU());
				tagSHEBEIYICHANGSHUJU &lc	= lcArray.back();

				lc.Xuhao						= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao				= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao					= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao			= sqlite3_column_int(lpStmt0, 3);
				lc.IP							= sqlite3_column_int(lpStmt0, 4);
				lc.Bendiyewu					= sqlite3_column_int(lpStmt0, 5) ? true:false;
				lc.Shebeibaifangweizhi			= sqlite3_column_int(lpStmt0, 6);
				lc.Riqi							= sqlite3_column_int64(lpStmt0, 7);
				lc.Yichangshejimokuai			= sqlite3_column_bytes(lpStmt0, 8)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 8)))		: "";
				lc.Yichangyuanyin				= sqlite3_column_bytes(lpStmt0, 9)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 9)))		: "";
				lc.Yichangxiangxineirong		= sqlite3_column_bytes(lpStmt0, 10)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 10)))	: "";
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryGUANLIYUAN(string QuerySql, std::vector<tagGUANLIYUAN> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 6)
			{
				lcArray.push_back(tagGUANLIYUAN());
				tagGUANLIYUAN &lc		= lcArray.back();

				lc.Xuhao				= sqlite3_column_int(lpStmt0, 0);
				lc.Yonghuming			= sqlite3_column_bytes(lpStmt0, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 1)))		: "";
				lc.Mima					= sqlite3_column_bytes(lpStmt0, 2)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 2)))		: "";
				lc.Youxiaoqikaishi		= sqlite3_column_int(lpStmt0, 3);
				lc.Youxiaoqijieshu		= sqlite3_column_int(lpStmt0, 4);
				lc.Quanxianjibie		= sqlite3_column_int(lpStmt0, 5) ? true:false;
			}
		}
		sqlite3_finalize(lpStmt0);

		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryGUANLIYUANCAOZUOJILU(string QuerySql, std::vector<tagGUANLIYUANCAOZUOJILU> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 5)
			{
				lcArray.push_back(tagGUANLIYUANCAOZUOJILU());
				tagGUANLIYUANCAOZUOJILU &lc		= lcArray.back();

				lc.Xuhao				= sqlite3_column_int(lpStmt0, 0);
				lc.Yonghuming			= sqlite3_column_bytes(lpStmt0, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 1)))		: "";
				lc.Riqi					= sqlite3_column_int64(lpStmt0, 2);
				lc.Caozuoleibie			= sqlite3_column_bytes(lpStmt0, 3)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 3)))		: "";
				lc.Caozuoneirong		= sqlite3_column_bytes(lpStmt0, 4)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 4)))		: "";
			}
		}
		sqlite3_finalize(lpStmt0);

		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QuerySHEBEIGUANLI(string QuerySql, std::vector<tagSHEBEIGUANLI> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break; 
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 14)
			{
				lcArray.push_back(tagSHEBEIGUANLI());
				tagSHEBEIGUANLI &lc		= lcArray.back();

				lc.Xuhao					= sqlite3_column_int(lpStmt0, 0);
				lc.Chengshibianhao			= sqlite3_column_int(lpStmt0, 1);
				lc.Jubianhao				= sqlite3_column_int(lpStmt0, 2);
				lc.Shiyongdanweibianhao		= sqlite3_column_int(lpStmt0, 3);
				lc.IP						= sqlite3_column_int(lpStmt0, 4);
				lc.Shebeichangjia			= sqlite3_column_bytes(lpStmt0, 5)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 5)))		: "";;
				lc.Shebeimingcheng			= sqlite3_column_bytes(lpStmt0, 6)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 6)))		: "";;
				lc.Shebeileixing			= sqlite3_column_bytes(lpStmt0, 7)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 7)))		: "";;
				lc.Jingdu					= sqlite3_column_double(lpStmt0, 8);
				lc.Weidu					= sqlite3_column_double(lpStmt0, 9);
				lc.Chuangjianshijian		= sqlite3_column_int64(lpStmt0, 10);
				lc.Yingjianxinxi			= sqlite3_column_bytes(lpStmt0, 11)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 11)))		: "";;
				lc.Ruanjianxinxi			= sqlite3_column_bytes(lpStmt0, 12)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 12)))		: "";;
				lc.Ruanjianshengjixinxi		= sqlite3_column_bytes(lpStmt0, 13)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 13)))		: "";;
			}
		}	

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}
bool QueryYINGSHEBIAO(string QuerySql, std::vector<tagYINGSHEBIAO> &lcArray, string &strError)
{
	bool bOk	= true;
	strError	= "";
	do
	{
		g_ReadWriteLock.lock(CReadWriteLock::LOCK_LEVEL_READ);

		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
		{
			strError = "打开基础支撑数据库失败";
			bOk = false;
			break;
		}
		sqlite3_stmt   *lpStmt0   =  NULL;
		std::string     lstrSQL  =  QuerySql;
		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt0, NULL) != SQLITE_OK)
		{
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		g_ReadWriteLock.unlock();

		while (sqlite3_step(lpStmt0) == SQLITE_ROW)
		{
			if (sqlite3_column_count(lpStmt0) == 2)
			{
				lcArray.push_back(tagYINGSHEBIAO());
				tagYINGSHEBIAO &lc		= lcArray.back();

				lc.Bianhao					= sqlite3_column_int(lpStmt0, 0);
				lc.Mingcheng				= sqlite3_column_bytes(lpStmt0, 1)	? (UTF8toASCII((char *)sqlite3_column_text(lpStmt0, 1)))	: "";
			}
		}

		sqlite3_finalize(lpStmt0);
		sqlite3_release_memory((int)sqlite3_memory_used());
	} while (0);
	if (bOk == false) g_ReadWriteLock.unlock();

	return bOk;
}