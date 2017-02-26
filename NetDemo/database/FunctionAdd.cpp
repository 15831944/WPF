#include "stdafx.h"
#include "Function.h"

//bool AddIDCARDAPPLY(tagIDCARDAPPLY  station, string &strError)
//{
//	bool bOk	= true;
//	strError	= "";
//	do
//	{
//		std::auto_ptr<CSqlite>  lpSQlite(new CSqlite);
//		if (!lpSQlite->Open(RIM_RTK_BSD_DB_FILE, false, true))
//		{
//			strError = "打开基础支撑数据库失败";
//			OutputDebugStringA(strError.c_str());
//			bOk = false;
//			break;
//		}
//		sqlite3_stmt   *lpStmt   =  NULL;
//
//
//		std::string     lstrSQL  =  " INSERT INTO "
//			T_IDCARDAPPLY 						"("
//			T_IDCARDAPPLY_NAME					","
//			T_IDCARDAPPLY_GENDER				","
//			T_IDCARDAPPLY_NATION				","
//			T_IDCARDAPPLY_BIRTHDAY				","
//			T_IDCARDAPPLY_ADDRESS				","
//			T_IDCARDAPPLY_IDNUMBER				","
//			T_IDCARDAPPLY_SIGDEPART				","
//			T_IDCARDAPPLY_SLH					","
//			T_IDCARDAPPLY_FPDATA				","
//			T_IDCARDAPPLY_FPFEATURE				","
//			T_IDCARDAPPLY_XCZP					","
//			T_IDCARDAPPLY_XZQH					","
//			T_IDCARDAPPLY_SANNERID				","
//			T_IDCARDAPPLY_SCANNERNAME			","
//			T_IDCARDAPPLY_LEGAL					","
//			T_IDCARDAPPLY_OPERATORID			","
//			T_IDCARDAPPLY_OPERATORNAME			","
//			T_IDCARDAPPLY_OPDATE				")"
//			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
//			;
//
//		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt, NULL) != SQLITE_OK)
//		{
//			char ch[512] ={ 0 };
//			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
//			strError = ch;
//			OutputDebugStringA(strError.c_str());
//			break;
//		}
//
//		int insertCount = 1;
//		const char* strData = "This is a test.";
//		//7. 基于已有的SQL语句，迭代的绑定不同的变量数据
//		for (int i = 0; i < insertCount; ++i) {
//			//在绑定时，最左面的变量索引值是1。
//
//			sqlite3_bind_text(lpStmt	, 1	, station.name.c_str()			, station.name.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 2	, station.gender.c_str()		, station.gender.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 3	, station.Nation.c_str()		, station.Nation.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 4	, station.Birthday.c_str()		, station.Birthday.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 5	, station.Address.c_str()		, station.Address.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 6	, station.IdNumber.c_str()		, station.IdNumber.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 7	, station.SigDepart.c_str()		, station.SigDepart.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 8	, station.SLH.c_str()			, station.SLH.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 9	, station.fpData.c_str()		, station.fpData.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 10, station.fpFeature.c_str()		, station.fpFeature.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 11, station.XCZP.c_str()			, station.XCZP.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 12, station.XZQH.c_str()			, station.XZQH.size()				, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 13, station.sannerId.c_str()		, station.sannerId.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 14, station.scannerName.c_str()	, station.scannerName.size()		, SQLITE_STATIC);
//			sqlite3_bind_int(lpStmt		, 15, station.legal);
//			sqlite3_bind_text(lpStmt	, 16, station.operatorID.c_str()	, station.operatorID.size()			, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 17, station.operatorName.c_str()	, station.operatorName.size()		, SQLITE_STATIC);
//			sqlite3_bind_text(lpStmt	, 18, station.opDate.c_str()		, station.opDate.size()				, SQLITE_STATIC);
//
//			int dd = sqlite3_step(lpStmt);
//			if (dd != SQLITE_ROW) {
//				char ch[512] ={ 0 };
//				sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
//				strError = ch;
//				OutputDebugStringA(strError.c_str());
//				break;
//			}
//			//重新初始化该sqlite3_stmt对象绑定的变量。
//			sqlite3_reset(lpStmt);
//		}
//
//		sqlite3_finalize(lpStmt);
//		sqlite3_release_memory((int)sqlite3_memory_used());
//	} while (0);
//
//	return bOk;
//}

