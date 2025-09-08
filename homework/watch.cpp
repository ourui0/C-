//
// Created by 34021 on 2025/9/8.
//
#include <algorithm>
#include<iostream>
#include<cstring>
using namespace std;
struct month{
    string str;
    long long num;
};
month months[12] = {
    {"January",1},{"February",2},
    {"March",3},{"April",4},
    {"May",5},{"June",6},
    {"July",7},{"August",8},
    {"September",9},{"October",10},
    {"November",11},{"December",12}
};
static const long long   DAY  = 86400;
static const long long   HOUR = 3600;
static const long long   MIN  = 60;

long long mdays[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},   // 平年
    {0,31,29,31,30,31,30,31,31,30,31,30,31}    // 闰年
};

/* 返回 year 年共有多少秒 */
long long year(long long y){
    return ((y%4==0 && y%100!=0) || (y%400==0)) ? 366*DAY : 365*DAY;
}

/* 返回 year 年 m 月共有多少秒 */
long long month(long long y,long long m){
    return mdays[year(y)==366*DAY][m] * DAY;
}
long long transform(string str) {
    for(auto & month : months) {
        if (strcmp(str.c_str(),month.str.c_str())==0) {
            return month.num;
        }
    }
    return 0;
}

string transform2(long long num) {
    if (num >= 10) {
        return std::to_string(num);
    }
    else {
        return "0"+std::to_string(num);
    }
}
void break_down_time(long long real,long long &y, long long &m, long long &d, long long &h, long long &min, long long &s){
    y = 2024; m = 9; d = 16;
    h = min = s = 0;

    while (real >= year(y+1)){
        real -= year(++y);
    }
    while (real >= month(y,m)){
        real -= month(y,m++);
        if (m==13){ m=1; y++; }
    }
    while (real < -month(y, m)){
        --m;
        if (m==0){ m=12; --y;}
        real += month(y,m);
    }

    /* 3. 日、时、分、秒直接除 */
    d += real / DAY;   real %= DAY;
    if (d > month(y,m)/DAY) {
        d -= month(y,m)/DAY;
        m++;
    }
    h  = real / HOUR;  real %= HOUR;
    if (h<0) {
        d-=1;
        h += 24;
    }
    min= real / MIN;   s=real % MIN;
    if (min < 0) {
        h-=1;
        min += 60;
    }
    if (s <0) {
        min-=1;
        s += 60;
    }
}
void watch(long long *year,long long *monthname,long long *day,long long *hour,long long *minute,long long *second) {
    long long count1 = 0 ;//以年为尺度计算
    for (long long i = 2025;i < *year; i++) {
        if ((i % 4 ==0 && i%100!=0)||(i%100==0&&i%400==0)) {
            count1 += 366*24;
        }
        else {
            count1 += 365*24;
        }
    }
    long long count2 = 0;//以月为尺度计算
    if (*year >= 2025||*year == 2024&&*monthname >= 9) {
        for (long long i = 9;i < 12*(*year - 2024 > 0) + *monthname; i++) {
            if (i <= 12) {
                if (i == 9||i == 11) {
                    count2 += 30 * 24;
                }
                else {
                    count2 += 31 * 24;
                }
            }
            else {
                if (i - 12 == 9||i - 12 == 11||i - 12 == 4||i - 12 == 6) {
                    count2 += 24 * 30;
                }
                else if (i - 12 == 2){
                    count2 += 28 * 24;
                }
                else {
                    count2 += 31 * 24;
                }
            }
        }
    }
    else {
        for (long long i = *monthname;i < 9; i++) {
            if (i == 4||i == 6) {
                count2 -= 24 * 30;
            }else if (i == 2){
                count2 -= 29 * 24;
            }else {
                count2 -= 31 * 24;
            }
        }
    }

    long long count3 = (*day - 2) * 24;//以日为尺度计算
    long long count4 = *hour - 22 + 23;//以小时为尺度
    long long count5 = *minute - 20 + 60;//以分钟为尺度
    long long count6 = *second;//以秒为尺度
    long long Count = (count1 + count2 + count3 + count4) * 3600 + count5 * 60 + count6;
    long long real = Count * 60/59 ;
    if (real < 0)real-=1;
    break_down_time(real, *year, *monthname, *day, *hour, *minute, *second);
}
int main() {
    long long year, day,hour,minute,second;
    string month;

    //输入
    cin >> year >> month >> day >> hour >> minute >> second;
    //转换
    long long monthName = transform(month);

    watch(&year, &monthName, &day, &hour, &minute, &second);
    //输出
    cout<< year<<'-'<<transform2(monthName)<<'-'<<transform2(day)<<'T'<<transform2(hour)<<':'<<transform2(minute)<<':'<<transform2(second);
    return 0;
}
