#pragma once
class CSqliteData
{
public:
	~CSqliteData();
protected:
	CSqliteData();

	typedef bool(*_QueryTable)(string QuerySql, string &resultStr, string &strError);

	typedef bool(*_QueryZHIQIANSHUJU)(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);
	typedef bool(*_AddZHIQIANSHUJU)(tagZHIQIANSHUJU  data, string &strError);

	typedef bool(*_QuerySHOUZHENGSHUJU)(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError);
	typedef bool(*_AddSHOUZHENGSHUJU)(tagSHOUZHENGSHUJU  data, string &strError);

	typedef bool(*_QueryQIANZHUSHUJU)(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError);
	typedef bool(*_AddQIANZHUSHUJU)(tagQIANZHUSHUJU  data, string &strError);

	typedef bool(*_QueryJIAOKUANSHUJU)(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError);
	typedef bool(*_AddJIAOKUANSHUJU)(tagJIAOKUANSHUJU  data, string &strError);

	typedef bool(*_QueryCHAXUNSHUJU)(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError);
	typedef bool(*_AddCHAXUNSHUJU)(tagCHAXUNSHUJU  data, string &strError);

	typedef bool(*_QueryYUSHOULISHUJU)(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError);
	typedef bool(*_AddYUSHOULISHUJU)(tagYUSHOULISHUJU  data, string &strError);

	typedef bool(*_QuerySHEBEIZHUANGTAI)(string QuerySql, std::vector<tagSHEBEIZHUANGTAI> &lcArray, string &strError);
	typedef bool(*_AddSHEBEIZHUANGTAI)(tagSHEBEIZHUANGTAI  data, string &strError);

	typedef bool(*_QuerySHEBEIYICHANGSHUJU)(string QuerySql, std::vector<tagSHEBEIYICHANGSHUJU> &lcArray, string &strError);
	typedef bool(*_AddSHEBEIYICHANGSHUJU)(tagSHEBEIYICHANGSHUJU  data, string &strError);

	typedef bool(*_QueryGUANLIYUAN)(string QuerySql, std::vector<tagGUANLIYUAN> &lcArray, string &strError);
	typedef bool(*_AddGUANLIYUAN)(tagGUANLIYUAN  data, string &strError);

	typedef bool(*_QueryGUANLIYUANCAOZUOJILU)(string QuerySql, std::vector<tagGUANLIYUANCAOZUOJILU> &lcArray, string &strError);
	typedef bool(*_AddGUANLIYUANCAOZUOJILU)(tagGUANLIYUANCAOZUOJILU  data, string &strError);

	typedef bool(*_QuerySHEBEIGUANLI)(string QuerySql, std::vector<tagSHEBEIGUANLI> &lcArray, string &strError);
	typedef bool(*_AddSHEBEIGUANLI)(tagSHEBEIGUANLI  data, string &strError);

	typedef bool(*_QueryYINGSHEBIAO)(string QuerySql, std::vector<tagYINGSHEBIAO> &lcArray, string &strError);
	typedef bool(*_AddYINGSHEBIAO)(tagYINGSHEBIAO  data, string &strError);
	

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

	_QueryTable								m_QueryTableFunc;

	_QueryZHIQIANSHUJU						m_QueryZHIQIANSHUJUFunc;
	_QuerySHOUZHENGSHUJU					m_QuerySHOUZHENGSHUJUFunc;
	_QueryQIANZHUSHUJU						m_QueryQIANZHUSHUJUFunc;
	_QueryJIAOKUANSHUJU						m_QueryJIAOKUANSHUJUFunc;
	_QueryCHAXUNSHUJU						m_QueryCHAXUNSHUJUFunc;
	_QueryYUSHOULISHUJU						m_QueryYUSHOULISHUJUFunc;
	_QuerySHEBEIZHUANGTAI					m_QuerySHEBEIZHUANGTAIFunc;
	_QuerySHEBEIYICHANGSHUJU				m_QuerySHEBEIYICHANGSHUJUFunc;
	_QueryGUANLIYUAN						m_QueryGUANLIYUANFunc;
	_QueryGUANLIYUANCAOZUOJILU				m_QueryGUANLIYUANCAOZUOJILUFunc;
	_QuerySHEBEIGUANLI						m_QuerySHEBEIGUANLIFunc;
	_QueryYINGSHEBIAO						m_QueryYINGSHEBIAOFunc;

	static CSqliteData*						m_pSqliteData;	//内部实例指针
public:
	static CSqliteData* 					GetInstance();
	static void 							ReleaseInstance();

	bool									QueryTable(string QuerySql, string &resultStr, string &strError);

	bool									QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);
	bool									AddZHIQIANSHUJU(tagZHIQIANSHUJU  data, string &strError);
											
	bool									QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError);
	bool									AddSHOUZHENGSHUJU(tagSHOUZHENGSHUJU  data, string &strError);
											
	bool									QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError);
	bool									AddQIANZHUSHUJU(tagQIANZHUSHUJU  data, string &strError);
											
	bool									QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError);
	bool									AddJIAOKUANSHUJU(tagJIAOKUANSHUJU  data, string &strError);
											
	bool									QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError);
	bool									AddCHAXUNSHUJU(tagCHAXUNSHUJU  data, string &strError);
											
	bool									QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError);
	bool									AddYUSHOULISHUJU(tagYUSHOULISHUJU  data, string &strError);
											
	bool									QuerySHEBEIZHUANGTAI(string QuerySql, std::vector<tagSHEBEIZHUANGTAI> &lcArray, string &strError);
	bool									AddSHEBEIZHUANGTAI(tagSHEBEIZHUANGTAI  data, string &strError);
											
	bool									QuerySHEBEIYICHANGSHUJU(string QuerySql, std::vector<tagSHEBEIYICHANGSHUJU> &lcArray, string &strError);
	bool									AddSHEBEIYICHANGSHUJU(tagSHEBEIYICHANGSHUJU  data, string &strError);
											
	bool									QueryGUANLIYUAN(string QuerySql, std::vector<tagGUANLIYUAN> &lcArray, string &strError);
	bool									AddGUANLIYUAN(tagGUANLIYUAN  data, string &strError);
											
	bool									QueryGUANLIYUANCAOZUOJILU(string QuerySql, std::vector<tagGUANLIYUANCAOZUOJILU> &lcArray, string &strError);
	bool									AddGUANLIYUANCAOZUOJILU(tagGUANLIYUANCAOZUOJILU  data, string &strError);
											
	bool									QuerySHEBEIGUANLI(string QuerySql, std::vector<tagSHEBEIGUANLI> &lcArray, string &strError);
	bool									AddSHEBEIGUANLI(tagSHEBEIGUANLI  data, string &strError);
											
	bool									QueryYINGSHEBIAO(string QuerySql, std::vector<tagYINGSHEBIAO> &lcArray, string &strError);
	bool									AddYINGSHEBIAO(tagYINGSHEBIAO  data, string &strError);

};

