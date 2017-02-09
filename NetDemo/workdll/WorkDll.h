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
					char*  					name,
					char*  					gender,
					char*  					Nation,
					char*  					Birthday,
					char*  					Address,
					char*  					IdNumber,
					char*  					SigDepart,
					char*  					SLH,
					LPBYTE  				fpData,
					int						fpDataSize,
					LPBYTE  				fpFeature,
					int						fpFeatureSize,
					LPBYTE  				XCZP,
					int						XCZPSize,
					char*  					XZQH,
					char*  					sannerId,
					char*  					scannerName,
					bool					legal,
					char*  					operatorID,
					char*  					operatorName,
					char*  					opDate
					);
void				queryIDCARDAPPLY(char* querySqlStr, QueryIDCARDAPPLYCallBack callBack);

typedef				void(__cdecl *QueryONLINESTATUSCallBack)(
					char*  					machineId,
					char*  					machineName,
					char*  					machineIP,
					char*  					machineLongi,
					char*  					machineLat,
					char*  					currentBusiness,
					char*  					businessStartTime,
					char*  					businessEndTime,
					bool  					businessDone
					);
void				queryONLINESTATUS(char* querySqlStr, QueryONLINESTATUSCallBack callBack);

typedef				void(__cdecl *QuerySHULIANGHUIZONGCallBack)(
					int  					Xuhao,
					int  					Shiyongdanwei,
					int  					Shebeizongshuliang,
					int  					Qiyongshebei,
					int  					Yuyueyewu,
					int  					Yushouliyewu,
					int  					Jiaofeiyewu,
					int  					Chaxunyewu,
					int		  				Shebeishouzheng,
					int		  				Xuqianyewu,
					int		  				Benshitongxingzheng,
					int		  				Dianzitongxingzheng,
					int		  				Tongxingzhengzhika,
					int		  				Lidengkequ,
					int		  				Feilidengkequ
					);
void				querySHULIANGHUIZONG(char* querySqlStr, QuerySHULIANGHUIZONGCallBack callBack);

typedef				void(__cdecl *QueryXIANGXITONGJICallBack)(
					int  					Xuhao,
					int  					Nian,
					int  					Yue,
					int  					Ri,
					int  					Xiaoshi,
					int  					Fenzhong,
					int  					Shiyongdanwei,
					int  					Qiyongshebei,
					int		  				Yuyueyewu,
					int		  				Yushouliyewu,
					int		  				Jiaofeiyewu,
					int		  				Chaxunyewu,
					int		  				Shebeishouzheng,
					int		  				Xuqianyewu,
					int		  				Benshitongxingzheng,
					int		  				Dianzitongxingzheng,
					int		  				Tongxingzhengzhika,
					int		  				Lidengkequ,
					int		  				Feilidengkequ
					);
void				queryXIANGXITONGJI(char* querySqlStr, QueryXIANGXITONGJICallBack callBack);

typedef				void(__cdecl *QueryZHIQIANSHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					ShebeiIP,
					char*  					Yewubianhao,
					char*  					YuanZhengjianhaoma,
					char*  					Xingming,
					char*  					Qianzhuzhonglei,
					char*  					ZhikaZhuangtai,
					char*		  			Zhengjianhaoma,
					char*		  			Jiekoufanhuijieguo,
					char*		  			Lianxidianhua
					);
void				queryZHIQIANSHUJU(char* querySqlStr, QueryZHIQIANSHUJUCallBack callBack);

typedef				void(__cdecl *QuerySHOUZHENGSHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					ShebeiIP,
					char*  					Zhengjianleixing,
					char*  					Zhengjianhaoma,
					char*  					Xingming,
					char*  					Shoulibianhao,
					char*  					Shifoujiaofei
					);
void				querySHOUZHENGSHUJU(char* querySqlStr, QuerySHOUZHENGSHUJUCallBack callBack);
typedef				void(__cdecl *QueryQIANZHUSHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					ShebeiIP,
					char*  					YuanZhengjianhaoma,
					char*  					Xingming,
					char*  					Xingbie,
					char*  					Chushengriqi,
					char*  					Lianxidianhua,
					char*  					Yewuleixing,
					char*  					Shouliren
					);
void				queryQIANZHUSHUJU(char* querySqlStr, QueryQIANZHUSHUJUCallBack callBack);
typedef				void(__cdecl *QueryJIAOKUANSHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					ShebeiIP,
					char*  					Zhishoudanweidaima,
					char*  					Jiaokuantongzhishuhaoma,
					char*  					Jiaokuanrenxingming,
					float  					Yingkoukuanheji,
					char*  					Jiaoyiriqi
					);
void				queryJIAOKUANSHUJU(char* querySqlStr, QueryJIAOKUANSHUJUCallBack callBack);
typedef				void(__cdecl *QueryCHAXUNSHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					ShebeiIP,
					char*  					Chaxunhaoma,
					char*  					Chaxunleixing,
					bool  					Shifouchaxunchenggong
					);
void				queryCHAXUNSHUJU(char* querySqlStr, QueryCHAXUNSHUJUCallBack callBack);
typedef				void(__cdecl *QueryYUSHOULISHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					ShebeiIP,
					char*  					Yewubianhao,
					char*  					Xingming,
					char*  					Lianxidianhua,
					char*  					Chuguoshiyou,
					char*  					YuanZhengjianhaoma,
					char*  					Qianzhuzhonglei,
					char*  					Xingbie,
					char*  					Hukousuozaidi,
					char*  					Minzu
					);
void				queryYUSHOULISHUJU(char* querySqlStr, QueryYUSHOULISHUJUCallBack callBack);

typedef				void(__cdecl *QuerySHEBEIYICHANGSHUJUCallBack)(
					int  					Xuhao,
					char*  					Riqi,
					char*  					Shiyongdanwei,
					char*  					Yichangshejimokuai,
					char*  					Yichangyuanyin,
					char*  					Yichangxiangxineirong
					);
void				querySHEBEIYICHANGSHUJU(char* querySqlStr, QuerySHEBEIYICHANGSHUJUCallBack callBack);
typedef				void(__cdecl *QueryGUANLIYUANCallBack)(
					int  					Xuhao,
					char*  					Yonghuming,
					char*  					Mima,
					char*  					Youxiaoqi,
					int  					Quanxianjibie
					);
void				queryGUANLIYUAN(char* querySqlStr, QueryGUANLIYUANCallBack callBack);
typedef				void(__cdecl *QueryGUANLIYUANCAOZUOJILUCallBack)(
					int  					Xuhao,
					char*  					Yonghuming,
					char*  					Riqi,
					char*  					Caozuoleibie,
					char*  					Caozuoneirong
					);
void				queryGUANLIYUANCAOZUOJILU(char* querySqlStr, QueryGUANLIYUANCAOZUOJILUCallBack callBack);
typedef				void(__cdecl *QuerySHEBEIGUANLICallBack)(
					int  					Xuhao,
					char*  					Sheng,
					char*  					Shi,
					char*  					Qu,
					char*  					Shiyongdanwei,
					char*  					IP,
					char*  					Shebeileixing,
					char*  					Jingdu,
					char*  					Weidu,
					char*  					Chuangjianshijian
					);
void				querySHEBEIGUANLI(char* querySqlStr, QuerySHEBEIGUANLICallBack callBack);
