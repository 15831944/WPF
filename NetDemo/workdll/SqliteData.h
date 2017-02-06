#pragma once
class CSqliteData
{
public:
	~CSqliteData();
protected:
	CSqliteData();

	typedef bool(*_QueryIDCARDAPPLY)(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError);
	typedef bool(*_AddIDCARDAPPLY)(tagIDCARDAPPLY  station, string &strError);

	_QueryIDCARDAPPLY						m_QueryIDCARDAPPLYFunc;
	_AddIDCARDAPPLY							m_AddIDCARDAPPLYFunc;


	static CSqliteData*						m_pSqliteData;	//内部实例指针
public:
	static CSqliteData* 					GetInstance();
	static void 							ReleaseInstance();

	bool									QueryIDCARDAPPLY(string QuerySql, std::vector<tagIDCARDAPPLY> &lcArray, string &strError);
	bool									AddIDCARDAPPLY(tagIDCARDAPPLY  station, string &strError);
};