void split(const string& str, vector<string>& ret_, string sep = ",")
{
	if (str.empty())
	{
		return;
	}

	string tmp;
	string::size_type pos_begin = str.find_first_not_of(sep);
	string::size_type comma_pos = 0;

	while (pos_begin != string::npos)
	{
		comma_pos = str.find(sep, pos_begin);
		if (comma_pos != string::npos)
		{
			tmp = str.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + sep.length();
		}
		else
		{
			tmp = str.substr(pos_begin);
			pos_begin = comma_pos;
		}

		if (!tmp.empty())
		{
			ret_.push_back(tmp);
			tmp.clear();
		}
	}

	return;
}
void makeFieldsTypeMap(char* tableName, vector<std::pair<std::string, int>>& fieldsTypeMap)
{
	fieldsTypeMap.clear();

	if (strcmp(tableName, T_ZHIQIANSHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_ZHIQIANSHUJU, SQLITE_NULL },
			{ T_ZHIQIANSHUJU_XUHAO, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_IP, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_RIQI, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_YEWUBIANHAO, SQLITE_TEXT },
			{ T_ZHIQIANSHUJU_YUANZHENGJIANHAOMA, SQLITE_TEXT },
			{ T_ZHIQIANSHUJU_XINGMING, SQLITE_TEXT },
			{ T_ZHIQIANSHUJU_QIANZHUZHONGLEI, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_ZHIKAZHUANGTAI, SQLITE_INTEGER },
			{ T_ZHIQIANSHUJU_ZHENGJIANHAOMA, SQLITE_TEXT },
			{ T_ZHIQIANSHUJU_JIEKOUFANHUIJIEGUO, SQLITE_TEXT },
			{ T_ZHIQIANSHUJU_LIANXIDIANHUA, SQLITE_TEXT },
		};
	}
	else if (strcmp(tableName, T_SHOUZHENGSHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_SHOUZHENGSHUJU, SQLITE_NULL },
			{ T_SHOUZHENGSHUJU_XUHAO, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_IP, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_RIQI, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_ZHENGJIANLEIXING, SQLITE_INTEGER },
			{ T_SHOUZHENGSHUJU_ZHENGJIANHAOMA, SQLITE_TEXT },
			{ T_SHOUZHENGSHUJU_XINGMING, SQLITE_TEXT },
			{ T_SHOUZHENGSHUJU_SHOULIBIANHAO, SQLITE_TEXT },
			{ T_SHOUZHENGSHUJU_SHIFOUJIAOFEI, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_QIANZHUSHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_QIANZHUSHUJU, SQLITE_NULL },
			{ T_QIANZHUSHUJU_XUHAO, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_IP, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_RIQI, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_YUANZHENGJIANHAOMA, SQLITE_TEXT },
			{ T_QIANZHUSHUJU_XINGMING, SQLITE_TEXT },
			{ T_QIANZHUSHUJU_XINGBIE, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_CHUSHENGRIQI, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_LIANXIDIANHUA, SQLITE_TEXT },
			{ T_QIANZHUSHUJU_YEWULEIXING, SQLITE_INTEGER },
			{ T_QIANZHUSHUJU_SHOULIREN, SQLITE_TEXT },
		};
	}
	else if (strcmp(tableName, T_JIAOKUANSHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_JIAOKUANSHUJU, SQLITE_NULL },
			{ T_JIAOKUANSHUJU_XUHAO, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_IP, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_RIQI, SQLITE_INTEGER },
			{ T_JIAOKUANSHUJU_ZHISHOUDANWEIDAIMA, SQLITE_TEXT },
			{ T_JIAOKUANSHUJU_JIAOKUANTONGZHISHUHAOMA, SQLITE_TEXT },
			{ T_JIAOKUANSHUJU_JIAOKUANRENXINGMING, SQLITE_TEXT },
			{ T_JIAOKUANSHUJU_YINGKOUKUANHEJI, SQLITE_FLOAT },
			{ T_JIAOKUANSHUJU_JIAOYIRIQI, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_CHAXUNSHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_CHAXUNSHUJU, SQLITE_NULL },
			{ T_CHAXUNSHUJU_XUHAO, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_IP, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_RIQI, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_CHAXUNHAOMA, SQLITE_TEXT },
			{ T_CHAXUNSHUJU_CHAXUNLEIXING, SQLITE_TEXT },
			{ T_CHAXUNSHUJU_SHIFOUCHAXUNCHENGGONG, SQLITE_INTEGER },
			{ T_CHAXUNSHUJU_CHUANGJIANSHIJIAN, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_YUSHOULISHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_YUSHOULISHUJU, SQLITE_NULL },
			{ T_YUSHOULISHUJU_XUHAO, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_IP, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_RIQI, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_YEWUBIANHAO, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_XINGMING, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_LIANXIDIANHUA, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_CHUGUOSHIYOU, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_YUANZHENGJIANHAOMA, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_QIANZHUZHONGLEI, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_XINGBIE, SQLITE_INTEGER },
			{ T_YUSHOULISHUJU_HUKOUSUOZAIDI, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_MINZU, SQLITE_TEXT },
			{ T_YUSHOULISHUJU_CHUANGJIANSHIJIAN, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_SHEBEIZHUANGTAI) == 0)
	{
		fieldsTypeMap ={
			{ T_SHEBEIZHUANGTAI, SQLITE_NULL },
			{ T_SHEBEIZHUANGTAI_XUHAO, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_JUBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_IP, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_BENDIYEWU, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_RIQI, SQLITE_INTEGER },
			{ T_SHEBEIZHUANGTAI_SHIFOUZAIXIAN, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_SHEBEIYICHANGSHUJU) == 0)
	{
		fieldsTypeMap ={
			{ T_SHEBEIYICHANGSHUJU, SQLITE_NULL },
			{ T_SHEBEIYICHANGSHUJU_XUHAO, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_JUBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_IP, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_BENDIYEWU, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_SHEBEIBAIFANGWEIZHI, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_RIQI, SQLITE_INTEGER },
			{ T_SHEBEIYICHANGSHUJU_YICHANGSHEJIMOKUAI, SQLITE_TEXT },
			{ T_SHEBEIYICHANGSHUJU_YICHANGYUANYIN, SQLITE_TEXT },
			{ T_SHEBEIYICHANGSHUJU_YICHANGXIANGXINEIRONG, SQLITE_TEXT },
		};
	}
	else if (strcmp(tableName, T_GUANLIYUAN) == 0)
	{
		fieldsTypeMap ={
			{ T_GUANLIYUAN, SQLITE_NULL },
			{ T_GUANLIYUAN_XUHAO, SQLITE_INTEGER },
			{ T_GUANLIYUAN_YONGHUMING, SQLITE_TEXT },
			{ T_GUANLIYUAN_MIMA, SQLITE_TEXT },
			{ T_GUANLIYUAN_YOUXIAOQIKAISHI, SQLITE_INTEGER },
			{ T_GUANLIYUAN_YOUXIAOQIJIESHU, SQLITE_INTEGER },
			{ T_GUANLIYUAN_QUANXIANJIBIE, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_GUANLIYUANCAOZUOJILU) == 0)
	{
		fieldsTypeMap ={
			{ T_GUANLIYUANCAOZUOJILU, SQLITE_NULL },
			{ T_GUANLIYUANCAOZUOJILU_XUHAO, SQLITE_INTEGER },
			{ T_GUANLIYUANCAOZUOJILU_YONGHUMING, SQLITE_TEXT },
			{ T_GUANLIYUANCAOZUOJILU_RIQI, SQLITE_INTEGER },
			{ T_GUANLIYUANCAOZUOJILU_CAOZUOLEIBIE, SQLITE_TEXT },
			{ T_GUANLIYUANCAOZUOJILU_CAOZUONEIRONG, SQLITE_TEXT },
		};
	}
	else if (strcmp(tableName, T_SHEBEIGUANLI) == 0)
	{
		fieldsTypeMap ={
			{ T_SHEBEIGUANLI, SQLITE_NULL },
			{ T_SHEBEIGUANLI_XUHAO, SQLITE_INTEGER },
			{ T_SHEBEIGUANLI_CHENGSHIBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIGUANLI_JUBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIGUANLI_SHIYONGDANWEIBIANHAO, SQLITE_INTEGER },
			{ T_SHEBEIGUANLI_IP, SQLITE_INTEGER },
			{ T_SHEBEIGUANLI_SHEBEICHANGJIA, SQLITE_TEXT },
			{ T_SHEBEIGUANLI_SHEBEIMINGCHENG, SQLITE_TEXT },
			{ T_SHEBEIGUANLI_SHEBEILEIXING, SQLITE_TEXT },
			{ T_SHEBEIGUANLI_JINGDU, SQLITE_FLOAT },
			{ T_SHEBEIGUANLI_WEIDU, SQLITE_FLOAT },
			{ T_SHEBEIGUANLI_CHUANGJIANSHIJIAN, SQLITE_INTEGER },
		};
	}
	else if (strcmp(tableName, T_YINGSHEBIAO) == 0)
	{
		fieldsTypeMap ={
			{ T_YINGSHEBIAO, SQLITE_NULL },
			{ T_YINGSHEBIAO_BIANHAO, SQLITE_INTEGER },
			{ T_YINGSHEBIAO_MINGCHENG, SQLITE_TEXT },
		};
	}
}

/*std::string     lstrSQL  =  " INSERT INTO "
T_ZHIQIANSHUJU								"("
T_ZHIQIANSHUJU_XUHAO						","
T_ZHIQIANSHUJU_CHENGSHIBIANHAO				","
T_ZHIQIANSHUJU_JUBIANHAO					","
T_ZHIQIANSHUJU_SHIYONGDANWEIBIANHAO			","
T_ZHIQIANSHUJU_IP							","
T_ZHIQIANSHUJU_BENDIYEWU					","
T_ZHIQIANSHUJU_SHEBEIBAIFANGWEIZHI			","
T_ZHIQIANSHUJU_RIQI							","
T_ZHIQIANSHUJU_YEWUBIANHAO					","
T_ZHIQIANSHUJU_YUANZHENGJIANHAOMA			","
T_ZHIQIANSHUJU_XINGMING						","
T_ZHIQIANSHUJU_QIANZHUZHONGLEI				","
T_ZHIQIANSHUJU_ZHIKAZHUANGTAI				","
T_ZHIQIANSHUJU_ZHENGJIANHAOMA				","
T_ZHIQIANSHUJU_JIEKOUFANHUIJIEGUO			","
T_ZHIQIANSHUJU_LIANXIDIANHUA				")"
" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
;*/

bool AddTable(char* tableName, char* dataStr, string &strError)
{
	bool bOk	= true;
	strError	= "";
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
		if (sqlite3_prepare_v2(lpSQlite->Handle(), beginSQL, strlen(beginSQL), &lpStmt0, NULL) != SQLITE_OK) 
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

		std::string		lstrSQL		= " INSERT INTO ";
		sqlite3_stmt   *lpStmt1		=  NULL;
		vector<std::pair<std::string, int>> fieldsTypeMap;
		makeFieldsTypeMap(tableName, fieldsTypeMap);

		//make Insert statement
		UINT i = 0;
		for (vector<std::pair<std::string, int>>::iterator it = fieldsTypeMap.begin(); it != fieldsTypeMap.end(); ++it, ++i)
		{
			lstrSQL += it->first;
			if (i == 0)
				lstrSQL += "(";
			else if ((i + 1) == fieldsTypeMap.size())
				lstrSQL += ")";
			else
				lstrSQL += ",";
		}
		lstrSQL += " VALUES(";
		for (i = 1; i < fieldsTypeMap.size(); ++i)
		{
			lstrSQL += "?";
			if ((i + 1) == fieldsTypeMap.size())
				lstrSQL += ")";
			else
				lstrSQL += ",";
		}

		if (sqlite3_prepare_v2(lpSQlite->Handle(), ASCIItoUTF8(lstrSQL).c_str(), -1, &lpStmt1, NULL) != SQLITE_OK)
		{
			if (lpStmt1) sqlite3_finalize(lpStmt1);
			bOk = false;
			char ch[512] ={ 0 };
			sprintf_s(ch, 512, "Prepare SQL:%s failure:%s\n", lstrSQL.c_str(), sqlite3_errmsg(lpSQlite->Handle()));
			strError = ch;
			break;
		}

		vector<string> rows; rows.reserve(1000);
		vector<string> cells; cells.reserve(1000);
		split(dataStr, rows, ";");
		for (int rowIndex = 0; rowIndex < rows.size(); ++rowIndex)
		{
			string& row = rows[rowIndex];
			if (row.length() > 0)
			{
				cells.clear();
				split(row, cells, ",");
				for (int colIndex = 0; colIndex < cells.size(); ++colIndex){
					string& cell = cells[colIndex];
					vector<string> keyvalue;
					split(cell, keyvalue, ":");

					for (UINT index = 0; index < fieldsTypeMap.size(); ++index){
						std::pair<std::string, int> it = fieldsTypeMap.at(index);
						if (sqlite3_strnicmp(it.first.c_str(), keyvalue[0].c_str(), 256) == 0){
							int rc;
							switch (it.second){
								case SQLITE_INTEGER:
									if (it.first == "Xuhao" && keyvalue[1]== "0")
										break;
									rc = sqlite3_bind_int64(lpStmt1, index, _atoi64(keyvalue[1].c_str()));
									break;
								case SQLITE_FLOAT:
									rc = sqlite3_bind_double(lpStmt1, index, atof(keyvalue[1].c_str()));
									break;
								case SQLITE_BLOB:
									;
									break;
								case SQLITE_TEXT:
									rc = sqlite3_bind_text(lpStmt1, index, keyvalue[1].c_str(), keyvalue[1].size(), SQLITE_STATIC);
									break;
								default:
									rc = sqlite3_bind_null(lpStmt1, index);
									break;
							}
							break;
						}
					}
				}

				int dd = sqlite3_step(lpStmt1);
				if (dd != SQLITE_ROW) {
					if (lpStmt1) sqlite3_finalize(lpStmt1);
					bOk = false; char ch[512] ={ 0 };
					sprintf_s(ch, 512, "failure:%s\n", sqlite3_errmsg(lpSQlite->Handle()));
					strError = ch;
					break;
				}
				//重新初始化该sqlite3_stmt对象绑定的变量。
				sqlite3_reset(lpStmt1);
			}
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
			break;
		}
		sqlite3_finalize(lpStmt2);


		sqlite3_release_memory((int)sqlite3_memory_used());
	}while (0);

	return bOk;
}


