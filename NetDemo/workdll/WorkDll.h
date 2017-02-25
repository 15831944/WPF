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
					char*	  					resultStr
					);
void				queryTable(char* QuerySql, QueryTableCallBack callBack);

typedef				void(__cdecl *QueryZHIQIANSHUJUCallBack)(
					int 						Xuhao,
					int							Chengshibianhao,
					int							Jubianhao,
					int							Shiyongdanweibianhao,
					int							IP,
					bool						Bendiyewu,
					int							Shebeibaifangweizhi,
					__int64						Riqi,
					char*	  					Yewubianhao,
					char*	  					YuanZhengjianhaoma,
					char*	  					Xingming,
					int	  						Qianzhuzhonglei,
					int	  						ZhikaZhuangtai,
					char*	  					Zhengjianhaoma,
					char*	  					Jiekoufanhuijieguo,
					char*	  					Lianxidianhua
					);
void				queryZHIQIANSHUJU(char* querySqlStr, QueryZHIQIANSHUJUCallBack callBack);

typedef				void(__cdecl *QuerySHOUZHENGSHUJUCallBack)(
					int							Xuhao,					
					int							Chengshibianhao,		
					int							Jubianhao,				
					int							Shiyongdanweibianhao,	
					int							IP,						
					bool						Bendiyewu,				
					int							Shebeibaifangweizhi,	
					__int64						Riqi,
					int							Zhengjianleixing,		
					char*						Zhengjianhaoma,			
					char*						Xingming,				
					char*						Shoulibianhao,			
					bool						Shifoujiaofei		
					);
void				querySHOUZHENGSHUJU(char* querySqlStr, QuerySHOUZHENGSHUJUCallBack callBack);
typedef				void(__cdecl *QueryQIANZHUSHUJUCallBack)(
					int							Xuhao,
					int							Chengshibianhao,
					int							Jubianhao,
					int							Shiyongdanweibianhao,
					int							IP,
					bool						Bendiyewu,
					int							Shebeibaifangweizhi,
					__int64						Riqi,
					char*						YuanZhengjianhaoma,
					char*						Xingming,
					int							Xingbie,
					__int64						Chushengriqi,
					char*						Lianxidianhua,
					int							Yewuleixing,
					char*						Shouliren
					);
void				queryQIANZHUSHUJU(char* querySqlStr, QueryQIANZHUSHUJUCallBack callBack);
typedef				void(__cdecl *QueryJIAOKUANSHUJUCallBack)(
					int							Xuhao,
					int							Chengshibianhao,
					int							Jubianhao,
					int							Shiyongdanweibianhao,
					int							IP,
					bool						Bendiyewu,
					int							Shebeibaifangweizhi,
					__int64						Riqi,
					char*						Zhishoudanweidaima,
					char*						Jiaokuantongzhishuhaoma,
					char*						Jiaokuanrenxingming,
					float						Yingkoukuanheji,
					__int64						Jiaoyiriqi
					);
void				queryJIAOKUANSHUJU(char* querySqlStr, QueryJIAOKUANSHUJUCallBack callBack);
typedef				void(__cdecl *QueryCHAXUNSHUJUCallBack)(
					int							Xuhao,
					int		  					Chengshibianhao,
					int		  					Jubianhao,
					int		  					Shiyongdanweibianhao,
					int		  					IP,
					bool						Bendiyewu,
					int							Shebeibaifangweizhi,
					__int64						Riqi,
					char*						Chaxunhaoma,
					char*						Chaxunleixing,
					bool						Shifouchaxunchenggong,
					__int64						Chuangjianshijian
					);
void				queryCHAXUNSHUJU(char* querySqlStr, QueryCHAXUNSHUJUCallBack callBack);
typedef				void(__cdecl *QueryYUSHOULISHUJUCallBack)(
					int							Xuhao,
					int		  					Chengshibianhao,
					int		  					Jubianhao,
					int		  					Shiyongdanweibianhao,
					int		  					IP,
					bool	  					Bendiyewu,
					int		  					Shebeibaifangweizhi,
					__int64		  				Riqi,
					char*	  					Yewubianhao,
					char*	  					Xingming,
					char*	  					Lianxidianhua,
					char*	  					Chuguoshiyou,
					char*  						YuanZhengjianhaoma,
					int		  					Qianzhuzhonglei,
					int	  						Xingbie,
					char*	  					Hukousuozaidi,
					char*	  					Minzu,
					__int64  					Chuangjianshijian
					);
void				queryYUSHOULISHUJU(char* querySqlStr, QueryYUSHOULISHUJUCallBack callBack);
typedef				void(__cdecl *QuerySHEBEIZHUANGTAICallBack)(
					int							Xuhao,
					int							Chengshibianhao,
					int							Jubianhao,
					int							Shiyongdanweibianhao,
					int							IP,
					bool						Bendiyewu,
					int							Shebeibaifangweizhi,
					__int64						Riqi,
					bool						Shifouzaixian
					);
void				querySHEBEIZHUANGTAI(char* querySqlStr, QuerySHEBEIZHUANGTAICallBack callBack);
typedef				void(__cdecl *QuerySHEBEIYICHANGSHUJUCallBack)(
					int							Xuhao,
					int		  					Chengshibianhao,
					int		  					Jubianhao,
					int		  					Shiyongdanweibianhao,
					int		  					IP,
					bool	  					Bendiyewu,
					int							Shebeibaifangweizhi,
					__int64						Riqi,
					char*						Yichangshejimokuai,
					char*						Yichangyuanyin,
					char*						Yichangxiangxineirong
					);
