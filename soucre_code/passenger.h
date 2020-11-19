#ifndef PASSENGER_H
#define PASSENGER_H

#include<mainwindow.h>
#include<form.h>
#include<QString>
#include<QLabel>

class Passenger
{
public:
    Passenger() { m_status = -1; m_time = 0; };
    //默认构造函数
    void initial_a_Passenger(int day, int leave_time, int source, int destination, int strategy, int passenger_num, int max_time);
    //初始化限时模型下的旅客
    void initial_a_Passenger(int day, int leave_time, int source, int destination, int strategy, int passenger_num);
    //初始化非限时模型下的旅客
    ~Passenger() {};
    //析构函数
    void travel_simulation_DMS(int trans, double danger, int temp_time, Passenger& A);
    //非限时模型下的旅行模拟，用来求出最优旅行方案
    void travel_simulation_PDMS(int trans, double danger, int temp_time, int elapsed_time, Passenger& A);
    //限时模型下的旅行模拟，用来求出最优旅行方案
    void initial_min_danger_trans_and_stack();
    //初始化旅行模拟辅助数组
    void dbg_output_min_danger_trans();
    //测试用输出最小风险
    void dbg_get_source();
    //测试用获取目的地
    void stack_back_all();
    void stack_back_1(int trans);
    void stack_back_2(int trans);
    //退栈函数，用来辅助旅行模拟函数
    void get_plan();
    //用于获取模拟的计划
    int label_pos_x(int i);
    //获取heng'zuo'b1
    int label_pos_y(int i);
    //获取纵坐标
    QString travel();
    //旅行函数 按照随时间进行旅客移动 返回QString类型以便文字显示
    QString inquire_now();
    //查询当前状态函数
    QString inquire_plan();
    //查询计划函数
    QLabel *my_label;
    //图标
    int get_status() { return m_status; };
    //获知旅客状态
private:
    int m_leave_day;					//旅客出发的日期
    int m_leave_time;					//旅客出发的时间
    int m_source;						//出发地
    int m_stay_city_or_transportation;	//当前状态,置0为等待状态，置其他为在旅行中的时间
    int m_destination;					//目的地
    int m_strategy;						//出行策略
    int m_max_time;						//限时情况下的乘客最大时间
    int m_time;                         //记录旅客总耗时
    int m_how_travel_city[MAX_TRANS + 1][4];
    //二维数组 0					1					2					3
    //		城市次序,-1代表为空	记录交通工具		第几列车次			置为1表示已经离开始发城市，置0表示未离开过（包含未到达过）
    int m_passenger_num;				//旅客的代号
    int m_status;						//旅行状态,0代表旅行中，1代表旅行已经结束,-1代表未创建,2代表无法出行
    int m_stack[MAX_TRANS + 1][2];
    /*一个栈 用来为该旅客模拟出行情况
    二维数组 	0		1
                城市 	车次
    */
    int m_min_danger_trans[MAX_TRANS + 1][2];
    //暂存最小风险策略的二维数组
    //二维数组情况同上
    double m_min_danger;
    //记录最小风险
};
void Passenger::initial_a_Passenger(int day, int leave_time, int source, int destination, int strategy, int passenger_num, int max_time) {
    m_leave_day = day;
    m_leave_time = leave_time;
    m_source = source;
    m_destination = destination;
    m_strategy = strategy;
    m_passenger_num = passenger_num;
    m_max_time = max_time;
    m_status = 0;
    initial_min_danger_trans_and_stack();
    if (m_strategy == PUNCTUAL_DANGER_MIN_STRATEGY) {
        m_min_danger = MAX_DANGER_PDMS;
    }
    else {
        m_min_danger = MAX_DANGER_WITH_TRANS_PDMS;
    }
}
//限时旅客的初始化
void Passenger::initial_a_Passenger(int day, int leave_time, int source, int destination, int strategy, int passenger_num) {
    m_leave_day = day;
    m_leave_time = leave_time;
    m_source = source;
    m_destination = destination;
    m_strategy = strategy;
    m_passenger_num = passenger_num;
    m_status = 0;
    initial_min_danger_trans_and_stack();
    if (m_strategy == DANGER_MIN_STRATEGY) {
        m_min_danger = MAX_DANGER_DMS;
    }
    else {
        m_min_danger = MAX_DANGER_WITH_TRANS_DMS;
    }
}
 //非限时旅客的初始化
