#pragma once

#include <vector>
#include <string>
using namespace std;

#include "SqliteDataDefine.h"

////tagIDCARDAPPLY
bool QueryIDCARDAPPLY(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError);
bool AddIDCARDAPPLY(tagIDCARDAPPLY  station, string &strError);

bool QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);

bool QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError);

bool QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError);

bool QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError);

bool QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError);

bool QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError);

