#include "stdafx.h"
#include "SqliteData.h"


CSqliteData* CSqliteData::m_pSqliteData	= NULL;

CSqliteData::CSqliteData()
{
	HMODULE hDataBaseDll				= LoadLibrary(_T("database.dll"));

	m_QueryIDCARDAPPLYFunc				= (_QueryIDCARDAPPLY)GetProcAddress(hDataBaseDll, "QueryIDCARDAPPLY");
	m_AddIDCARDAPPLYFunc				= (_AddIDCARDAPPLY)GetProcAddress(hDataBaseDll, "AddIDCARDAPPLY");

	m_QueryZHIQIANSHUJUFunc				= (_QueryZHIQIANSHUJU)GetProcAddress(hDataBaseDll, "QueryZHIQIANSHUJU");

	m_QuerySHOUZHENGSHUJUFunc			= (_QuerySHOUZHENGSHUJU)GetProcAddress(hDataBaseDll, "QuerySHOUZHENGSHUJU");

	m_QueryQIANZHUSHUJUFunc				= (_QueryQIANZHUSHUJU)GetProcAddress(hDataBaseDll, "QueryQIANZHUSHUJU");

	m_QueryJIAOKUANSHUJUFunc			= (_QueryJIAOKUANSHUJU)GetProcAddress(hDataBaseDll, "QueryJIAOKUANSHUJU");

	m_QueryCHAXUNSHUJUFunc				= (_QueryCHAXUNSHUJU)GetProcAddress(hDataBaseDll, "QueryCHAXUNSHUJU");

	m_QueryYUSHOULISHUJUFunc			= (_QueryYUSHOULISHUJU)GetProcAddress(hDataBaseDll, "QueryYUSHOULISHUJU");

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

bool CSqliteData::QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError)
{
	if (m_QueryZHIQIANSHUJUFunc)
		return m_QueryZHIQIANSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError)
{
	if (m_QuerySHOUZHENGSHUJUFunc)
		return m_QuerySHOUZHENGSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError)
{
	if (m_QueryQIANZHUSHUJUFunc)
		return m_QueryQIANZHUSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError)
{
	if (m_QueryJIAOKUANSHUJUFunc)
		return m_QueryJIAOKUANSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError)
{
	if (m_QueryCHAXUNSHUJUFunc)
		return m_QueryCHAXUNSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError)
{
	if (m_QueryYUSHOULISHUJUFunc)
		return m_QueryYUSHOULISHUJUFunc(QuerySql, lcArray, strError);
	return false;
}
