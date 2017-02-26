// NetDll.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "WorkDll.h"
#include "Client.h"
#include "Server.h"

#include "SqliteData.h"

/***************************************Server*******************************************/
bool startServer(char *ip, int port)
{
	return CServer::GetInstance()->StartServer(ip, port);
}

bool stopServer()
{
	return CServer::GetInstance()->StopServer();
}
bool isServerStoped()
{
	return CServer::GetInstance()->ServerStoped();
}


/***************************************Client*******************************************/
bool startClient(char *ip, int port)
{
	return CClient::GetInstance()->StartClient(ip, port);
}

bool stopClient()
{
	return CClient::GetInstance()->StopClient();
}

bool isClientStoped()
{
	return CClient::GetInstance()->ClientStoped();
}

void queryTable(char* QuerySql, QueryTableCallBack callBack)
{
	string strError = "";
	string resultStr = "";
	resultStr.reserve(0x100000);
	CSqliteData::GetInstance()->QueryTable(QuerySql, resultStr, strError);

	if (callBack)
	{
		callBack((char*)resultStr.c_str());
	}
}

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

void addTable(char* tableName, char* dataStr, AddDataCallBack callBack)
{
	string strError = "";


	CSqliteData::GetInstance()->AddTable(tableName, dataStr, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
	
	return;

#pragma region fdfd
	//vector<string> rows;
	//split(dataStr, rows, ";");
	//for (int rowIndex = 0; rowIndex < rows.size(); ++rowIndex)
	//{
	//	string row = rows[rowIndex];
	//	if (row.length() > 0)
	//	{
	//		if (strcmp(tableName, T_ZHIQIANSHUJU) == 0)
	//		{
	//			tagZHIQIANSHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_YEWUBIANHAO) == 0)
	//					data.Yewubianhao = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_YUANZHENGJIANHAOMA) == 0)
	//					data.YuanZhengjianhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_XINGMING) == 0)
	//					data.Xingming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_QIANZHUZHONGLEI) == 0)
	//					data.Qianzhuzhonglei = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_ZHIKAZHUANGTAI) == 0)
	//					data.ZhikaZhuangtai = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_ZHENGJIANHAOMA) == 0)
	//					data.Zhengjianhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_JIEKOUFANHUIJIEGUO) == 0)
	//					data.Jiekoufanhuijieguo = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_ZHIQIANSHUJU_LIANXIDIANHUA) == 0)
	//					data.Lianxidianhua = keyvalue[1];
	//			}

	//			CSqliteData::GetInstance()->AddZHIQIANSHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_SHOUZHENGSHUJU) == 0)
	//		{
	//			tagSHOUZHENGSHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_ZHENGJIANLEIXING) == 0)
	//					data.Zhengjianleixing = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_ZHENGJIANHAOMA) == 0)
	//					data.Zhengjianhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_XINGMING) == 0)
	//					data.Xingming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_SHOULIBIANHAO) == 0)
	//					data.Shoulibianhao = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHOUZHENGSHUJU_SHIFOUJIAOFEI) == 0)
	//					data.Shifoujiaofei = atoi(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddSHOUZHENGSHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_QIANZHUSHUJU) == 0)
	//		{
	//			tagQIANZHUSHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_YUANZHENGJIANHAOMA) == 0)
	//					data.YuanZhengjianhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_XINGMING) == 0)
	//					data.Xingming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_XINGBIE) == 0)
	//					data.Xingbie = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_CHUSHENGRIQI) == 0)
	//					data.Chushengriqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_LIANXIDIANHUA) == 0)
	//					data.Lianxidianhua = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_YEWULEIXING) == 0)
	//					data.Yewuleixing = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_QIANZHUSHUJU_SHOULIREN) == 0)
	//					data.Shouliren = keyvalue[1].c_str();
	//			}
	//			CSqliteData::GetInstance()->AddQIANZHUSHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_JIAOKUANSHUJU) == 0)
	//		{
	//			tagJIAOKUANSHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_ZHISHOUDANWEIDAIMA) == 0)
	//					data.Zhishoudanweidaima = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_JIAOKUANTONGZHISHUHAOMA) == 0)
	//					data.Jiaokuantongzhishuhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_JIAOKUANRENXINGMING) == 0)
	//					data.Jiaokuanrenxingming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_YINGKOUKUANHEJI) == 0)
	//					data.Yingkoukuanheji = atof(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_JIAOKUANSHUJU_JIAOYIRIQI) == 0)
	//					data.Jiaoyiriqi = _atoi64(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddJIAOKUANSHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_CHAXUNSHUJU) == 0)
	//		{
	//			tagCHAXUNSHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_CHAXUNHAOMA) == 0)
	//					data.Chaxunhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_CHAXUNLEIXING) == 0)
	//					data.Chaxunleixing = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_SHIFOUCHAXUNCHENGGONG) == 0)
	//					data.Shifouchaxunchenggong = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_CHAXUNSHUJU_CHUANGJIANSHIJIAN) == 0)
	//					data.Chuangjianshijian = _atoi64(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddCHAXUNSHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_YUSHOULISHUJU) == 0)
	//		{
	//			tagYUSHOULISHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_YEWUBIANHAO) == 0)
	//					data.Yewubianhao = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_XINGMING) == 0)
	//					data.Xingming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_LIANXIDIANHUA) == 0)
	//					data.Lianxidianhua = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_CHUGUOSHIYOU) == 0)
	//					data.Chuguoshiyou = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_YUANZHENGJIANHAOMA) == 0)
	//					data.YuanZhengjianhaoma = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_QIANZHUZHONGLEI) == 0)
	//					data.Qianzhuzhonglei = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_XINGBIE) == 0)
	//					data.Xingbie = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_HUKOUSUOZAIDI) == 0)
	//					data.Hukousuozaidi = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_MINZU) == 0)
	//					data.Minzu = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_YUSHOULISHUJU_CHUANGJIANSHIJIAN) == 0)
	//					data.Chuangjianshijian = _atoi64(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddYUSHOULISHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_SHEBEIZHUANGTAI) == 0)
	//		{
	//			tagSHEBEIZHUANGTAI data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIZHUANGTAI_SHIFOUZAIXIAN) == 0)
	//					data.Shifouzaixian = atoi(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddSHEBEIZHUANGTAI(data, strError);
	//		}
	//		else if (strcmp(tableName, T_SHEBEIYICHANGSHUJU) == 0)
	//		{
	//			tagSHEBEIYICHANGSHUJU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_BENDIYEWU) == 0)
	//					data.Bendiyewu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_SHEBEIBAIFANGWEIZHI) == 0)
	//					data.Shebeibaifangweizhi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_YICHANGSHEJIMOKUAI) == 0)
	//					data.Yichangshejimokuai = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_YICHANGYUANYIN) == 0)
	//					data.Yichangyuanyin = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIYICHANGSHUJU_YICHANGXIANGXINEIRONG) == 0)
	//					data.Yichangxiangxineirong = keyvalue[1].c_str();
	//			}
	//			CSqliteData::GetInstance()->AddSHEBEIYICHANGSHUJU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_GUANLIYUAN) == 0)
	//		{
	//			tagGUANLIYUAN data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_GUANLIYUAN_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUAN_YONGHUMING) == 0)
	//					data.Yonghuming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUAN_MIMA) == 0)
	//					data.Mima = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUAN_YOUXIAOQIKAISHI) == 0)
	//					data.Youxiaoqikaishi = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUAN_YOUXIAOQIJIESHU) == 0)
	//					data.Youxiaoqijieshu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUAN_QUANXIANJIBIE) == 0)
	//					data.Quanxianjibie = atoi(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddGUANLIYUAN(data, strError);
	//		}
	//		else if (strcmp(tableName, T_GUANLIYUANCAOZUOJILU) == 0)
	//		{
	//			tagGUANLIYUANCAOZUOJILU data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_GUANLIYUANCAOZUOJILU_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUANCAOZUOJILU_YONGHUMING) == 0)
	//					data.Yonghuming = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUANCAOZUOJILU_RIQI) == 0)
	//					data.Riqi = _atoi64(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUANCAOZUOJILU_CAOZUOLEIBIE) == 0)
	//					data.Caozuoleibie = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_GUANLIYUANCAOZUOJILU_CAOZUONEIRONG) == 0)
	//					data.Caozuoneirong = keyvalue[1].c_str();
	//			}
	//			CSqliteData::GetInstance()->AddGUANLIYUANCAOZUOJILU(data, strError);
	//		}
	//		else if (strcmp(tableName, T_SHEBEIGUANLI) == 0)
	//		{
	//			tagSHEBEIGUANLI data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_XUHAO) == 0)
	//					data.Xuhao = 0;
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_CHENGSHIBIANHAO) == 0)
	//					data.Chengshibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_JUBIANHAO) == 0)
	//					data.Jubianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_SHIYONGDANWEIBIANHAO) == 0)
	//					data.Shiyongdanweibianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_IP) == 0)
	//					data.IP = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_SHEBEICHANGJIA) == 0)
	//					data.Shebeichangjia = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_SHEBEIMINGCHENG) == 0)
	//					data.Shebeimingcheng = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_SHEBEILEIXING) == 0)
	//					data.Shebeileixing = keyvalue[1].c_str();
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_JINGDU) == 0)
	//					data.Jingdu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_WEIDU) == 0)
	//					data.Weidu = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_SHEBEIGUANLI_CHUANGJIANSHIJIAN) == 0)
	//					data.Chuangjianshijian = _atoi64(keyvalue[1].c_str());
	//			}
	//			CSqliteData::GetInstance()->AddSHEBEIGUANLI(data, strError);
	//		}
	//		else if (strcmp(tableName, T_YINGSHEBIAO) == 0)
	//		{
	//			tagYINGSHEBIAO data;

	//			vector<string> cells;
	//			split(dataStr, cells, ",");
	//			for (int colIndex = 0; colIndex < cells.size(); ++colIndex)
	//			{
	//				string cell = cells[colIndex];
	//				vector<string> keyvalue;
	//				split(cell, keyvalue, ":");

	//				if (strcmp(keyvalue[0].c_str(), T_YINGSHEBIAO_BIANHAO) == 0)
	//					data.Bianhao = atoi(keyvalue[1].c_str());
	//				else if (strcmp(keyvalue[0].c_str(), T_YINGSHEBIAO_MINGCHENG) == 0)
	//					data.Mingcheng = keyvalue[1].c_str();
	//		
	//			}
	//			CSqliteData::GetInstance()->AddYINGSHEBIAO(data, strError);
	//		}
	//	}
	//}
