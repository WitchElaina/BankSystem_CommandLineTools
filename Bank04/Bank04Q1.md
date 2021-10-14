# 问题一

## CreditAccount函数中哪些没被定义成虚函数

### 构造函数

`CreditAccount`类和`SavingsAccoun`类虽然都有用户自定义的构造函数, 但构造函数中锁**使用的变量不同**, **不能共用一个接口**, 因此不能定义成虚函数.

### 值获取类函数

`getCredit()`,`getRate()`,`getFee()`,`getAvailableCredit()`等**返回私有对象值**的函数没被定义成虚函数, 因为`SavingsAccount`类中不包含这些对象, 无须创建共用的接口.

> 相关代码如下
>
> ````cpp
> // account.h
> 
> // 用户类基类
> class Account
> {
>     // 用户ID
>     string id;
>     // 用户余额
>     double balance;
>     // 系统总存款
>     static double total;
>     
> 
> public:
>     // 构造函数
>     Account(Date m_date,string m_id);
> 
>     //
>     virtual ~Account();
> 
>     // 账户变动记录辅助函数
>     void record(Date m_date, double m_amount,string m_desc);
>     // 获取用户ID
>     string getID();
>     // 获取用户余额
>     double getBalance();
>     // 获取系统总存款
>     static double getTotal();
>     // 打印用户信息函数
>     virtual void show()=0;
>     // 存款函数
>     virtual void deposit(Date m_date, double m_amount, string m_desc )=0;
>     // 取款函数
>     virtual void withdraw(Date m_date, double m_amount, string m_desc )=0;
>     // 结算利息函数
>     virtual void settle(Date date)=0;
>     
> };
> 
> // 信用卡类
> class CreditAccount:virtual public Account
> {
>     // 累加器
>     Accumulator acc;
>     // 信用额度
>     double credit;
>     // 利息
>     double rate;
>     // 年费
>     double fee;
>     Date a_date;
> 
> 
> public:
>     // 信用卡类构造函数
>     CreditAccount(Date m_date, string m_id, double m_credit, double m_rate, double m_fee);
>     // 获取信用额度
>     double getCredit();
>     // 获取利息
>     double getRate();  
>     // 获取年费
>     double getFee();
>     // 获取可用额度
>     double getAvailableCredit();
>     // 还款函数
>     void deposit(Date m_date, double m_amount,string m_detail);
>     // 支付函数
>     void withdraw(Date m_date,double m_amount,string m_detail);
>     // 结算利息函数
>     void settle(Date m_date);
>     // 打印账户信息
>     void show();
> };
> ````
>
> 