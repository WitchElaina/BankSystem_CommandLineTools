# 问题二

## 对年利率的理解

本体中的年利率计算时需要先计算日均存款, 在结算时再按照结算前日均存款总和计算所获得的年利率, 核心公式如下
$$
年利息=(每日和\div当年天数)\times年利率 \\
每日和=\sum当前存款数\times存款天数
$$


## 代码实现与解释

首先创建一个``Accumulator``类作为累加器, 用于存放每一次账户存取款时每日和存款

````cpp
// account.h

// 累加器类
class Accumulator
{
    // 上次操作日期
    Date lastDate;
    // 操作数额
    double value;
    // 和
    double sum;

public:
    // 累加器构造函数
    Accumulator(Date m_lastDate, double m_value);
    Accumulator();
    // 求和
    double getSum(Date m_date);
    // 数值刷新函数
    void change(Date m_lastDate, double m_value);
    // 数值重置函数
    void reset(Date m_lastDate, double m_value);

};
````

实现如下

````cpp
// account.cpp

double Accumulator::getSum(Date m_date)
{
    // 返回当期时间差
    sum+=m_date.distance(lastDate)*value;
    return sum;
}

// 数值改变函数
void Accumulator::change(Date m_lastDate, double m_value)
{
    getSum(m_lastDate);
    // 重新赋值
    lastDate=m_lastDate;
    value=m_value;
}

// 数值重设函数
void Accumulator::reset(Date m_lastDate, double m_value)
{
    sum=0;
    // 重设当前累加器数值
    change(m_lastDate, m_value);
}
````

每次存取款时, 对``Account``类中包含的累加器``acc``进行如下调用

````cpp
// account.cpp

// 存款函数
void SavingsAccount::deposit(Date m_date, double m_amount,string m_desc)
{
    // 更新累加器
    //  核心: 此处更新累加器时, 所使用的value应该是存款之前的账户总额, 因此使用balance作为value, 取款函数同理
    acc.change(m_date, m_amount+getBalance());  
    
    // 存入余额并打印信息
    record(m_date, m_amount, m_desc);
}
````

这样保证了每次存取款时刷新累加器, 计算变动前总日均累加和 (每日和),取款同理

````cpp
// 取款函数
void SavingsAccount::withdraw(Date m_date,double m_amount,string m_desc)
{
    // 取款数字需要改变为负数完成运算
    m_amount=-m_amount;

    // 更新累加器
    acc.change(m_date, m_amount+getBalance());  
    
    // 存入余额并打印信息
    record(m_date, m_amount, m_desc);   
}
````

在结算利息时, 首先更新累加器, 计算上次更新到结算利息期间的日均和, 然后根据总日均和计算利息, 最后调用存款函数, 将所得利息记入账户中并打印相关用户提示信息, 代码如下

````cpp
// account.cpp

#define SAVING_ACCOUNT_PERIOD 365	//设置平年天数

// 结算利息函数
void SavingsAccount::settle(Date m_date)
{
    // 利息
    double interest;

    // 更新累加器
    acc.change(m_date, getBalance());

    // 计算利息
  interest=set_precision_2(acc.getSum(m_date)/(SAVING_ACCOUNT_PERIOD+1)*rate);

    // 利息记入本金
    //  使用存款函数, 将利息存入本金
    deposit(m_date, interest, "interest");

}
````

