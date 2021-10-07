#ifndef date_h
#define date_h

#include <iostream>

using namespace std;

const int DAYS_EACH_MONTH[]={0,31,59,90,120,151,181,212,243,273,304,334,365};

const int DAY_EACH_MONTH[]={31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
private:
    /* data */
    int year;
    int month;
    int day;

public:
    Date(int m_year,int m_month,int m_day);
    Date();
    void show();
    int get_year();
    int get_month();
    int get_day();
    bool isLeap(int m_year);
    int date_trans();
    int distance(Date m_date);
};


#endif /* date.h */