#pragma endregion fdfd

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}

void addZHIQIANSHUJU(
	int 						Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*	  					Yewubianhao,
	char*	  					YuanZhengjianhaoma,
	char*	  					Xingming,
	int	  						Qianzhuzhonglei,
	int	  						ZhikaZhuangtai,
	char*	  					Zhengjianhaoma,
	char*	  					Jiekoufanhuijieguo,
	char*	  					Lianxidianhua,
	AddDataCallBack				callBack
	)
{
	tagZHIQIANSHUJU data;
	data.Xuhao									= Xuhao;
	data.Chengshibianhao						= Chengshibianhao;
	data.Jubianhao								= Jubianhao;
	data.Shiyongdanweibianhao					= Shiyongdanweibianhao;
	data.IP										= IP;
	data.Bendiyewu								= Bendiyewu;
	data.Shebeibaifangweizhi					= Shebeibaifangweizhi;
	data.Riqi									= Riqi;
	data.Yewubianhao							= Yewubianhao;
	data.YuanZhengjianhaoma						= YuanZhengjianhaoma;
	data.Xingming								= Xingming;
	data.Qianzhuzhonglei						= Qianzhuzhonglei;
	data.ZhikaZhuangtai							= ZhikaZhuangtai;
	data.Zhengjianhaoma							= Zhengjianhaoma;
	data.Jiekoufanhuijieguo						= Jiekoufanhuijieguo;
	data.Lianxidianhua							= Lianxidianhua;

	string strError = "";
	CSqliteData::GetInstance()->AddZHIQIANSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}