bool AddZHIQIANSHUJU(tagZHIQIANSHUJU  data, string &strError)
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
			T_ZHIQIANSHUJU								"("
			T_ZHIQIANSHUJU_XUHAO						","
			T_ZHIQIANSHUJU_CHENGSHIBIANHAO				","
			T_ZHIQIANSHUJU_JUBIANHAO					","
			T_ZHIQIANSHUJU_SHIYONGDANWEIBIANHAO			","
			T_ZHIQIANSHUJU_IP							","
			T_ZHIQIANSHUJU_BENDIYEWU					","
			T_ZHIQIANSHUJU_SHEBEIBAIFANGWEIZHI			","
			T_ZHIQIANSHUJU_RIQI							","
			T_ZHIQIANSHUJU_YEWUBIANHAO					","
			T_ZHIQIANSHUJU_YUANZHENGJIANHAOMA			","
			T_ZHIQIANSHUJU_XINGMING						","
			T_ZHIQIANSHUJU_QIANZHUZHONGLEI				","
			T_ZHIQIANSHUJU_ZHIKAZHUANGTAI				","
			T_ZHIQIANSHUJU_ZHENGJIANHAOMA				","
			T_ZHIQIANSHUJU_JIEKOUFANHUIJIEGUO			","
			T_ZHIQIANSHUJU_LIANXIDIANHUA				")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_text(lpStmt, 9, data.Yewubianhao.c_str(), data.Yewubianhao.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 10, data.YuanZhengjianhaoma.c_str(), data.YuanZhengjianhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 11, data.Xingming.c_str(), data.Xingming.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 12, data.Qianzhuzhonglei);
			sqlite3_bind_int(lpStmt, 13, data.ZhikaZhuangtai);
			sqlite3_bind_text(lpStmt, 14, data.Zhengjianhaoma.c_str(), data.Zhengjianhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 15, data.Jiekoufanhuijieguo.c_str(), data.Jiekoufanhuijieguo.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 16, data.Lianxidianhua.c_str(), data.Lianxidianhua.size(), SQLITE_STATIC);

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

