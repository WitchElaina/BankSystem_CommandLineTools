# 问题一

## 为什么使用静态成员函数

静态成员的作用域局部于类, 静态成员为类的多个对象提供了共享的成员, 系统需求一个账户类共享的成员`total`来记录系统总存款, 因此使用静态成员方便快捷地记录这一数据.



## 代码中使用位置及解释

代码中, 在`SavingsAccount`类中添加静态成员`total`用以记录存款总数, 相关代码如下

````cpp
// account.h

class SavingsAccount
{
public:
  	static double total;
}
````

存取款函数中, 每次完成操作后都要对`total`变量进行更新, 相关代码如下

````cpp
// account.cpp

// 账户变动记录辅助函数
void SavingsAccount::record(Date m_date, double m_amount)
{
    // ...
  	// 每次调用都会将存款变动数额加到total中
    total+=m_amount;
    // ...
}
````