void    addSHOUZHENGSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	int							Zhengjianleixing,
	char*						Zhengjianhaoma,
	char*						Xingming,
	char*						Shoulibianhao,
	bool						Shifoujiaofei,
	AddDataCallBack				callBack
	)
{
	tagSHOUZHENGSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Zhengjianleixing			= Zhengjianleixing;
	data.Zhengjianhaoma				= Zhengjianhaoma;
	data.Xingming					= Xingming;
	data.Shoulibianhao				= Shoulibianhao;
	data.Shifoujiaofei				= Shifoujiaofei;

	string strError = "";
	CSqliteData::GetInstance()->AddSHOUZHENGSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addQIANZHUSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						YuanZhengjianhaoma,
	char*						Xingming,
	int							Xingbie,
	__int64						Chushengriqi,
	char*						Lianxidianhua,
	int							Yewuleixing,
	char*						Shouliren,
	AddDataCallBack				callBack
	)
{
	tagQIANZHUSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.YuanZhengjianhaoma			= YuanZhengjianhaoma;
	data.Xingming					= Xingming;
	data.Xingbie					= Xingbie;
	data.Chushengriqi				= Chushengriqi;
	data.Lianxidianhua				= Lianxidianhua;
	data.Yewuleixing				= Yewuleixing;
	data.Shouliren					= Shouliren;

	string strError = "";
	CSqliteData::GetInstance()->AddQIANZHUSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addJIAOKUANSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Zhishoudanweidaima,
	char*						Jiaokuantongzhishuhaoma,
	char*						Jiaokuanrenxingming,
	float						Yingkoukuanheji,
	__int64						Jiaoyiriqi,
	AddDataCallBack				callBack
	)
{
	tagJIAOKUANSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Zhishoudanweidaima			= Zhishoudanweidaima;
	data.Jiaokuantongzhishuhaoma	= Jiaokuantongzhishuhaoma;
	data.Jiaokuanrenxingming		= Jiaokuanrenxingming;
	data.Yingkoukuanheji			= Yingkoukuanheji;
	data.Jiaoyiriqi					= Jiaoyiriqi;

	string strError = "";
	CSqliteData::GetInstance()->AddJIAOKUANSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addCHAXUNSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Chaxunhaoma,
	char*						Chaxunleixing,
	bool						Shifouchaxunchenggong,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	)
{
	tagCHAXUNSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Chaxunhaoma				= Chaxunhaoma;
	data.Chaxunleixing				= Chaxunleixing;
	data.Shifouchaxunchenggong		= Shifouchaxunchenggong;
	data.Chuangjianshijian			= Chuangjianshijian;

	string strError = "";
	CSqliteData::GetInstance()->AddCHAXUNSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addYUSHOULISHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int		  					Shebeibaifangweizhi,
	__int64		  				Riqi,
	char*	  					Yewubianhao,
	char*	  					Xingming,
	char*	  					Lianxidianhua,
	char*	  					Chuguoshiyou,
	char*  						YuanZhengjianhaoma,
	int		  					Qianzhuzhonglei,
	int	  						Xingbie,
	char*	  					Hukousuozaidi,
	char*	  					Minzu,
	__int64  					Chuangjianshijian,
	AddDataCallBack				callBack
	)
{
	tagYUSHOULISHUJU data;
	data.Xuhao					= Xuhao;
	data.Chengshibianhao		= Chengshibianhao;
	data.Jubianhao				= Jubianhao;
	data.Shiyongdanweibianhao	= Shiyongdanweibianhao;
	data.IP						= IP;
	data.Bendiyewu				= Bendiyewu;
	data.Shebeibaifangweizhi	= Shebeibaifangweizhi;
	data.Riqi					= Riqi;
	data.Yewubianhao			= Yewubianhao;
	data.Xingming				= Xingming;
	data.Lianxidianhua			= Lianxidianhua;
	data.Chuguoshiyou			= Chuguoshiyou;
	data.YuanZhengjianhaoma		= YuanZhengjianhaoma;
	data.Qianzhuzhonglei		= Qianzhuzhonglei;
	data.Xingbie				= Xingbie;
	data.Hukousuozaidi			= Hukousuozaidi;
	data.Minzu					= Minzu;
	data.Chuangjianshijian		= Chuangjianshijian;

	string strError = "";
	CSqliteData::GetInstance()->AddYUSHOULISHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addSHEBEIZHUANGTAI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	bool						Shifouzaixian,
	AddDataCallBack				callBack
	)
{
	tagSHEBEIZHUANGTAI data;
	data.Xuhao					= Xuhao;
	data.Chengshibianhao		= Chengshibianhao;
	data.Jubianhao				= Jubianhao;
	data.Shiyongdanweibianhao	= Shiyongdanweibianhao;
	data.IP						= IP;
	data.Bendiyewu				= Bendiyewu;
	data.Shebeibaifangweizhi	= Shebeibaifangweizhi;
	data.Riqi					= Riqi;
	data.Shifouzaixian			= Shifouzaixian;

	string strError = "";
	CSqliteData::GetInstance()->AddSHEBEIZHUANGTAI(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addSHEBEIYICHANGSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Yichangshejimokuai,
	char*						Yichangyuanyin,
	char*						Yichangxiangxineirong,
	AddDataCallBack				callBack
	)
{
	tagSHEBEIYICHANGSHUJU data;
	data.Xuhao						= Xuhao;
	data.Chengshibianhao			= Chengshibianhao;
	data.Jubianhao					= Jubianhao;
	data.Shiyongdanweibianhao		= Shiyongdanweibianhao;
	data.IP							= IP;
	data.Bendiyewu					= Bendiyewu;
	data.Shebeibaifangweizhi		= Shebeibaifangweizhi;
	data.Riqi						= Riqi;
	data.Yichangshejimokuai			= Yichangshejimokuai;
	data.Yichangyuanyin				= Yichangyuanyin;
	data.Yichangxiangxineirong		= Yichangxiangxineirong;

	string strError = "";
	CSqliteData::GetInstance()->AddSHEBEIYICHANGSHUJU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addGUANLIYUAN(
	int  						Xuhao,
	char*  						Yonghuming,
	char*  						Mima,
	int  						Youxiaoqikaishi,
	int  						Youxiaoqijieshu,
	int  						Quanxianjibie,
	AddDataCallBack				callBack
	)
{
	tagGUANLIYUAN data;
	data.Xuhao					= Xuhao;
	data.Yonghuming				= Yonghuming;
	data.Mima					= Mima;
	data.Youxiaoqikaishi		= Youxiaoqikaishi;
	data.Youxiaoqijieshu		= Youxiaoqijieshu;
	data.Quanxianjibie			= Quanxianjibie;
	

	string strError = "";
	CSqliteData::GetInstance()->AddGUANLIYUAN(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addGUANLIYUANCAOZUOJILU(
	int  						Xuhao,
	char*  						Yonghuming,
	__int64  					Riqi,
	char*  						Caozuoleibie,
	char*  						Caozuoneirong,
	AddDataCallBack				callBack
	)
{
	tagGUANLIYUANCAOZUOJILU data;
	data.Xuhao					= Xuhao;
	data.Yonghuming				= Yonghuming;
	data.Riqi					= Riqi;
	data.Caozuoleibie			= Caozuoleibie;
	data.Caozuoneirong			= Caozuoneirong;

	string strError = "";
	CSqliteData::GetInstance()->AddGUANLIYUANCAOZUOJILU(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addSHEBEIGUANLI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	char*						Shebeichangjia,
	char*						Shebeimingcheng,
	char*						Shebeileixing,
	float						Jingdu,
	float						Weidu,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	)
{
	tagSHEBEIGUANLI data;
	data.Xuhao					= Xuhao;
	data.Chengshibianhao		= Chengshibianhao;
	data.Jubianhao				= Jubianhao;
	data.Shiyongdanweibianhao	= Shiyongdanweibianhao;
	data.IP						= IP;
	data.Shebeichangjia			= Shebeichangjia;
	data.Shebeimingcheng		= Shebeimingcheng;
	data.Shebeileixing			= Shebeileixing;
	data.Jingdu					= Jingdu;
	data.Weidu					= Weidu;
	data.Chuangjianshijian		= Chuangjianshijian;

	string strError = "";
	CSqliteData::GetInstance()->AddSHEBEIGUANLI(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
void    addYINGSHEBIAO(
	int							Bianhao,
	char*						Mingcheng,
	AddDataCallBack				callBack
	)
{
	tagYINGSHEBIAO data;
	data.Bianhao				= Bianhao;
	data.Mingcheng				= Mingcheng;

	string strError = "";
	CSqliteData::GetInstance()->AddYINGSHEBIAO(data, strError);

	if (callBack)
	{
		callBack((char*)strError.c_str());
	}
}
