#pragma once


/***************************************Server*******************************************/
bool				startServer(char *ip, int port);
bool				stopServer();
bool				isServerStoped();



/***************************************Client*******************************************/
bool				startClient(char *ip, int port);
bool				stopClient();
bool				isClientStoped();


typedef				void(__cdecl *QueryIDCARDAPPLYCallBack)(
					char*  			name,
					char*  			gender,
					char*  			Nation,
					char*  			Birthday,
					char*  			Address,
					char*  			IdNumber,
					char*  			SigDepart,
					char*  			SLH,
					LPBYTE  		fpData,
					int				fpDataSize,
					LPBYTE  		fpFeature,
					int				fpFeatureSize,
					LPBYTE  		XCZP,
					int				XCZPSize,
					char*  			XZQH,
					char*  			sannerId,
					char*  			scannerName,
					bool			legal,
					char*  			operatorID,
					char*  			operatorName,
					char*  			opDate
					);
void				queryIDCARDAPPLY(char* querySqlStr, QueryIDCARDAPPLYCallBack callBack);