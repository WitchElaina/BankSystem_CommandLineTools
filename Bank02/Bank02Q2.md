

# 问题二

## 计算两个日期相距的天数

### 闰年判断

众所周知, 当一个非**整百年的年份**能够被`4`整除时, 该年份为闰年; 当一个**整百**年份能被`400`整除时, 该年份为闰年.

在`Date`类中编写`isLeap`函数判断一个年份是否为闰年, 代码如下

```cpp
bool Date::isLeap(int m_year)
{
    if((m_year%100==0||m_year%400==0)&&(m_year%4==0||m_year%100!=0))
        return true;
    else
        return false;
}
```



### 建表

由于一年中每月天数不同, 在计算当年内两日期天数差时不方便, 可以采用建表查表的方法创建一个数组, 记录**每月一号到当年一月一号的天数**

程序中, 使用`DAYS_EACH_MONTH`数组存放这组数据

````
// date.h
const int DAYS_EACH_MONTH[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
````



### 计算相对日期

计算每个日期距离`1年1月1日`的天数, 再用欲求的两个日期的相对日期天数作减法, 算得两日期相距的天数. 

使用`date_trans`函数将一个`Date`类由绝对日期转换成相对日期

````cpp
// date.h
class Date
{
		// ...
public:
  	int date_trans();
  	// ...
}
````

计算`year年month月day日`的**相对日期**步骤如下

#### 计算年

首先计算`year年1月1日`距`1年1月1日`的天数差, 由于月日均相同, 至于要计算相差几年即可, 过程中需要注意, 闰年有`366`天, 判断该年为闰年时需要为总天数再`+1`

代码如下

````cpp
// date.cpp

int Date::date_trans()
{
    int day_sum=0;
  	
    for(int i=1;i<get_year();i++)
    {
      	// 每年增加365天
        day_sum+=365;
      	// 有闰年多加1天
        if(isLeap(i))
            day_sum++;
    }
  	// ...
````

#### 计算月

根据之前建立的`DAYS_EACH_MONTH`数组, 快速获得`month月1日`距离`1月1日`的天数并加入总和中

代码如下

````cpp
		// ...
		day_sum+=DAYS_EACH_MONTH[get_month()-1];
		// ...
````

#### 计算日

由于前面已经算得年月之间的日期差, 此时只需求出`year年month月1日`距离`year年month月day日`的天数差,  将日期中的`day`加入天数总和中即可

````cpp
		// ...
		day_sum+=get_day();

    return day_sum;
}
````



### 计算天数差

使用`date_trans`函数获得两日期的相对日期值, 再作差即可得到两日期的天数差

````cpp
// date.cpp
int Date::date_cal(Date m_date)
{
    return -m_date.date_trans()+date_trans();
}
````





 