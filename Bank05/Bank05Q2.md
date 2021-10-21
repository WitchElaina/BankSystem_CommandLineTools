# 问题二

## 如何处理`query()`函数

### 前置工作

#### 创建账目记录类

使用账目记录类`AccountRecord`记录一条流水的日期, 账户, 时间, 交易数额等详细信息, 类构成如下

````cpp
// 账目记录类
class AccountRecord
{
    // 日期
    Date date;
    // 账户
    string* id;
    // 交易数额
    double amount;
    // 账户余额
    double balance;
    // 详细信息
    string desc;

public:
    // 构造函数
    AccountRecord(Date m_date, string* m_id, double m_amount, double m_balance, string m_desc);
    AccountRecord();
    void show();
};
````

#### 创建账目记录对象`recordMap`

在`Account.h`中声明`multimap`类对象`recordMap`记录账目变动信息, 将`键key`设置为`Date`类, `值value`设置成`AccountRecord`类

````cpp
// 账目记录
static multimap<Date, AccountRecord>recordMap;
````

每当有账目变动时, 使用`multimap`的方法`insert`插入一个键值对`pair<Date, AccountRecord>`以达到记录账目信息的目的.

```cpp
// 记录流水信息
void Account::record(Date m_date, double m_amount,string m_desc)
{
  //******
  
    AccountRecord m_account_record(m_date, &id, m_amount, getBalance(), m_desc);


    recordMap.insert(pair<Date, AccountRecord>(m_date, m_account_record));
}
```



### 函数实现

调用`query()`函数时, 需要传入参数`Date begin_date`和`Date end_date`作为信息展示的时间范围, 随后创建`multimap<Date,AccountRecord>`的迭代器`iterator`用于遍历存放账目的`recordMap`中的对象, 从`begin_date`开始到`end_date`截止, 每次循环都调用`AccountRecord`中的`show()`函数打印单条流水的信息, 即可实现历史流水查询的功能, 代码如下

````cpp
// 历史流水查询
void Account::query(Date begin_date, Date end_date)
{
    multimap<Date,AccountRecord>::iterator it;
    for(it=recordMap.begin();it!=recordMap.end();it++)
    {
        it->second.show();
    }
}
````

