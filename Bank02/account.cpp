//
//  account.cpp
//  Bank01
//
//  Created by 马澍朝 on 2021/9/8.
//

#include "account.h"

// 初始化总金额
double SavingsAccount::total=0;

// 构造函数
SavingsAccount::SavingsAccount(Date m_date,string m_id,double m_rate)
{
    lastDate=m_date;
    id=m_id;
    rate=m_rate;
    balance=0;
    accumulation=0;
    m_date.show();
    cout<<"\t#"<<id<<" created"<<endl;
}

// 获取ID
string SavingsAccount::getID()
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


// 获取总存款
double SavingsAccount::getTotal()
{
    return total;
}


// 累加器
double SavingsAccount::accumulate(Date m_data)
{
    double temp=(m_data.date_cal(lastDate))*balance;
    return temp;
}

// 账户变动记录辅助函数
void SavingsAccount::record(Date m_date, double m_amount)
{
    m_amount = floor(m_amount * 100 + 0.5) / 100;
    accumulation+=accumulate(m_date);
    lastDate=m_date;
    balance+=m_amount;
    total+=m_amount;
    if(m_amount!=0)
    {
        lastDate.show();
        cout<<"\t#"<<id<<"\t"<<m_amount<<"\t"<<balance;
    }
}

// 存款函数
void SavingsAccount::deposit(Date m_date, double m_amount,string m_detail)
{
    record(m_date, m_amount);
    cout<<"\t"<<m_detail<<endl;
}

// 取款函数
void SavingsAccount::withdraw(Date m_date, double m_amount,string m_detail)
{
    record(m_date, -m_amount);
    cout<<"\t"<<m_detail<<endl;
}

// 利息结算函数
void SavingsAccount::settle(Date m_date)
{
    double rating;
    record(m_date, 0);
    rating=accumulation/366*rate;
    rating=floor(rating * 100 + 0.5) / 100;
    balance+=rating;
    total+=rating;
    lastDate.show();
    cout<<"\t#"<<id<<"\t"<<rating<<"\t"<<balance<<"\t"<<"interest"<<endl;
}


// 账户余额打印函数
void SavingsAccount::show()
{
    cout<<getID()<<"\tBalance: "<<getBalance();
}
