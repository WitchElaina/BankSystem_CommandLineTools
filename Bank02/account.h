//
//  account.hpp
//  Bank01
//
//  Created by 马澍朝 on 2021/9/8.
//

#ifndef account_h
#define account_h



#include<cmath>
#include "date.h"


class SavingsAccount
{
    string id;
    double balance;
    double rate;
    Date lastDate;
    double accumulation;
    void record(Date m_date, double m_amount);
    double accumulate(Date m_data);

public:
    static double total;
    SavingsAccount(Date m_date,string m_id,double m_rate);
    string getID();
    double getBalance();
    double getRate();
    static double getTotal();
    void show();
    void deposit(Date m_date, double m_amount,string m_detail);
    void withdraw(Date m_date,double m_amount,string m_detail);
    void settle(Date m_date);
};

#endif /* account_h */