QString Passenger::travel() {
     int i = 0;
     //按照旅行模拟的结果旅行
     QString temp_string;
     while (m_how_travel_city[i][3] != 0) {
         //找到最近离开的城市，以及当前乘坐的车次
         i++;
     }
     if (m_stay_city_or_transportation > 0) {
         //若在旅行中
         if (m_stay_city_or_transportation == timetable[m_how_travel_city[i- 1][0]][m_how_travel_city[i - 1][2]][ALL_TIME] ) {
            //如果当前旅行时间等于本次乘车的总时间，说明已经到站
             my_label->setGeometry(label_pos_x(i), label_pos_y(i), 48, 48);
             m_stay_city_or_transportation = 0;
             //将状态置为等待状态
             QString str1 = QString::number(m_passenger_num + 1);
             QString str2 = QString::fromStdString(trans_city_back(timetable[m_how_travel_city[i - 1][0]][m_how_travel_city[i - 1][2]][DESTINATION]));
             temp_string =  QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客到达了") + str2;
             if (m_how_travel_city[i][0] == m_destination) {
                 //下一车次始发地是目的地，说明现在已经到达目的地了
                 m_status = 1;
                 //将旅行状态改为结束  
                 my_label->setGeometry(0,0,0,0);
                 temp_string.append(QString::fromLocal8Bit("第") +  str1 + QString::fromLocal8Bit("位旅客结束了旅行\n"));
             }
             else if (timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME] == now_hour) {
                 //如果下一车次的出发时间等于当前时间，转车
                 QString str3 = QString::fromStdString(trans_city_back(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][SOURCE]));
                 QString str4 = QString::fromStdString(trans_transportation_back(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][TRANSPORTATION]));
                 QString str5 = QString::fromStdString(trans_city_back(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][DESTINATION]));
                 temp_string.append(QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客已经转乘") + str3 +
                                    QString::fromLocal8Bit("站") + QString::number(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME])
                                    + QString::fromLocal8Bit("时的") + str4 + QString::fromLocal8Bit("准备前往") + str5);
                 m_stay_city_or_transportation = 1;
                 //置为旅行状态 乘车1h
                 m_how_travel_city[i][3] = 1;
             }
             else {
                 my_label->setGeometry(label_pos_x(i), label_pos_y(i), 48, 48);
                 //不处理，继续等车
             }
         }
         else {
             //如果没到站，旅行持续时间+1
             m_stay_city_or_transportation++;
         }
     }
     else {
         //如果不在旅行中，即等车状态
         my_label->setGeometry(label_pos_x(i), label_pos_y(i), 48, 48);
         if (timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME] == now_hour) {
             //如果下一车次的出发时间等于当前时间，转车
             QString str1 = QString::fromStdString(trans_city_back(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][SOURCE]));
             QString str2 = QString::number(m_passenger_num + 1);
             QString str3 = QString::fromStdString(trans_transportation_back(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][TRANSPORTATION]));
             QString str4 = QString::fromStdString(trans_city_back(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][DESTINATION]));
             temp_string = QString::fromLocal8Bit("第") + str2 + QString::fromLocal8Bit("位旅客已经乘坐上") + str1 +
                     QString::fromLocal8Bit("站") + QString::number(timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME]) +
                     QString::fromLocal8Bit("时的") + str3 + QString::fromLocal8Bit("准备前往") + str4;
             m_stay_city_or_transportation = 1;
             //置为旅行状态 乘车1h
             m_how_travel_city[i][3] = 1;
         }
     }
     return temp_string;
 }
 //旅行
