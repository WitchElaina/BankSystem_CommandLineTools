# 问题二

## settle函数如何处理

````cpp
// 结算函数
void CreditAccount::settle(Date m_date)
{
    // 利息
    double interest;

    // 年费
    bool annual_fee=false;

    // 更新累加器
    acc.change(m_date, getBalance());

    // 计算利息
    interest=set_precision_2(acc.getSum(m_date)*rate);
    withdraw(m_date, -interest, "interest");
    
    // 判断是否需要交年费
    if(m_date.get_year()!=a_date.get_year())
    {
        annual_fee=true;
    }
  
    // 将利息与年费记入消费记录
    if(annual_fee)
        withdraw(m_date, CREDIT_ACCOUNT_ANNUAL_FEE, "annual fee");
    
}
````

首先使用`Accumulator`类中的`change(Date,double)`函数更新累加器, 求出账户截止计算日期的**每日和**, 然后使用`getSum(Date)`函数计算**利息**, 随后判断是否需要缴纳**年费**, 完成结算.

> 涉及到的`Accumulator`类中的方法代码如下
>
> ````cpp
> // 求和
> double Accumulator::getSum(Date m_date)
> {
>     // 返回当期时间差
>     sum+=m_date.distance(lastDate)*value;
>     return sum;
> }
> 
> // 数值改变函数
> void Accumulator::change(Date m_lastDate, double m_value)
> {
>     getSum(m_lastDate);
>     // 重新赋值
>     lastDate=m_lastDate;
>     value=m_value;
> }
> ````

