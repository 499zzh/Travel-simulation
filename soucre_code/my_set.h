#ifndef MY_SET_H
#define MY_SET_H

extern const char BEIJING[10] = "BEIJING";
extern const char SHANGHAI[10] = "SHANGHAI";
extern const char GUANGZHOU[10] = "GUANGZHOU";
extern const char HANGZHOU[10] = "HANGZHOU";
extern const char SHENYANG[10] = "SHENYANG";
extern const char HAERBIN[10] = "HAERBIN";
extern const char CHENGDU[10] = "CHENGDU";
extern const char NANJING[10] = "NANJING";
extern const char XIAN[10] = "XIAN";
extern const char WUHAN[10] = "WUHAN";
extern const char MY_ERROR[10] = "ERROR!";

extern const char FLIGHT[10] = "FLIGHT";
extern const char TRAIN[10] = "TRAIN";
extern const char CAR[10] = "CAR";

#define MAX_TRANS 5 //定义最大转车次数
#define MAX_DANGER_DMS 20 //定义最大可接受的风险大小
#define MAX_DANGER_PDMS 20 //定义最大可接受的风险大小
#define MAX_DANGER_WITH_TRANS_DMS 50 //定义最大可接受的风险大小
#define MAX_DANGER_WITH_TRANS_PDMS 50 //定义最大可接受的风险大小

#define DANGER_MIN_STRATEGY 0 //风险最小策略
#define PUNCTUAL_DANGER_MIN_STRATEGY 1 //规定时间的风险最小策略
#define DANGER_MIN_WITH_TRANS_STRATEGY 2 //风险最小策略
#define PUNCTUAL_DANGER_MIN_WITH_TRANS_STRATEGY 3 //规定时间的风险最小且包含交通工具策略

#define SOURCE 0
#define DESTINATION 1
#define TRANSPORTATION 2
#define START_TIME 3
#define FINISH_TIME 4
#define ALL_TIME 5

#define MAX_PASSENGER 50
//最大接待乘客数
double city_table[10][2];
/*城市情况表
0	1
城市	风险
*/
double trans_table[3];
//交通工具风险情况
int  timetable[10][20][6];
/*
第一列代表城市 每个城市对应一个二维数组
二维数组	0			1			2			3			4			5
            始发地 		目的地		交通工具	出发时间 	到达时间	消耗的总时间
该二维数组按照出发时间升序排列 20是经查表记录最多班次的城市北京所拥有的发车次数为16 设定为最大值
*/
int now_year = 2020;
int now_month;
int now_day;
int now_hour;
//时间

#endif // MY_SET_H
