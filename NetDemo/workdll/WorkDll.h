#pragma once


/***************************************Server*******************************************/
bool				startServer(char *ip, int port);
bool				stopServer();
bool				isServerStoped();
int					curServerConnections();


/***************************************Client*******************************************/
bool				startClient(char *ip, int port, bool bDevice);
bool				stopClient();
bool				isClientStoped();

typedef				void(__cdecl *QueryTableCallBack)(
					char*	  					dataStr,
					char*	  					errorStr
					);
void				queryTable(char* QuerySql, QueryTableCallBack callBack, bool bSync);
void				queryOnlieDevCnt(QueryTableCallBack callBack, bool bSync);


typedef				void(__cdecl *AddDataCallBack)(
	char*			strError
	);

void				addTable(char* tableName, char* dataStr, AddDataCallBack callBack, bool bSync);
