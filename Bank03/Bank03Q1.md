# 问题一

**SavingsAccount**和**CreditAccount**的共性:

代码如下

````cpp
// 储蓄卡类
class SavingsAccount:virtual public Account
{
    // 累加器
    Accumulator acc;
    // 利率
    double rate;

public:
    // 储蓄卡类构造函数
    SavingsAccount(Date m_date, string m_id, double m_rate);
    // 获取利率
    double getRate();
    // 存款函数
    void deposit(Date m_date, double m_amount,string m_detail);
    // 取款函数
    void withdraw(Date m_date,double m_amount,string m_detail);
    // 结算利息函数
    void settle(Date m_date);
    // 打印账户信息
    void show();

};
````

````cpp
// 信用卡类
class CreditAccount:virtual public Account
{
    // 累加器
    Accumulator acc;
    // 信用额度
    double credit;
    // 利息
    double rate;
    // 年费
    double fee;
    Date a_date;


public:
    // 信用卡类构造函数
    CreditAccount(Date m_date, string m_id, double m_credit, double m_rate, double m_fee);
    // 获取信用额度
    double getCredit();
    // 获取利息
    double getRate();  
    // 获取年费
    double getFee();
    // 获取可用额度
    double getAvailableCredit();
    // 还款函数
    void deposit(Date m_date, double m_amount,string m_detail);
    // 支付函数
    void withdraw(Date m_date,double m_amount,string m_detail);
    // 结算利息函数
    void settle(Date m_date);
    // 打印账户信息
    void show();
};
````

从类的声明中可以看出

- 都继承了`Account`类, 都包含编号`id`, 余额`balance`等账户基本信息变量.
- 都拥有**账目变动记录**方法`record(Date, double, string)`, 用来记录账户存取款情况.