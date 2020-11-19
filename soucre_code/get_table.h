#ifndef GET_TABLE_H
#define GET_TABLE_H

#include<my_set.h>
#include<iostream>
#include<fstream>
#include<cassert>
#include<string.h>
#include<windows.h>
#include<form.h>

using namespace std;

void set_time() {
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    //获取系统时间
    now_month = sys.wMonth;
    now_day = sys.wDay;
    now_hour = sys.wHour;
}
//获取系统时间
void change_time() {
    if (now_hour != 23) {
        //如果没到达23H 则hour+1 代表过了1h
        now_hour++;
    }
    else {
        //如果now_hour = 24 说明到了第二天 置0
        now_hour = 0;
        //接着根据月份情况，确定下一天是几号
        switch (now_month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            //大月
            if (now_day != 31) {
                //如果当前不是大月的最后一天，简单加1即可
                now_day++;
            }
            else {
                //如果是最后一天，重置为1
                now_day = 1;
                //判断第二个月的情况
                if (now_month != 12) {
                    //如果之前不是12月份，月份简单加一即可
                    now_month++;
                }
                else {
                    //如果之前是12月份，说明已经到了新的一年，月份置1，年份加一
                    now_month = 1;
                    now_year++;
                }
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            //小月
            if (now_day != 30) {
                //如果当前不是大月的最后一天，简单加1即可
                now_day++;
            }
            else {
                //如果是最后一天，重置为1
                now_day = 1;
                now_month++;
            }
            break;
        case 2:
            //2月
            if (now_day < 28) {
                //如果没到28号，不论闰年平年 都是加1
                now_day++;
            }
            else if ((now_year % 4 == 0 && now_year % 100 != 0) || (now_year % 400 == 0)) {
                //如果今年是闰年
                if (now_day == 28) {
                    //如果是28号,还有29号，则加1
                    now_day++;
                }
                else {
                    //如果29号，说明是最后一天， 重置为1，月份加1
                    now_day = 1;
                    now_month++;
                }
            }
            else {
                //不是闰年，日期重置，月份加1
                now_day = 1;
                now_month++;
            }
            break;
        default:
            cout << "please debug change_time function!" << endl;
            break;
        }
    }
}
//修改时间
void transform(char* string) {
    //小写字符串改为大写
    for (int i = 0; string[i] != '\0' && i < 10; i++) {
        if (string[i] - 97 >= 0) {
            string[i] -= 32;
        }
    }
}
//城市名称的大小写转换
void cut_timetable(int timetable_temp[130][6]) {
    int c[10] = { 0 };
    for (int i = 0; i < 130; i++) {
        int temp = c[timetable_temp[i][0]];
        //建立一个临时变量 存储当前始发城市
        for (int j = 0; j < 6; j++) {
            //将总表中的不同始发地的数据项进行复制，分割
            timetable[timetable_temp[i][0]][temp][j] = timetable_temp[i][j];
        }
        c[timetable_temp[i][0]]++;
    }
}
//该函数用来将得到的总时间表切割为三维数组 对应各个城市
void get_timetable() {
    //获取总的时间表
    int timetable_temp[130][6];
    ifstream timetable_all("./my_data/timetable.txt");
    if (!timetable_all.is_open()) {
        cout << "open file fail!" << endl;
        assert(timetable_all.is_open());
    }
    for (int i = 0; i < 130 && !timetable_all.eof(); i++) {
        char string[256];                          //临时的字符串变量
        timetable_all.getline(string, 256);
        char* temp = NULL;
        char* outer_ptr = NULL;
        temp = strtok_s(string, "\t", &outer_ptr);
        timetable_temp[i][0] = trans_city(temp);
        temp = strtok_s(NULL, "\t", &outer_ptr);
        timetable_temp[i][1] = trans_city(temp);
        temp = strtok_s(NULL, "\t", &outer_ptr);
        timetable_temp[i][2] = trans_transportation(temp);
        temp = strtok_s(NULL, "\t", &outer_ptr);
        if (strlen(temp) == 1)
            timetable_temp[i][3] = temp[0] - 48;
        else
            timetable_temp[i][3] = (temp[0] - 48) * 10 + temp[1] - 48;
        temp = strtok_s(NULL, "\t", &outer_ptr);
        if (strlen(temp) == 1)
            timetable_temp[i][4] = temp[0] - 48;
        else
            timetable_temp[i][4] = (temp[0] - 48) * 10 + temp[1] - 48;
        temp = strtok_s(NULL, "\t", &outer_ptr);
        if (strlen(temp) == 1)
            timetable_temp[i][5] = temp[0] - 48;
        else
            timetable_temp[i][5] = (temp[0] - 48) * 10 + temp[1] - 48;
    }
    cut_timetable(timetable_temp);
}
//用来从文件中时间表的函数
void get_danger() {
    ifstream danger_all("./my_data/danger.txt");
    if (!danger_all.is_open()) {
        cout << "open file fail!" << endl;
        assert(danger_all.is_open());
    }
    for (int i = 0; i < 10 && !danger_all.eof(); i++) {
        char string[256];                          //临时的字符串变量
        danger_all.getline(string, 256);
        char* temp = NULL;
        char* outer_ptr = NULL;
        temp = strtok_s(string, " ", &outer_ptr);
        city_table[i][0] = trans_city(temp);
        temp = strtok_s(NULL, " ", &outer_ptr);
        city_table[i][1] = (double)((temp[2] - 48)) / 10;
    }
    trans_table[0] = 9;
    trans_table[1] = 5;
    trans_table[2] = 2;
}
//用来从文件中风险情况的函数
#endif // GET_TABLE_H
