#pragma once
class CSqliteData
{
public:
	~CSqliteData();
protected:
	CSqliteData();

	typedef bool(*_QueryTable)(string QuerySql, string &dataStr, string &strError);
	typedef bool(*_AddTable)(char* tableName, char* dataStr, string &strError);
	typedef bool(*_ExcuteSql)(char* sqlStr, string &strError);

	typedef bool(*_AddZHIQIANSHUJU)(tagZHIQIANSHUJU  data, string &strError);

	typedef bool(*_AddSHOUZHENGSHUJU)(tagSHOUZHENGSHUJU  data, string &strError);

	typedef bool(*_AddQIANZHUSHUJU)(tagQIANZHUSHUJU  data, string &strError);

	typedef bool(*_AddJIAOKUANSHUJU)(tagJIAOKUANSHUJU  data, string &strError);

	typedef bool(*_AddCHAXUNSHUJU)(tagCHAXUNSHUJU  data, string &strError);

	typedef bool(*_AddYUSHOULISHUJU)(tagYUSHOULISHUJU  data, string &strError);

	typedef bool(*_AddSHEBEIZHUANGTAI)(tagSHEBEIZHUANGTAI  data, string &strError);

	typedef bool(*_AddSHEBEIYICHANGSHUJU)(tagSHEBEIYICHANGSHUJU  data, string &strError);

	typedef bool(*_AddGUANLIYUAN)(tagGUANLIYUAN  data, string &strError);

	typedef bool(*_AddGUANLIYUANCAOZUOJILU)(tagGUANLIYUANCAOZUOJILU  data, string &strError);

	typedef bool(*_AddSHEBEIGUANLI)(tagSHEBEIGUANLI  data, string &strError);

	typedef bool(*_AddYINGSHEBIAO)(tagYINGSHEBIAO  data, string &strError);
	
	_QueryTable								m_QueryTableFunc;
	_AddTable								m_AddTableFunc;
	_ExcuteSql								m_ExcuteSqlFunc;

	_AddZHIQIANSHUJU						m_AddZHIQIANSHUJUFunc;
	_AddSHOUZHENGSHUJU						m_AddSHOUZHENGSHUJUFunc;
	_AddQIANZHUSHUJU						m_AddQIANZHUSHUJUFunc;
	_AddJIAOKUANSHUJU						m_AddJIAOKUANSHUJUFunc;
	_AddCHAXUNSHUJU							m_AddCHAXUNSHUJUFunc;
	_AddYUSHOULISHUJU						m_AddYUSHOULISHUJUFunc;
	_AddSHEBEIZHUANGTAI						m_AddSHEBEIZHUANGTAIFunc;
	_AddSHEBEIYICHANGSHUJU					m_AddSHEBEIYICHANGSHUJUFunc;
	_AddGUANLIYUAN							m_AddGUANLIYUANFunc;
	_AddGUANLIYUANCAOZUOJILU				m_AddGUANLIYUANCAOZUOJILUFunc;
	_AddSHEBEIGUANLI						m_AddSHEBEIGUANLIFunc;
	_AddYINGSHEBIAO							m_AddYINGSHEBIAOFunc;


	static CSqliteData*						m_pSqliteData;	//内部实例指针
public:
	static CSqliteData* 					GetInstance();
	static void 							ReleaseInstance();

	bool									QueryTable(string QuerySql, string &dataStr, string &strError);
	bool									AddTable(char* tableName, char* dataStr, string &strError);
	bool									ExcuteSql(char* sqlStr, string &strError);

	bool									AddZHIQIANSHUJU(tagZHIQIANSHUJU  data, string &strError);
											
	bool									AddSHOUZHENGSHUJU(tagSHOUZHENGSHUJU  data, string &strError);
											
	bool									AddQIANZHUSHUJU(tagQIANZHUSHUJU  data, string &strError);
											
	bool									AddJIAOKUANSHUJU(tagJIAOKUANSHUJU  data, string &strError);
											
	bool									AddCHAXUNSHUJU(tagCHAXUNSHUJU  data, string &strError);
											
	bool									AddYUSHOULISHUJU(tagYUSHOULISHUJU  data, string &strError);
											
	bool									AddSHEBEIZHUANGTAI(tagSHEBEIZHUANGTAI  data, string &strError);
											
	bool									AddSHEBEIYICHANGSHUJU(tagSHEBEIYICHANGSHUJU  data, string &strError);
											
	bool									AddGUANLIYUAN(tagGUANLIYUAN  data, string &strError);
											
	bool									AddGUANLIYUANCAOZUOJILU(tagGUANLIYUANCAOZUOJILU  data, string &strError);
											
	bool									AddSHEBEIGUANLI(tagSHEBEIGUANLI  data, string &strError);
											
	bool									AddYINGSHEBIAO(tagYINGSHEBIAO  data, string &strError);
};

