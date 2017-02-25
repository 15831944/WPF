#include "stdafx.h"
#include "SqliteData.h"


CSqliteData* CSqliteData::m_pSqliteData	= NULL;

CSqliteData::CSqliteData()
{
	HMODULE hDataBaseDll				= LoadLibrary(_T("database.dll"));

	m_QueryTableFunc					= (_QueryTable)GetProcAddress(hDataBaseDll, "QueryTable");

	m_QueryZHIQIANSHUJUFunc				= (_QueryZHIQIANSHUJU)GetProcAddress(hDataBaseDll, "QueryZHIQIANSHUJU");
	m_QuerySHOUZHENGSHUJUFunc			= (_QuerySHOUZHENGSHUJU)GetProcAddress(hDataBaseDll, "QuerySHOUZHENGSHUJU");
	m_QueryQIANZHUSHUJUFunc				= (_QueryQIANZHUSHUJU)GetProcAddress(hDataBaseDll, "QueryQIANZHUSHUJU");
	m_QueryJIAOKUANSHUJUFunc			= (_QueryJIAOKUANSHUJU)GetProcAddress(hDataBaseDll, "QueryJIAOKUANSHUJU");
	m_QueryCHAXUNSHUJUFunc				= (_QueryCHAXUNSHUJU)GetProcAddress(hDataBaseDll, "QueryCHAXUNSHUJU");
	m_QueryYUSHOULISHUJUFunc			= (_QueryYUSHOULISHUJU)GetProcAddress(hDataBaseDll, "QueryYUSHOULISHUJU");
	m_QuerySHEBEIZHUANGTAIFunc			= (_QuerySHEBEIZHUANGTAI)GetProcAddress(hDataBaseDll, "QuerySHEBEIZHUANGTAI");
	m_QuerySHEBEIYICHANGSHUJUFunc		= (_QuerySHEBEIYICHANGSHUJU)GetProcAddress(hDataBaseDll, "QuerySHEBEIYICHANGSHUJU");
	m_QueryGUANLIYUANFunc				= (_QueryGUANLIYUAN)GetProcAddress(hDataBaseDll, "QueryGUANLIYUAN");
	m_QueryGUANLIYUANCAOZUOJILUFunc		= (_QueryGUANLIYUANCAOZUOJILU)GetProcAddress(hDataBaseDll, "QueryGUANLIYUANCAOZUOJILU");
	m_QuerySHEBEIGUANLIFunc				= (_QuerySHEBEIGUANLI)GetProcAddress(hDataBaseDll, "QuerySHEBEIGUANLI");
	m_QueryYINGSHEBIAOFunc				= (_QueryYINGSHEBIAO)GetProcAddress(hDataBaseDll, "QueryYINGSHEBIAO");



	m_AddZHIQIANSHUJUFunc				= (_AddZHIQIANSHUJU)GetProcAddress(hDataBaseDll, "AddZHIQIANSHUJU");
	m_AddSHOUZHENGSHUJUFunc				= (_AddSHOUZHENGSHUJU)GetProcAddress(hDataBaseDll, "AddSHOUZHENGSHUJU");
	m_AddQIANZHUSHUJUFunc				= (_AddQIANZHUSHUJU)GetProcAddress(hDataBaseDll, "AddQIANZHUSHUJU");
	m_AddJIAOKUANSHUJUFunc				= (_AddJIAOKUANSHUJU)GetProcAddress(hDataBaseDll, "AddJIAOKUANSHUJU");
	m_AddCHAXUNSHUJUFunc				= (_AddCHAXUNSHUJU)GetProcAddress(hDataBaseDll, "AddCHAXUNSHUJU");
	m_AddYUSHOULISHUJUFunc				= (_AddYUSHOULISHUJU)GetProcAddress(hDataBaseDll, "AddYUSHOULISHUJU");
	m_AddSHEBEIZHUANGTAIFunc			= (_AddSHEBEIZHUANGTAI)GetProcAddress(hDataBaseDll, "AddSHEBEIZHUANGTAI");
	m_AddSHEBEIYICHANGSHUJUFunc			= (_AddSHEBEIYICHANGSHUJU)GetProcAddress(hDataBaseDll, "AddSHEBEIYICHANGSHUJU");
	m_AddGUANLIYUANFunc					= (_AddGUANLIYUAN)GetProcAddress(hDataBaseDll, "AddGUANLIYUAN");
	m_AddGUANLIYUANCAOZUOJILUFunc		= (_AddGUANLIYUANCAOZUOJILU)GetProcAddress(hDataBaseDll, "AddGUANLIYUANCAOZUOJILU");
	m_AddSHEBEIGUANLIFunc				= (_AddSHEBEIGUANLI)GetProcAddress(hDataBaseDll, "AddSHEBEIGUANLI");
	m_AddYINGSHEBIAOFunc				= (_AddYINGSHEBIAO)GetProcAddress(hDataBaseDll, "AddYINGSHEBIAO");
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

bool CSqliteData::QueryTable(string QuerySql, string &resultStr, string &strError)
{
	if (m_QueryTableFunc)
		return m_QueryTableFunc(QuerySql, resultStr, strError);
	return false;
}

bool CSqliteData::QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError)
{
	if (m_QueryZHIQIANSHUJUFunc)
		return m_QueryZHIQIANSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddZHIQIANSHUJU(tagZHIQIANSHUJU data, string &strError)
{
	if (m_AddZHIQIANSHUJUFunc)
		return m_AddZHIQIANSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError)
{
	if (m_QuerySHOUZHENGSHUJUFunc)
		return m_QuerySHOUZHENGSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddSHOUZHENGSHUJU(tagSHOUZHENGSHUJU data, string &strError)
{
	if (m_AddSHOUZHENGSHUJUFunc)
		return m_AddSHOUZHENGSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError)
{
	if (m_QueryQIANZHUSHUJUFunc)
		return m_QueryQIANZHUSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddQIANZHUSHUJU(tagQIANZHUSHUJU data, string &strError)
{
	if (m_AddQIANZHUSHUJUFunc)
		return m_AddQIANZHUSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError)
{
	if (m_QueryJIAOKUANSHUJUFunc)
		return m_QueryJIAOKUANSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddJIAOKUANSHUJU(tagJIAOKUANSHUJU data, string &strError)
{
	if (m_AddJIAOKUANSHUJUFunc)
		return m_AddJIAOKUANSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError)
{
	if (m_QueryCHAXUNSHUJUFunc)
		return m_QueryCHAXUNSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddCHAXUNSHUJU(tagCHAXUNSHUJU data, string &strError)
{
	if (m_AddCHAXUNSHUJUFunc)
		return m_AddCHAXUNSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError)
{
	if (m_QueryYUSHOULISHUJUFunc)
		return m_QueryYUSHOULISHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddYUSHOULISHUJU(tagYUSHOULISHUJU data, string &strError)
{
	if (m_AddYUSHOULISHUJUFunc)
		return m_AddYUSHOULISHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QuerySHEBEIZHUANGTAI(string QuerySql, std::vector<tagSHEBEIZHUANGTAI> &lcArray, string &strError)
{
	if (m_QuerySHEBEIZHUANGTAIFunc)
		return m_QuerySHEBEIZHUANGTAIFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddSHEBEIZHUANGTAI(tagSHEBEIZHUANGTAI data, string &strError)
{
	if (m_AddSHEBEIZHUANGTAIFunc)
		return m_AddSHEBEIZHUANGTAIFunc(data, strError);
	return false;
}

bool CSqliteData::QuerySHEBEIYICHANGSHUJU(string QuerySql, std::vector<tagSHEBEIYICHANGSHUJU> &lcArray, string &strError)
{
	if (m_QuerySHEBEIYICHANGSHUJUFunc)
		return m_QuerySHEBEIYICHANGSHUJUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddSHEBEIYICHANGSHUJU(tagSHEBEIYICHANGSHUJU data, string &strError)
{
	if (m_AddSHEBEIYICHANGSHUJUFunc)
		return m_AddSHEBEIYICHANGSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::QueryGUANLIYUAN(string QuerySql, std::vector<tagGUANLIYUAN> &lcArray, string &strError)
{
	if (m_QueryGUANLIYUANFunc)
		return m_QueryGUANLIYUANFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddGUANLIYUAN(tagGUANLIYUAN data, string &strError)
{
	if (m_AddGUANLIYUANFunc)
		return m_AddGUANLIYUANFunc(data, strError);
	return false;
}

bool CSqliteData::QueryGUANLIYUANCAOZUOJILU(string QuerySql, std::vector<tagGUANLIYUANCAOZUOJILU> &lcArray, string &strError)
{
	if (m_QueryGUANLIYUANCAOZUOJILUFunc)
		return m_QueryGUANLIYUANCAOZUOJILUFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddGUANLIYUANCAOZUOJILU(tagGUANLIYUANCAOZUOJILU data, string &strError)
{
	if (m_AddGUANLIYUANCAOZUOJILUFunc)
		return m_AddGUANLIYUANCAOZUOJILUFunc(data, strError);
	return false;
}

bool CSqliteData::QuerySHEBEIGUANLI(string QuerySql, std::vector<tagSHEBEIGUANLI> &lcArray, string &strError)
{
	if (m_QuerySHEBEIGUANLIFunc)
		return m_QuerySHEBEIGUANLIFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddSHEBEIGUANLI(tagSHEBEIGUANLI data, string &strError)
{
	if (m_AddSHEBEIGUANLIFunc)
		return m_AddSHEBEIGUANLIFunc(data, strError);
	return false;
}

bool CSqliteData::QueryYINGSHEBIAO(string QuerySql, std::vector<tagYINGSHEBIAO> &lcArray, string &strError)
{
	if (m_QueryYINGSHEBIAOFunc)
		return m_QueryYINGSHEBIAOFunc(QuerySql, lcArray, strError);
	return false;
}

bool CSqliteData::AddYINGSHEBIAO(tagYINGSHEBIAO data, string &strError)
{
	if (m_AddYINGSHEBIAOFunc)
		return m_AddYINGSHEBIAOFunc(data, strError);
	return false;
}