bool AddSHOUZHENGSHUJU(tagSHOUZHENGSHUJU  data, string &strError)
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
			T_SHOUZHENGSHUJU								"("
			T_SHOUZHENGSHUJU_XUHAO							","
			T_SHOUZHENGSHUJU_CHENGSHIBIANHAO				","
			T_SHOUZHENGSHUJU_JUBIANHAO						","
			T_SHOUZHENGSHUJU_SHIYONGDANWEIBIANHAO			","
			T_SHOUZHENGSHUJU_IP								","
			T_SHOUZHENGSHUJU_BENDIYEWU						","
			T_SHOUZHENGSHUJU_SHEBEIBAIFANGWEIZHI			","
			T_SHOUZHENGSHUJU_RIQI							","
			T_SHOUZHENGSHUJU_ZHENGJIANLEIXING				","
			T_SHOUZHENGSHUJU_ZHENGJIANHAOMA					","
			T_SHOUZHENGSHUJU_XINGMING						","
			T_SHOUZHENGSHUJU_SHOULIBIANHAO					","
			T_SHOUZHENGSHUJU_SHIFOUJIAOFEI					")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_int(lpStmt, 9, data.Zhengjianleixing);
			sqlite3_bind_text(lpStmt, 10, data.Zhengjianhaoma.c_str(), data.Zhengjianhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 11, data.Xingming.c_str(), data.Xingming.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 12, data.Shoulibianhao.c_str(), data.Shoulibianhao.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 13, data.Shifoujiaofei);

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

