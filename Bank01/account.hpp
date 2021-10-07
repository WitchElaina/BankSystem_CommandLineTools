//
//  account.hpp
//  Bank01
//
//  Created by 马澍朝 on 2021/9/8.
//

#ifndef account_hpp
#define account_hpp

#include <iostream>
#include <cmath>
using namespace std;

class SavingsAccount
{
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;
    void record(int m_date, double m_amount);
    double accumulate(int m_data);

public:
    SavingsAccount(int m_date,int m_id,double m_rate);
    int getID();
    double getBalance();
    double getRate();
    void show();
    void deposit(int m_date, double m_amount);
    void withdraw(int m_date,double m_amount);
    void settle(int m_date);
};

#endif /* account_hpp */
