#include "stdafx.h"
#include "SqliteData.h"


CSqliteData* CSqliteData::m_pSqliteData	= NULL;

CSqliteData::CSqliteData()
{
	HMODULE hDataBaseDll				= LoadLibrary(_T("database.dll"));

	m_QueryTableFunc					= (_QueryTable)GetProcAddress(hDataBaseDll, "QueryTable");
	m_AddTableFunc						= (_AddTable)GetProcAddress(hDataBaseDll, "AddTable");


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

bool CSqliteData::QueryTable(string QuerySql, string &dataStr, string &strError)
{
	if (m_QueryTableFunc)
		return m_QueryTableFunc(QuerySql, dataStr, strError);
	return false;
}

bool CSqliteData::AddTable(char* tableName, char* dataStr, string &strError)
{
	if (m_AddTableFunc)
		return m_AddTableFunc(tableName, dataStr, strError);
	return false;
}


bool CSqliteData::AddZHIQIANSHUJU(tagZHIQIANSHUJU data, string &strError)
{
	if (m_AddZHIQIANSHUJUFunc)
		return m_AddZHIQIANSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddSHOUZHENGSHUJU(tagSHOUZHENGSHUJU data, string &strError)
{
	if (m_AddSHOUZHENGSHUJUFunc)
		return m_AddSHOUZHENGSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddQIANZHUSHUJU(tagQIANZHUSHUJU data, string &strError)
{
	if (m_AddQIANZHUSHUJUFunc)
		return m_AddQIANZHUSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddJIAOKUANSHUJU(tagJIAOKUANSHUJU data, string &strError)
{
	if (m_AddJIAOKUANSHUJUFunc)
		return m_AddJIAOKUANSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddCHAXUNSHUJU(tagCHAXUNSHUJU data, string &strError)
{
	if (m_AddCHAXUNSHUJUFunc)
		return m_AddCHAXUNSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddYUSHOULISHUJU(tagYUSHOULISHUJU data, string &strError)
{
	if (m_AddYUSHOULISHUJUFunc)
		return m_AddYUSHOULISHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddSHEBEIZHUANGTAI(tagSHEBEIZHUANGTAI data, string &strError)
{
	if (m_AddSHEBEIZHUANGTAIFunc)
		return m_AddSHEBEIZHUANGTAIFunc(data, strError);
	return false;
}

bool CSqliteData::AddSHEBEIYICHANGSHUJU(tagSHEBEIYICHANGSHUJU data, string &strError)
{
	if (m_AddSHEBEIYICHANGSHUJUFunc)
		return m_AddSHEBEIYICHANGSHUJUFunc(data, strError);
	return false;
}

bool CSqliteData::AddGUANLIYUAN(tagGUANLIYUAN data, string &strError)
{
	if (m_AddGUANLIYUANFunc)
		return m_AddGUANLIYUANFunc(data, strError);
	return false;
}

bool CSqliteData::AddGUANLIYUANCAOZUOJILU(tagGUANLIYUANCAOZUOJILU data, string &strError)
{
	if (m_AddGUANLIYUANCAOZUOJILUFunc)
		return m_AddGUANLIYUANCAOZUOJILUFunc(data, strError);
	return false;
}

bool CSqliteData::AddSHEBEIGUANLI(tagSHEBEIGUANLI data, string &strError)
{
	if (m_AddSHEBEIGUANLIFunc)
		return m_AddSHEBEIGUANLIFunc(data, strError);
	return false;
}

bool CSqliteData::AddYINGSHEBIAO(tagYINGSHEBIAO data, string &strError)
{
	if (m_AddYINGSHEBIAOFunc)
		return m_AddYINGSHEBIAOFunc(data, strError);
	return false;
}
