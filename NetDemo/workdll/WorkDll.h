#pragma once


/***************************************Server*******************************************/
bool				startServer(char *ip, int port);
bool				stopServer();
bool				isServerStoped();



/***************************************Client*******************************************/
bool				startClient(char *ip, int port);
bool				stopClient();
bool				isClientStoped();

typedef				void(__cdecl *QueryTableCallBack)(
					char*	  					dataStr
					);
void				queryTable(char* QuerySql, QueryTableCallBack callBack);


typedef				void(__cdecl *AddDataCallBack)(
	char*			strError
	);

void				addTable(char* tableName, char* dataStr, AddDataCallBack callBack);