void				querySHEBEIYICHANGSHUJU(char* querySqlStr, QuerySHEBEIYICHANGSHUJUCallBack callBack);
typedef				void(__cdecl *QueryGUANLIYUANCallBack)(
					int  						Xuhao,
					char*  						Yonghuming,
					char*  						Mima,
					int  						Youxiaoqikaishi,
					int  						Youxiaoqijieshu,
					int  						Quanxianjibie
					);
void				queryGUANLIYUAN(char* querySqlStr, QueryGUANLIYUANCallBack callBack);
typedef				void(__cdecl *QueryGUANLIYUANCAOZUOJILUCallBack)(
					int  						Xuhao,
					char*  						Yonghuming,
					__int64  					Riqi,
					char*  						Caozuoleibie,
					char*  						Caozuoneirong
					);
void				queryGUANLIYUANCAOZUOJILU(char* querySqlStr, QueryGUANLIYUANCAOZUOJILUCallBack callBack);
typedef				void(__cdecl *QuerySHEBEIGUANLICallBack)(
					int							Xuhao,
					int							Chengshibianhao,
					int							Jubianhao,
					int							Shiyongdanweibianhao,
					int							IP,
					char*						Shebeichangjia,
					char*						Shebeimingcheng,
					char*						Shebeileixing,
					float						Jingdu,
					float						Weidu,
					__int64						Chuangjianshijian
					);
void				querySHEBEIGUANLI(char* querySqlStr, QuerySHEBEIGUANLICallBack callBack);
typedef				void(__cdecl *QueryYINGSHEBIAOCallBack)(
					int							Bianhao,
					char*						Mingcheng
					);
void				queryYINGSHEBIAO(char* querySqlStr, QueryYINGSHEBIAOCallBack callBack);

typedef				void(__cdecl *AddDataCallBack)(
	char*			strError
	);

void addZHIQIANSHUJU(
	int 						Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*	  					Yewubianhao,
	char*	  					YuanZhengjianhaoma,
	char*	  					Xingming,
	int	  						Qianzhuzhonglei,
	int	  						ZhikaZhuangtai,
	char*	  					Zhengjianhaoma,
	char*	  					Jiekoufanhuijieguo,
	char*	  					Lianxidianhua,
	AddDataCallBack				callBack
	);

void    addSHOUZHENGSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	int							Zhengjianleixing,
	char*						Zhengjianhaoma,
	char*						Xingming,
	char*						Shoulibianhao,
	bool						Shifoujiaofei,
	AddDataCallBack				callBack
	);

void    addQIANZHUSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						YuanZhengjianhaoma,
	char*						Xingming,
	int							Xingbie,
	__int64						Chushengriqi,
	char*						Lianxidianhua,
	int							Yewuleixing,
	char*						Shouliren,
	AddDataCallBack				callBack
	);
void    addJIAOKUANSHUJU(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Zhishoudanweidaima,
	char*						Jiaokuantongzhishuhaoma,
	char*						Jiaokuanrenxingming,
	float						Yingkoukuanheji,
	__int64						Jiaoyiriqi,
	AddDataCallBack				callBack
	);
void    addCHAXUNSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Chaxunhaoma,
	char*						Chaxunleixing,
	bool						Shifouchaxunchenggong,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	);
void    addYUSHOULISHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int		  					Shebeibaifangweizhi,
	__int64		  				Riqi,
	char*	  					Yewubianhao,
	char*	  					Xingming,
	char*	  					Lianxidianhua,
	char*	  					Chuguoshiyou,
	char*  						YuanZhengjianhaoma,
	int		  					Qianzhuzhonglei,
	int		  					Xingbie,
	char*	  					Hukousuozaidi,
	char*	  					Minzu,
	__int64  					Chuangjianshijian,
	AddDataCallBack				callBack
	);
void    addSHEBEIZHUANGTAI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	bool						Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	bool						Shifouzaixian,
	AddDataCallBack				callBack
	);
void    addSHEBEIYICHANGSHUJU(
	int							Xuhao,
	int		  					Chengshibianhao,
	int		  					Jubianhao,
	int		  					Shiyongdanweibianhao,
	int		  					IP,
	bool	  					Bendiyewu,
	int							Shebeibaifangweizhi,
	__int64						Riqi,
	char*						Yichangshejimokuai,
	char*						Yichangyuanyin,
	char*						Yichangxiangxineirong,
	AddDataCallBack				callBack
	);
void    addGUANLIYUAN(
	int  						Xuhao,
	char*  						Yonghuming,
	char*  						Mima,
	int  						Youxiaoqikaishi,
	int  						Youxiaoqijieshu,
	int  						Quanxianjibie,
	AddDataCallBack				callBack
	);
void    addGUANLIYUANCAOZUOJILU(
	int  						Xuhao,
	char*  						Yonghuming,
	__int64  					Riqi,
	char*  						Caozuoleibie,
	char*  						Caozuoneirong,
	AddDataCallBack				callBack
	);
void    addSHEBEIGUANLI(
	int							Xuhao,
	int							Chengshibianhao,
	int							Jubianhao,
	int							Shiyongdanweibianhao,
	int							IP,
	char*						Shebeichangjia,
	char*						Shebeimingcheng,
	char*						Shebeileixing,
	float						Jingdu,
	float						Weidu,
	__int64						Chuangjianshijian,
	AddDataCallBack				callBack
	);
void    addYINGSHEBIAO(
	int							Bianhao,
	char*						Mingcheng,
	AddDataCallBack				callBack
	);