bool AddQIANZHUSHUJU(tagQIANZHUSHUJU  data, string &strError)
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
			T_QIANZHUSHUJU								"("
			T_QIANZHUSHUJU_XUHAO						","
			T_QIANZHUSHUJU_CHENGSHIBIANHAO				","
			T_QIANZHUSHUJU_JUBIANHAO					","
			T_QIANZHUSHUJU_SHIYONGDANWEIBIANHAO			","
			T_QIANZHUSHUJU_IP							","
			T_QIANZHUSHUJU_BENDIYEWU					","
			T_QIANZHUSHUJU_SHEBEIBAIFANGWEIZHI			","
			T_QIANZHUSHUJU_RIQI							","
			T_QIANZHUSHUJU_YUANZHENGJIANHAOMA			","
			T_QIANZHUSHUJU_XINGMING						","
			T_QIANZHUSHUJU_XINGBIE						","
			T_QIANZHUSHUJU_CHUSHENGRIQI					","
			T_QIANZHUSHUJU_LIANXIDIANHUA				","
			T_QIANZHUSHUJU_YEWULEIXING					","
			T_QIANZHUSHUJU_SHOULIREN					")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_text(lpStmt, 9, data.YuanZhengjianhaoma.c_str(), data.YuanZhengjianhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 10, data.Xingming.c_str(), data.Xingming.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 11, data.Xingbie);
			sqlite3_bind_int64(lpStmt, 12, data.Chushengriqi);
			sqlite3_bind_text(lpStmt, 13, data.Lianxidianhua.c_str(), data.Lianxidianhua.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 14, data.Yewuleixing);
			sqlite3_bind_text(lpStmt, 15, data.Shouliren.c_str(), data.Shouliren.size(), SQLITE_STATIC);

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
bool AddJIAOKUANSHUJU(tagJIAOKUANSHUJU  data, string &strError)
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
			T_JIAOKUANSHUJU									"("
			T_JIAOKUANSHUJU_XUHAO							","
			T_JIAOKUANSHUJU_CHENGSHIBIANHAO					","
			T_JIAOKUANSHUJU_JUBIANHAO						","
			T_JIAOKUANSHUJU_SHIYONGDANWEIBIANHAO			","
			T_JIAOKUANSHUJU_IP								","
			T_JIAOKUANSHUJU_BENDIYEWU						","
			T_JIAOKUANSHUJU_SHEBEIBAIFANGWEIZHI				","
			T_JIAOKUANSHUJU_RIQI							","
			T_JIAOKUANSHUJU_ZHISHOUDANWEIDAIMA				","
			T_JIAOKUANSHUJU_JIAOKUANTONGZHISHUHAOMA			","
			T_JIAOKUANSHUJU_JIAOKUANRENXINGMING				","
			T_JIAOKUANSHUJU_YINGKOUKUANHEJI					","
			T_JIAOKUANSHUJU_JIAOYIRIQI						")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_text(lpStmt, 9, data.Zhishoudanweidaima.c_str(), data.Zhishoudanweidaima.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 10, data.Jiaokuantongzhishuhaoma.c_str(), data.Jiaokuantongzhishuhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 11, data.Jiaokuanrenxingming.c_str(), data.Jiaokuanrenxingming.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 12, data.Yingkoukuanheji);
			sqlite3_bind_int64(lpStmt, 13, data.Jiaoyiriqi);

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
bool AddCHAXUNSHUJU(tagCHAXUNSHUJU  data, string &strError)
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
			T_CHAXUNSHUJU								"("
			T_CHAXUNSHUJU_XUHAO							","
			T_CHAXUNSHUJU_CHENGSHIBIANHAO				","
			T_CHAXUNSHUJU_JUBIANHAO						","
			T_CHAXUNSHUJU_SHIYONGDANWEIBIANHAO			","
			T_CHAXUNSHUJU_IP							","
			T_CHAXUNSHUJU_BENDIYEWU						","
			T_CHAXUNSHUJU_SHEBEIBAIFANGWEIZHI			","
			T_CHAXUNSHUJU_RIQI							","
			T_CHAXUNSHUJU_CHAXUNHAOMA					","
			T_CHAXUNSHUJU_CHAXUNLEIXING					","
			T_CHAXUNSHUJU_SHIFOUCHAXUNCHENGGONG			","
			T_CHAXUNSHUJU_CHUANGJIANSHIJIAN				")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_text(lpStmt, 9, data.Chaxunhaoma.c_str(), data.Chaxunhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 10, data.Chaxunleixing.c_str(), data.Chaxunleixing.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 11, data.Shifouchaxunchenggong);
			sqlite3_bind_int64(lpStmt, 12, data.Chuangjianshijian);

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
bool AddYUSHOULISHUJU(tagYUSHOULISHUJU  data, string &strError)
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
			T_YUSHOULISHUJU									"("
			T_YUSHOULISHUJU_XUHAO							","
			T_YUSHOULISHUJU_CHENGSHIBIANHAO					","
			T_YUSHOULISHUJU_JUBIANHAO						","
			T_YUSHOULISHUJU_SHIYONGDANWEIBIANHAO			","
			T_YUSHOULISHUJU_IP								","
			T_YUSHOULISHUJU_BENDIYEWU						","
			T_YUSHOULISHUJU_SHEBEIBAIFANGWEIZHI				","
			T_YUSHOULISHUJU_RIQI							","
			T_YUSHOULISHUJU_YEWUBIANHAO						","
			T_YUSHOULISHUJU_XINGMING						","
			T_YUSHOULISHUJU_LIANXIDIANHUA					","
			T_YUSHOULISHUJU_CHUGUOSHIYOU					","
			T_YUSHOULISHUJU_YUANZHENGJIANHAOMA				","
			T_YUSHOULISHUJU_QIANZHUZHONGLEI					","
			T_YUSHOULISHUJU_XINGBIE							","
			T_YUSHOULISHUJU_HUKOUSUOZAIDI					","
			T_YUSHOULISHUJU_MINZU							","
			T_YUSHOULISHUJU_CHUANGJIANSHIJIAN				")"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_text(lpStmt, 9, data.Yewubianhao.c_str(), data.Yewubianhao.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 10, data.Xingming.c_str(), data.Xingming.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 11, data.Lianxidianhua.c_str(), data.Lianxidianhua.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 12, data.Chuguoshiyou.c_str(), data.Chuguoshiyou.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 13, data.YuanZhengjianhaoma.c_str(), data.YuanZhengjianhaoma.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 14, data.Qianzhuzhonglei);
			sqlite3_bind_int(lpStmt, 15, data.Xingbie);
			sqlite3_bind_text(lpStmt, 16, data.Hukousuozaidi.c_str(), data.Hukousuozaidi.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 17, data.Minzu.c_str(), data.Minzu.size(), SQLITE_STATIC);
			sqlite3_bind_int64(lpStmt, 18, data.Chuangjianshijian);

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
bool AddSHEBEIZHUANGTAI(tagSHEBEIZHUANGTAI  data, string &strError)
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
			T_SHEBEIZHUANGTAI											"("
			T_SHEBEIZHUANGTAI_XUHAO										","
			T_SHEBEIZHUANGTAI_CHENGSHIBIANHAO							","
			T_SHEBEIZHUANGTAI_JUBIANHAO									","
			T_SHEBEIZHUANGTAI_SHIYONGDANWEIBIANHAO						","
			T_SHEBEIZHUANGTAI_IP										","
			T_SHEBEIZHUANGTAI_BENDIYEWU									","
			T_SHEBEIZHUANGTAI_SHEBEIBAIFANGWEIZHI						","
			T_SHEBEIZHUANGTAI_RIQI										","
			T_SHEBEIZHUANGTAI_SHIFOUZAIXIAN								")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_int(lpStmt, 9, data.Shifouzaixian);

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
bool AddSHEBEIYICHANGSHUJU(tagSHEBEIYICHANGSHUJU  data, string &strError)
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
			T_SHEBEIYICHANGSHUJU										"("
			T_SHEBEIYICHANGSHUJU_XUHAO									","
			T_SHEBEIYICHANGSHUJU_CHENGSHIBIANHAO						","
			T_SHEBEIYICHANGSHUJU_JUBIANHAO								","
			T_SHEBEIYICHANGSHUJU_SHIYONGDANWEIBIANHAO					","
			T_SHEBEIYICHANGSHUJU_IP										","
			T_SHEBEIYICHANGSHUJU_BENDIYEWU								","
			T_SHEBEIYICHANGSHUJU_SHEBEIBAIFANGWEIZHI					","
			T_SHEBEIYICHANGSHUJU_RIQI									","
			T_SHEBEIYICHANGSHUJU_YICHANGSHEJIMOKUAI						","
			T_SHEBEIYICHANGSHUJU_YICHANGYUANYIN							","
			T_SHEBEIYICHANGSHUJU_YICHANGXIANGXINEIRONG					")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_int(lpStmt, 6, data.Bendiyewu);
			sqlite3_bind_int(lpStmt, 7, data.Shebeibaifangweizhi);
			sqlite3_bind_int64(lpStmt, 8, data.Riqi);
			sqlite3_bind_text(lpStmt, 9, data.Yichangshejimokuai.c_str(), data.Yichangshejimokuai.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 10, data.Yichangyuanyin.c_str(), data.Yichangyuanyin.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 11, data.Yichangxiangxineirong.c_str(), data.Yichangxiangxineirong.size(), SQLITE_STATIC);

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
bool AddGUANLIYUAN(tagGUANLIYUAN  data, string &strError)
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
			T_GUANLIYUAN							"("
			T_GUANLIYUAN_XUHAO						","
			T_GUANLIYUAN_YONGHUMING					","
			T_GUANLIYUAN_MIMA						","
			T_GUANLIYUAN_YOUXIAOQIKAISHI			","
			T_GUANLIYUAN_YOUXIAOQIJIESHU			","
			T_GUANLIYUAN_QUANXIANJIBIE				")"
			" VALUES(?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_text(lpStmt, 2, data.Yonghuming.c_str(), data.Yonghuming.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 3, data.Mima.c_str(), data.Mima.size(), SQLITE_STATIC);
			sqlite3_bind_int(lpStmt, 4, data.Youxiaoqikaishi);
			sqlite3_bind_int(lpStmt, 5, data.Youxiaoqijieshu);
			sqlite3_bind_int(lpStmt, 6, data.Quanxianjibie);

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
bool AddGUANLIYUANCAOZUOJILU(tagGUANLIYUANCAOZUOJILU  data, string &strError)
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
			T_GUANLIYUANCAOZUOJILU						"("
			T_GUANLIYUANCAOZUOJILU_XUHAO				","
			T_GUANLIYUANCAOZUOJILU_YONGHUMING			","
			T_GUANLIYUANCAOZUOJILU_RIQI					","
			T_GUANLIYUANCAOZUOJILU_CAOZUOLEIBIE			","
			T_GUANLIYUANCAOZUOJILU_CAOZUONEIRONG		")"
			" VALUES(?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_text(lpStmt, 2, data.Yonghuming.c_str(), data.Yonghuming.size(), SQLITE_STATIC);
			sqlite3_bind_int64(lpStmt, 3, data.Riqi);
			sqlite3_bind_text(lpStmt, 4, data.Caozuoleibie.c_str(), data.Caozuoleibie.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 5, data.Caozuoneirong.c_str(), data.Caozuoneirong.size(), SQLITE_STATIC);

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
bool AddSHEBEIGUANLI(tagSHEBEIGUANLI  data, string &strError)
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
			T_SHEBEIGUANLI								"("
			T_SHEBEIGUANLI_XUHAO						","
			T_SHEBEIGUANLI_CHENGSHIBIANHAO				","
			T_SHEBEIGUANLI_JUBIANHAO					","
			T_SHEBEIGUANLI_SHIYONGDANWEIBIANHAO			","
			T_SHEBEIGUANLI_IP							","
			T_SHEBEIGUANLI_SHEBEICHANGJIA				","
			T_SHEBEIGUANLI_SHEBEIMINGCHENG				","
			T_SHEBEIGUANLI_SHEBEILEIXING				","
			T_SHEBEIGUANLI_JINGDU						","
			T_SHEBEIGUANLI_WEIDU						","
			T_SHEBEIGUANLI_CHUANGJIANSHIJIAN			")"
			" VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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

			if (data.Xuhao != 0)
				sqlite3_bind_int(lpStmt, 1, data.Xuhao);
			sqlite3_bind_int(lpStmt, 2, data.Chengshibianhao);
			sqlite3_bind_int(lpStmt, 3, data.Jubianhao);
			sqlite3_bind_int(lpStmt, 4, data.Shiyongdanweibianhao);
			sqlite3_bind_int(lpStmt, 5, data.IP);
			sqlite3_bind_text(lpStmt, 6, data.Shebeichangjia.c_str(), data.Shebeichangjia.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 7, data.Shebeimingcheng.c_str(), data.Shebeimingcheng.size(), SQLITE_STATIC);
			sqlite3_bind_text(lpStmt, 8, data.Shebeileixing.c_str(), data.Shebeileixing.size(), SQLITE_STATIC);
			sqlite3_bind_double(lpStmt, 9, data.Jingdu);
			sqlite3_bind_double(lpStmt, 10, data.Weidu);
			sqlite3_bind_int64(lpStmt, 11, data.Chuangjianshijian);

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
bool AddYINGSHEBIAO(tagYINGSHEBIAO  data, string &strError)
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
			T_YINGSHEBIAO						"("
			T_YINGSHEBIAO_BIANHAO				","
			T_YINGSHEBIAO_MINGCHENG				")"
			" VALUES(?, ?)"
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

			sqlite3_bind_int(lpStmt, 1, data.Bianhao);
			sqlite3_bind_text(lpStmt, 2, data.Mingcheng.c_str(), data.Mingcheng.size(), SQLITE_STATIC);

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