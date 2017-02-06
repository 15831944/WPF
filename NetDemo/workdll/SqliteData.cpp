#include "stdafx.h"
#include "SqliteData.h"


CSqliteData* CSqliteData::m_pSqliteData	= NULL;

CSqliteData::CSqliteData()
{
	HMODULE hDataBaseDll				= LoadLibrary(_T("database.dll"));

	m_QueryIDCARDAPPLYFunc				= (_QueryIDCARDAPPLY)GetProcAddress(hDataBaseDll, "QueryIDCARDAPPLY");
	m_AddIDCARDAPPLYFunc				= (_AddIDCARDAPPLY)GetProcAddress(hDataBaseDll, "AddIDCARDAPPLY");
}


CSqliteData::~CSqliteData()
{
}

CSqliteData* CSqliteData::GetInstance()
{
	if (m_pSqliteData == NULL)
	{
		m_pSqliteData = new CSqliteData();
	}

	return m_pSqliteData;
}

void CSqliteData::ReleaseInstance()
{
	if (m_pSqliteData)
	{
		delete m_pSqliteData;
		m_pSqliteData = NULL;
	}
}

bool CSqliteData::QueryIDCARDAPPLY(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError)
{
	if (m_QueryIDCARDAPPLYFunc)
		return m_QueryIDCARDAPPLYFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddIDCARDAPPLY(tagIDCARDAPPLY station, string &strError)
{
	if (m_AddIDCARDAPPLYFunc)
		return m_AddIDCARDAPPLYFunc(station, strError);
	return false;
}
