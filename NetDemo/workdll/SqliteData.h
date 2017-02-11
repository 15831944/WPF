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

	_QueryIDCARDAPPLY						m_QueryIDCARDAPPLYFunc;
	_AddIDCARDAPPLY							m_AddIDCARDAPPLYFunc;

	_QueryZHIQIANSHUJU						m_QueryZHIQIANSHUJUFunc;

	static CSqliteData*						m_pSqliteData;	//内部实例指针
public:
	static CSqliteData* 					GetInstance();
	static void 							ReleaseInstance();

	bool									QueryIDCARDAPPLY(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError);
	bool									AddIDCARDAPPLY(tagIDCARDAPPLY  station, string &strError);

	bool									QueryZHIQIANSHUJU(string QuerySql, std::vector<tagZHIQIANSHUJU> &lcArray, string &strError);
};

