// date.cpp

#include "date.h"

Date::Date(int m_year,int m_month,int m_day)
{
    year=m_year;
    month=m_month;
    day=m_day;
}

Date::Date()
{

}

void Date::show()
{
    cout<<year<<"-"<<month<<"-"<<day;
}

int Date::get_year()
{
    return year;
}

int Date::get_month()
{
    return month;
}

int Date::get_day()
{
    return day;
}

bool Date::isLeap(int m_year)
{
    if((m_year%100==0||m_year%400==0)&&(m_year%4==0||m_year%100!=0))
        return true;
    else
        return false;
}

int Date::date_trans()
{
    int day_sum=0;
    for(int i=1;i<get_year();i++)
    {
        day_sum+=365;
        if(isLeap(i))
            day_sum++;
    }

    day_sum+=DAYS_EACH_MONTH[get_month()-1];

    day_sum+=get_day();

    return day_sum;
}

int Date::date_cal(Date m_date)
{
    return -m_date.date_trans()+date_trans();
}
