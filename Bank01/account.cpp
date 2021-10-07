//
//  account.cpp
//  Bank01
//
//  Created by 马澍朝 on 2021/9/8.
//

#include "account.hpp"


// 构造函数
SavingsAccount::SavingsAccount(int m_date,int m_id,double m_rate)
{
    lastDate=m_date;
    id=m_id;
    rate=m_rate;
    balance=0;
    accumulation=0;
}

// 获取ID
int SavingsAccount::getID()
{
    return id;
}

// 获取余额
double SavingsAccount::getBalance()
{
    return  balance;
}

// 获取利率
double SavingsAccount::getRate()
{
    return rate;
}


// 累加器
double SavingsAccount::accumulate(int m_data)
{
    double temp=(m_data-lastDate)*balance;
    return temp;
}

// 账户变动记录辅助函数
void SavingsAccount::record(int m_date, double m_amount)
{
    m_amount = floor(m_amount * 100 + 0.5) / 100;
    accumulation+=accumulate(m_date);
    lastDate=m_date;
    balance+=m_amount;
    if(m_amount!=0)
        cout<<lastDate<<"\t#"
        <<id<<"\t"
        <<m_amount<<"\t"
        <<balance<<endl;
}

// 存款函数
void SavingsAccount::deposit(int m_date, double m_amount)
{
    record(m_date, m_amount);
}

// 取款函数
void SavingsAccount::withdraw(int m_date, double m_amount)
{
    record(m_date, -m_amount);
}

// 利息结算函数
void SavingsAccount::settle(int m_date)
{
    double rating;
    record(m_date, 0);
    rating=accumulation/365*rate;
    rating=floor(rating * 100 + 0.5) / 100;
    balance+=rating;
    cout<<lastDate<<"\t#"<<id<<"\t"<<rating<<endl;
}


// 账户余额打印函数
void SavingsAccount::show()
{
    cout<<"#"<<getID()<<"\tBalance: "<<getBalance();
}
