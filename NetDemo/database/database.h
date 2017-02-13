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