QString Passenger::inquire_now() {
     QString temp_string;
     QString str1 = QString::number(m_passenger_num + 1);
     //查询,通过旅客代号输出当前状态
     if (m_status == 1){
         temp_string = QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客已经到达了目的地。");
     }

     else if (m_status == 2) {
         temp_string = QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客无法正常出行！");
     }
     else {
         int i = 0;
         while (m_how_travel_city[i + 1][3] != 0) {
             i++;
         }
         //查找m_how_travel_city数组，当发现第一个未离开的城市,之后判断状态
         if (m_stay_city_or_transportation == 0)
             temp_string = QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客正在") +
                     QString::fromStdString(trans_city_back(m_how_travel_city[i][0])) + QString::fromLocal8Bit("等车.");
         else{
             temp_string =  QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客正在乘坐") +
                     QString::fromStdString(trans_transportation_back(m_how_travel_city[i][1]))
                     + QString::fromLocal8Bit("从") + QString::fromStdString(trans_city_back(m_how_travel_city[i - 1][SOURCE])) +
                     QString::fromLocal8Bit("前往") + QString::fromStdString(trans_city_back(m_how_travel_city[i][SOURCE]));
         }
     }
     return temp_string;
 }
 //查询旅客状态
QString Passenger::inquire_plan() {
     int i = 0;
     QString temp_string;
     m_time= 0;
     QString str1 = QString::number(m_passenger_num + 1);
     if (m_min_danger_trans[0][1] == -1) {
         temp_string =  QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客无法正常出行。");
         return temp_string;
     }
     else if(m_status == -1){
         temp_string =  QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客还未创建。");
         return temp_string;
     }
     temp_string =  QString::fromLocal8Bit("第") + str1 + QString::fromLocal8Bit("位旅客的旅行计划如下：\n");
     while (m_how_travel_city[i][2] != -1 && m_how_travel_city[i][0] != m_destination) {
         //读取所有存在的路线
         temp_string.append(QString::fromLocal8Bit("第") + QString::number(i + 1 ) +
                            QString::fromStdString(trans_city_back(m_how_travel_city[i][0])) + QString::fromLocal8Bit("搭乘")
                            + QString::fromStdString(trans_transportation_back(m_how_travel_city[i][1])) + QString::fromLocal8Bit("前往"));
         if (m_how_travel_city[i + 1][0] == -1) {
             temp_string.append(QString::fromStdString(trans_city_back(m_destination)));
         }
         else {
             temp_string.append(QString::fromStdString(trans_city_back(m_how_travel_city[i + 1][0])));
         }
         temp_string.append("\n");
         if (i == 0) {
             if (m_leave_time <= timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME]) {
                 //如果出发时间小于发车时间 说明是同一天的车
                 m_time += timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME] - m_leave_time;
             }
             else {
                 m_time += timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME] + 24 - m_leave_time;
             }
         }
         else {
             if (timetable[m_how_travel_city[i - 1][0]][m_how_travel_city[i - 1][2]][FINISH_TIME]
                 <= timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME]) {
                 //如果出发时间小于发车时间 说明是同一天的车
                 m_time += timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME] - timetable[m_how_travel_city[i - 1][0]][m_how_travel_city[i - 1][2]][FINISH_TIME];
             }
             else {
                 m_time += timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][START_TIME] + 24 - timetable[m_how_travel_city[i - 1][0]][m_how_travel_city[i - 1][2]][FINISH_TIME];
             }
         }
         //等车时间
         m_time += timetable[m_how_travel_city[i][0]][m_how_travel_city[i][2]][ALL_TIME];
         //乘车时间
         i++;
     }
     if (m_how_travel_city[0][2] != -1) {
         QString str1 = QString::number(m_min_danger);
         QString str2 = QString::number(m_time);
         temp_string.append(QString::fromLocal8Bit("\n总风险为：") + str1 + QString::fromLocal8Bit("\n总耗时为：") + str2);
     }
     return temp_string;
}
 //查询旅客计划
