#ifndef FORM_H
#define FORM_H

#include<my_set.h>
#include<string.h>

const char* trans_city_back(int city) {
    switch (city)
    {
    case 0:
        return BEIJING;
    case 1:
        return SHANGHAI;
    case 2:
        return GUANGZHOU;
    case 3:
        return HANGZHOU;
    case 4:
        return SHENYANG;
    case 5:
        return HAERBIN;
    case 6:
        return CHENGDU;
    case 7:
        return NANJING;
    case 8:
        return XIAN;
    case 9:
        return WUHAN;
    default:
        return MY_ERROR;
    }
}
//城市与城市变量之间的转换函数
int trans_city(char* string) {
    if (strcmp(string, BEIJING) == 0) return 0;
    else if (!strcmp(string, SHANGHAI)) return 1;
    else if (!strcmp(string, GUANGZHOU)) return 2;
    else if (!strcmp(string, HANGZHOU)) return 3;
    else if (!strcmp(string, SHENYANG)) return 4;
    else if (!strcmp(string, HAERBIN)) return 5;
    else if (!strcmp(string, CHENGDU)) return 6;
    else if (!strcmp(string, NANJING)) return 7;
    else if (!strcmp(string, XIAN)) return 8;
    else if (!strcmp(string, WUHAN)) return 9;
    else return -1;
}
//城市与城市变量之间的转换函数
const char* trans_transportation_back(int transportation) {
    switch (transportation)
    {
    case 0:
        return FLIGHT;
    case 1:
        return TRAIN;
    case 2:
        return CAR;
    default:
        return MY_ERROR;
    }
}
//交通工具与交通工具变量之间的转换函数
int trans_transportation(char* string) {
    if (!strcmp(string, FLIGHT)) return 0;
    else if (!strcmp(string, TRAIN)) return 1;
    else if (!strcmp(string, CAR)) return 2;
    else return -1;
}
//交通工具与交通工具变量之间的转换函数
#endif // FORM_H
