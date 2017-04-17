#pragma once

#include <vector>
#include <string>
using namespace std;

#include "SqliteDataDefine.h"


/*
	1. 每个属性与对应的值之间以 ： 号分隔
	2. 属性与属性之间以 , 号分隔
	3. 每行以 ; 号结尾
	4. 行与行之间无字符
	datastr Format:(实际没有换行，只是为了方便显示)

	propertyName1_0:propertyValue1_0,propertyName1_1:propertyValue1_1,propertyName1_2:propertyValue1_2,……;
	propertyName2_0:propertyValue2_0,propertyName2_1:propertyValue2_1,propertyName2_2:propertyValue2_2,……;
	propertyName3_0:propertyValue3_0,propertyName3_1:propertyValue3_1,propertyName3_2:propertyValue3_2,……;
*/
bool			QueryTable(string QuerySql, string &dataStr, string &strError);
bool			QueryVersion(string QuerySql, string &Bianhao, string &Banbenhao, string &Anzhuangbao, string &strError);

bool			AddTable(char* tableName, char* dataStr, int datalen, string &strError);
bool			AddVersion(char* Bianhao, char* Banbenhao, LPBYTE Anzhuangbao, int datalen, string &strError);
bool			ExcuteSql(char* sqlStr, string &strError);

bool			QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);
bool			AddZHIQIANSHUJU(tagZHIQIANSHUJU  data, string &strError);

bool			QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError);
bool			AddSHOUZHENGSHUJU(tagSHOUZHENGSHUJU  data, string &strError);

bool			QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError);
bool			AddQIANZHUSHUJU(tagQIANZHUSHUJU  data, string &strError);

bool			QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError);
bool			AddJIAOKUANSHUJU(tagJIAOKUANSHUJU  data, string &strError);

bool			QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError);
bool			AddCHAXUNSHUJU(tagCHAXUNSHUJU  data, string &strError);

bool			QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError);
bool			AddYUSHOULISHUJU(tagYUSHOULISHUJU  data, string &strError);

bool			QuerySHEBEIZHUANGTAI(string QuerySql, std::vector<tagSHEBEIZHUANGTAI> &lcArray, string &strError);
bool			AddSHEBEIZHUANGTAI(tagSHEBEIZHUANGTAI  data, string &strError);

bool			QuerySHEBEIYICHANGSHUJU(string QuerySql, std::vector<tagSHEBEIYICHANGSHUJU> &lcArray, string &strError);
bool			AddSHEBEIYICHANGSHUJU(tagSHEBEIYICHANGSHUJU  data, string &strError);

bool			QueryGUANLIYUAN(string QuerySql, std::vector<tagGUANLIYUAN> &lcArray, string &strError);
bool			AddGUANLIYUAN(tagGUANLIYUAN  data, string &strError);

bool			QueryGUANLIYUANCAOZUOJILU(string QuerySql, std::vector<tagGUANLIYUANCAOZUOJILU> &lcArray, string &strError);
bool			AddGUANLIYUANCAOZUOJILU(tagGUANLIYUANCAOZUOJILU  data, string &strError);

bool			QuerySHEBEIGUANLI(string QuerySql, std::vector<tagSHEBEIGUANLI> &lcArray, string &strError);
bool			AddSHEBEIGUANLI(tagSHEBEIGUANLI  data, string &strError);

bool			QueryYINGSHEBIAO(string QuerySql, std::vector<tagYINGSHEBIAO> &lcArray, string &strError);
bool			AddYINGSHEBIAO(tagYINGSHEBIAO  data, string &strError);