void Passenger::initial_min_danger_trans_and_stack() {
    int i = 0;
    for (i = 0; i < MAX_TRANS + 1; i++) {
        m_min_danger_trans[i][0] = -1;
        m_min_danger_trans[i][1] = -1;
        m_stack[i][0] = -1;
        m_stack[i][1] = -1;
    }
    m_stack[0][0] = m_source;
}
//初始化最小风险策略和栈的所有值为初值-1
void Passenger::stack_back_all() {
    //退栈
    for (int i = 0; i < MAX_TRANS + 1; i++) {
        m_stack[i][0] = -1;
        m_stack[i][1] = -1;
    }
    m_stack[0][0] = m_source;
}
//退栈
void Passenger::stack_back_1(int trans) {
    m_stack[trans + 1][0] = -1;
    m_stack[trans][1] = -1; //告知退栈-当前步骤
}
//退栈1步
void Passenger::stack_back_2(int trans) {
    //退栈2步
    m_stack[trans + 1][0] = -1;
    m_stack[trans][1] = -1; //告知退栈-当前步骤
    m_stack[trans][0] = -1;
    m_stack[trans - 1][1] = -1; //告知退栈-上一步骤
}
//退栈2步
int find_next(int city, int time) {
    int i = 0;
    while (timetable[city][i][ALL_TIME] > 0 && timetable[city][i][START_TIME] < time) {
        //有车 且 发车时间小于当前时间
        i++;
    }
    return i;
}
//找到最近一班车
void Passenger::travel_simulation_DMS(int trans, double danger, int temp_time, Passenger& A) {
    if (m_stack[trans][0] == A.m_destination) {
        //如果当前栈顶是目的地 说明已经到达目的地
        if (danger < m_min_danger) {
            //如果风险小于最小风险
            m_min_danger = danger;
            if (m_min_danger < 0.1) {
                m_min_danger = 0;
            }
            //新的最小风险为当前风险
            for (int i = 0; i < MAX_TRANS + 1; i++) {
                A.m_min_danger_trans[i][0] = A.m_stack[i][0];
                A.m_min_danger_trans[i][1] = A.m_stack[i][1];
            }
            A.m_min_danger_trans[MAX_TRANS + 1][0] = A.m_stack[MAX_TRANS + 1][0];
            //最小风险策略设置为当前栈中情况;
        }
        if (m_min_danger <= 0.5) {
            stack_back_all();
        }
        //如果得到的最小风险已经相当小了就直接退出
        //如果得到一班车到达目的地，则经由上一地点的路线中不可能再有比该班车风险小的班次所以退栈2步
        if (trans > 0) {
            stack_back_2(trans);
            //退栈两步
        }
        else {
            stack_back_all();
        }
    }
    else {
        //如果没到达任何目的地
        if (trans < MAX_TRANS) {
            //如果转车次数小于最大转车次数则继续前进
            int now_city = A.m_stack[trans][0];
            //当前城市是栈顶的第一个城市
            double new_danger = 0;
            //该变量为新产生的风险
            int next = find_next(now_city, temp_time);
            //根据当前城市，当前时间寻找最近的一班车
            for (int j = next; timetable[now_city][j][ALL_TIME] != 0 && A.m_stack[trans][0] != -1 && j < 16; j++) {
                //从下一班车开始，有车且没发生退栈则继续
                A.m_stack[trans + 1][0] = timetable[now_city][j][DESTINATION];
                //下一个城市是本车次的目的地
                A.m_stack[trans][1] = j;
                //将该车次填入栈中
                new_danger = ((double)timetable[now_city][j][START_TIME] - temp_time) * city_table[now_city][1];
                //计算本次等车所产生的风险
                if (A.m_strategy == DANGER_MIN_STRATEGY) {
                    //如果是不含交通工具风险
                    if (danger + new_danger <= MAX_DANGER_DMS) {
                        //如果新风险小于最大风险继续前进，否则之后所有的车次风险都一定大于规定值，退栈两步
                        travel_simulation_DMS(trans + 1, danger + new_danger,
                            (timetable[now_city][j][START_TIME] + timetable[now_city][j][ALL_TIME]) % 24, A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                    }
                    else if (trans > 0) {
                        stack_back_2(trans);
                    }
                    else {
                        //如果转车次数为0，则是由始发地出发的车次，则此后均不可能出现可行解
                        stack_back_all();
                        //全退，结束循环
                    }
                }
                else if(A.m_strategy == DANGER_MIN_WITH_TRANS_STRATEGY){
                    //如果计算交通工具风险
                    double new_danger_trans = trans_table[timetable[now_city][j][TRANSPORTATION]] * timetable[now_city][j][ALL_TIME]
                        * city_table[now_city][1];
                    //计算本次乘车所产生的风险
                    if (danger + new_danger + new_danger_trans <= MAX_DANGER_WITH_TRANS_DMS) {
                        //如果新风险小于最大风险继续前进
                        travel_simulation_DMS(trans + 1, danger + new_danger + new_danger_trans,
                            (timetable[now_city][j][START_TIME] + timetable[now_city][j][ALL_TIME]) % 24, A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                    }
                    else if (danger + new_danger <= MAX_DANGER_WITH_TRANS_DMS) {
                        //如果新风险大于最大风险，但是原风险加上等车风险小于最大风险，则此时后面仍有可能出现可行的车次
                        stack_back_1(trans);
                    }
                    else {
                        //如果等车风险加上当前风险已经超出最大风险，则此后不可能出现可行解，退栈
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            //如果转车次数为0，则是由始发地出发的车次，则此后均不可能出现可行解
                            stack_back_all();
                            //全退，结束循环
                        }
                    }
                }
            }
            for (int j = 0; j < next && A.m_stack[trans][0] != -1; j++) {
                //从第二天的第一班开始直到第二天的next班次车，且未发生退栈
                A.m_stack[trans + 1][0] = timetable[now_city][j][DESTINATION];
                A.m_stack[trans][1] = j;
                //将该车次填入栈中
                new_danger = (timetable[now_city][j][START_TIME] + 24 - temp_time) * city_table[now_city][1];
                //计算本次等车所产生的风险
                if (A.m_strategy == DANGER_MIN_STRATEGY) {
                    //如果是不含交通工具风险
                    if (danger + new_danger <= MAX_DANGER_DMS) {
                        //如果新风险小于最大风险继续前进
                        travel_simulation_DMS(trans + 1, danger + new_danger,
                            (timetable[now_city][j][START_TIME] + timetable[now_city][j][ALL_TIME]) % 24, A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                    }
                    else if(A.m_strategy == DANGER_MIN_WITH_TRANS_STRATEGY){
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            stack_back_all();
                            //如果仅由始发地出发的车都已经超出最大风险，则直接舍弃后面
                        }
                    }
                }
                else {
                    //如果含有交通工具的风险
                    double new_danger_trans = trans_table[timetable[now_city][j][TRANSPORTATION]] * timetable[now_city][j][ALL_TIME]
                        * city_table[now_city][1];
                    //计算交通工具的风险
                    if (danger + new_danger + new_danger_trans <= MAX_DANGER_WITH_TRANS_DMS) {
                        //如果新风险小于最大风险继续前进
                        travel_simulation_DMS(trans + 1,danger + new_danger + new_danger_trans,
                            (timetable[now_city][j][START_TIME] + timetable[now_city][j][ALL_TIME]) % 24, A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                    }
                    else if (danger + new_danger <= MAX_DANGER_WITH_TRANS_DMS) {
                        //如果新风险大于最大风险，但是原风险加上等车风险小于最大风险，则此时后面仍有可能出现可行的车次
                        stack_back_1(trans);
                    }
                    else {
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            stack_back_all();
                            //如果仅由始发地出发的车都已经超出最大风险，则直接舍弃后面
                        }
                    }
                }
            }
        }
    }
}
//DMS策略下的旅行模拟
void Passenger::travel_simulation_PDMS(int trans, double danger, int temp_time, int elapsed_time, Passenger& A) {
    if (A.m_stack[trans][0] == A.m_destination) {
        //如果当前栈顶是目的地 说明已经到达目的地
        if (danger < m_min_danger && elapsed_time <= A.m_max_time) {
            //如果风险小于最小风险,且消耗的时间不超过规定用时
            m_min_danger = danger;
            //新的最小风险为当前风险
            if (m_min_danger < 0.1) {
                m_min_danger = 0;
            }
            for (int i = 0; i < MAX_TRANS + 1; i++) {
                A.m_min_danger_trans[i][0] = A.m_stack[i][0];
                A.m_min_danger_trans[i][1] = A.m_stack[i][1];
                //cout << A.m_min_danger_trans[i][0] << "\t" << A.m_min_danger_trans[i][1] << endl;
            }
            A.m_min_danger_trans[MAX_TRANS + 1][0] = A.m_stack[MAX_TRANS + 1][0];
            //最小风险策略设置为当前栈中情况
        }
        if (m_min_danger <= 0.5) {
            stack_back_all();
        }
        //如果得到的最小风险已经相当小了就直接退出
        //如果得到一班车到达目的地，则经由上一地点的路线中不可能再有比该班车风险小的班次所以退栈2步
        if (trans > 0) {
            stack_back_2(trans);
            //退栈两步
        }
        else {
            //如果仅经过始发地就可以到达目的地，那直接得出结果
            stack_back_all();
        }
    }
    else {
        //如果没到达任何目的地
        if (trans < MAX_TRANS) {
            //如果转车次数小于最大转车次数则继续前进
            int now_city = A.m_stack[trans][0];
            //当前城市是栈顶的第一个城市
            double new_danger = 0;
            //该变量为新产生的风险
            int next = find_next(now_city, temp_time);
            //根据当前城市，当前时间寻找最近的一班车
            int new_time = 0;
            //新产生的时间消耗
            for (int j = next; timetable[now_city][j][ALL_TIME] != 0 && A.m_stack[trans][0] != -1 && j < 16; j++) {
                //从下一班车开始，有车且没发生退栈则继续
                A.m_stack[trans + 1][0] = timetable[now_city][j][DESTINATION];
                //下一个城市是本车次的目的地
                A.m_stack[trans][1] = j;
                //将该车次填入栈中
                new_danger = (timetable[now_city][j][START_TIME] - temp_time) * city_table[now_city][1];
                //计算本次乘车所产生的风险
                new_time = timetable[now_city][j][START_TIME] - temp_time;
                //计算本次乘车产生的等车时间消耗为 发车时间 减去 当前时间
                if (A.m_strategy == PUNCTUAL_DANGER_MIN_STRATEGY) {
                    //如果不计算交通工具风险
                    if (danger + new_danger <= MAX_DANGER_PDMS && new_time + elapsed_time + timetable[now_city][j][ALL_TIME] <= A.m_max_time) {
                        //如果新风险小于最大风险且新产生的等、乘车时间加上消耗时间小于规定时间 则继续前进
                        travel_simulation_PDMS(trans + 1, danger + new_danger, (timetable[now_city][j][START_TIME] +
                            timetable[now_city][j][ALL_TIME]) % 24, new_time + elapsed_time + timetable[now_city][j][ALL_TIME], A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                        //新消耗时间为等、乘时间加上已消耗时间
                    }
                    else if ((timetable[now_city][j][START_TIME] - temp_time + elapsed_time) >= A.m_max_time) {
                        //如果当前车次仅等车时间加上消耗时间就已经超时，则后面任何班次不可能有符合条件的车次
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            stack_back_all();
                            //如果仅由始发地出发的车都已经超出时间，则直接舍弃后面
                        }
                    }
                    //其他情况为乘车时间超出，但等车风险未超出 仍有可能 不处理
                }
                else if(A.m_strategy == PUNCTUAL_DANGER_MIN_WITH_TRANS_STRATEGY){
                    //如果计算交通工具产生的风险
                    double new_danger_trans = trans_table[timetable[now_city][j][TRANSPORTATION]] * timetable[now_city][j][ALL_TIME]
                        * city_table[now_city][1];
                    //乘车产生的风险
                    if (danger + new_danger + new_danger_trans <= MAX_DANGER_WITH_TRANS_PDMS &&
                        new_time + elapsed_time + timetable[now_city][j][ALL_TIME] <= A.m_max_time) {
                        //如果新风险小于最大风险且新产生的等、乘车时间加上消耗时间小于规定时间 则继续前进
                        travel_simulation_PDMS(trans + 1, danger + new_danger + new_danger_trans, (timetable[now_city][j][START_TIME] +
                            timetable[now_city][j][ALL_TIME]) % 24, new_time + elapsed_time + timetable[now_city][j][ALL_TIME], A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                        //新消耗时间为等、乘时间加上已消耗时间
                    }
                    else if ((timetable[now_city][j][START_TIME] - temp_time + elapsed_time) >= A.m_max_time) {
                        //如果当前车次仅等车时间加上消耗时间就已经超时，则后面任何班次不可能有符合条件的车次
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            stack_back_all();
                            //如果仅由始发地出发的车都已经超出时间，则直接舍弃后面
                        }
                    }
                    else if (danger + new_danger < MAX_DANGER_WITH_TRANS_PDMS) {
                        //如果当前时间未超出，等风险加原风险未超出，但是总风险超出，则后面仍有可能出现可行解 不处理
                        stack_back_1(trans);
                    }
                    //其他情况为乘车时间超出，但等车风险未超出 仍有可能 不处理
                }
            }
            for (int j = 0; j < next && A.m_stack[trans][0] != -1; j++) {
                //从第二天的第一班开始直到第二天的next班次车，且未发生退栈
                A.m_stack[trans + 1][0] = timetable[now_city][j][DESTINATION];
                A.m_stack[trans][1] = j;
                //将该车次填入栈中
                new_danger = (timetable[now_city][j][START_TIME] + 24 - temp_time) * city_table[now_city][1];
                //计算本次等车所产生的风险
                new_time = timetable[now_city][j][START_TIME] + 24 - temp_time + timetable[now_city][j][ALL_TIME];
                //计算本次乘车产生的时间消耗为 发车时间 + 24 减去 当前时间 加上总耗时
                if (A.m_strategy == PUNCTUAL_DANGER_MIN_STRATEGY) {
                    if (danger + new_danger <= MAX_DANGER_PDMS && new_time + elapsed_time <= A.m_max_time) {
                        //如果新风险小于最大风险且新产生的等、乘车时间加上消耗时间小于规定时间 则继续前进
                        travel_simulation_PDMS(trans + 1,danger + new_danger, (timetable[now_city][j][START_TIME] +
                            timetable[now_city][j][ALL_TIME]) % 24, new_time + elapsed_time + timetable[now_city][j][ALL_TIME], A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                        //新消耗时间为等、乘时间加上已消耗时间
                    }
                    else if ((timetable[now_city][j][START_TIME] + 24 - temp_time + elapsed_time) >= A.m_max_time) {
                        //如果当前车次仅等车时间加上消耗时间就已经超时，则后面任何班次不可能有符合条件的车次
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            stack_back_all();
                            //如果仅由始发地出发的车都已经超出时间，则直接舍弃后面
                        }
                    }
                    //其他情况为乘车时间超出，但等车风险未超出 仍有可能 不处理
                }
                else {
                    //如果计算乘风险
                    double new_danger_trans = trans_table[timetable[now_city][j][TRANSPORTATION]] * timetable[now_city][j][ALL_TIME]
                        * city_table[now_city][1];
                    //乘风险
                    if (danger + new_danger + new_danger_trans <= MAX_DANGER_WITH_TRANS_PDMS && new_time + elapsed_time <= A.m_max_time) {
                        //如果新风险小于最大风险且新产生的等、乘车时间加上消耗时间小于规定时间 则继续前进
                        travel_simulation_PDMS(trans + 1, danger + new_danger + new_danger_trans, (timetable[now_city][j][START_TIME] +
                            timetable[now_city][j][ALL_TIME]) % 24, new_time + elapsed_time + timetable[now_city][j][ALL_TIME], A);
                        //向前试探下一步，转车次数加一，风险为原风险加上产生的新风险,新时间为发车时间加上乘车时间
                        //新消耗时间为等、乘时间加上已消耗时间
                    }
                    else if ((timetable[now_city][j][START_TIME] + 24 - temp_time + elapsed_time) >= A.m_max_time) {
                        //如果当前车次仅等车时间加上消耗时间就已经超时，则后面任何班次不可能有符合条件的车次
                        if (trans > 0) {
                            stack_back_2(trans);
                        }
                        else {
                            stack_back_all();
                            //如果仅由始发地出发的车都已经超出时间，则直接舍弃后面
                        }
                    }
                    else if (danger + new_danger < MAX_DANGER_WITH_TRANS_PDMS) {
                        //如果当前时间未超出，等风险加原风险未超出，但是总风险超出，则后面仍有可能出现可行解
                        stack_back_1(trans);
                    }
                    //其他情况为乘车时间超出，但等车风险未超出 仍有可能 不处理
                }
            }
        }
    }
}
//PDMS策略下的旅行模拟
void Passenger::get_plan() {
    m_min_danger_trans[0][0] = m_source;
    if (m_min_danger_trans[0][1] == -1) {
        m_status = 2;
    }
    for (int i = 0; i < MAX_TRANS + 1; i++) {
        m_how_travel_city[i][0] = m_min_danger_trans[i][0];
        m_how_travel_city[i][1] = timetable[m_min_danger_trans[i][0]][m_min_danger_trans[i][1]][TRANSPORTATION];
        m_how_travel_city[i][2] = m_min_danger_trans[i][1];
        m_how_travel_city[i][3] = 0;
    }
}
//获取计划
int Passenger::label_pos_x(int i){
    if(m_how_travel_city[i][0] == 0)
        return 550;
    else if(m_how_travel_city[i][0] == 1)
        return 680;
    else if(m_how_travel_city[i][0] == 2)
        return 510;
    else if(m_how_travel_city[i][0] == 3)
        return 640;
    else if(m_how_travel_city[i][0] == 4)
        return 650;
    else if(m_how_travel_city[i][0] == 5)
        return 760;
    else if(m_how_travel_city[i][0] == 6)
        return 381;
    else if(m_how_travel_city[i][0] == 7)
        return 620;
    else if(m_how_travel_city[i][0] == 8)
        return 460;
    else if(m_how_travel_city[i][0] == 9)
        return 560;
}
//获取x
int Passenger::label_pos_y(int i){
    if(m_how_travel_city[i][0] == 0)
        return 270;
    else if(m_how_travel_city[i][0] == 1)
        return 410;
    else if(m_how_travel_city[i][0] == 2)
        return 530;
    else if(m_how_travel_city[i][0] == 3)
        return 470;
    else if(m_how_travel_city[i][0] == 4)
        return 224;
    else if(m_how_travel_city[i][0] == 5)
        return 154;
    else if(m_how_travel_city[i][0] == 6)
        return 424;
    else if(m_how_travel_city[i][0] == 7)
        return 360;
    else if(m_how_travel_city[i][0] == 8)
        return 354;
    else if(m_how_travel_city[i][0] == 9)
        return 450;
}
//获取y
#endif // PASSENGER_H
