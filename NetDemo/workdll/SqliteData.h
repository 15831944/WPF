#pragma once
class CSqliteData
{
public:
	~CSqliteData();
protected:
	CSqliteData();

	typedef bool(*_QueryIDCARDAPPLY)(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError);
	typedef bool(*_AddIDCARDAPPLY)(tagIDCARDAPPLY  station, string &strError);

	typedef bool(*_QueryZHIQIANSHUJU)(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);

	typedef bool(*_QuerySHOUZHENGSHUJU)(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError);

	typedef bool(*_QueryQIANZHUSHUJU)(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError);

	typedef bool(*_QueryJIAOKUANSHUJU)(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError);

	typedef bool(*_QueryCHAXUNSHUJU)(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError);

	typedef bool(*_QueryYUSHOULISHUJU)(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError);
	


	_QueryIDCARDAPPLY						m_QueryIDCARDAPPLYFunc;
	_AddIDCARDAPPLY							m_AddIDCARDAPPLYFunc;

	_QueryZHIQIANSHUJU						m_QueryZHIQIANSHUJUFunc;

	_QuerySHOUZHENGSHUJU					m_QuerySHOUZHENGSHUJUFunc;

	_QueryQIANZHUSHUJU						m_QueryQIANZHUSHUJUFunc;

	_QueryJIAOKUANSHUJU						m_QueryJIAOKUANSHUJUFunc;

	_QueryCHAXUNSHUJU						m_QueryCHAXUNSHUJUFunc;

	_QueryYUSHOULISHUJU						m_QueryYUSHOULISHUJUFunc;


	static CSqliteData*						m_pSqliteData;	//内部实例指针
public:
	static CSqliteData* 					GetInstance();
	static void 							ReleaseInstance();

	bool									QueryIDCARDAPPLY(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError);
	bool									AddIDCARDAPPLY(tagIDCARDAPPLY  station, string &strError);

	bool									QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);

	bool									QuerySHOUZHENGSHUJU(string QuerySql, std::vector<tagSHOUZHENGSHUJU> &lcArray, string &strError);

	bool									QueryQIANZHUSHUJU(string QuerySql, std::vector<tagQIANZHUSHUJU> &lcArray, string &strError);

	bool									QueryJIAOKUANSHUJU(string QuerySql, std::vector<tagJIAOKUANSHUJU> &lcArray, string &strError);

	bool									QueryCHAXUNSHUJU(string QuerySql, std::vector<tagCHAXUNSHUJU> &lcArray, string &strError);

	bool									QueryYUSHOULISHUJU(string QuerySql, std::vector<tagYUSHOULISHUJU> &lcArray, string &strError);

};

