

# 问题一

## 如何创建工程

### IDE中快速创建

打开**IDE**, 这里以Xcode为例

;<img src="/Users/msz/Library/Application Support/typora-user-images/image-20210923205202988.png" alt="image-20210923205202988" style="zoom:88%;" />

点击**Create a new Xcode project**按钮, 选择**Command Line Tool**创建一个基于C++编写的控制台项目

;<img src="/Users/msz/Library/Application Support/typora-user-images/image-20210923205336543.png" alt="image-20210923205336543" style="zoom: 88%;" />

即可创建工程, 或者手动创建. 

### 手动添加多个源代码到项目中

创建文件夹保存工程

````Bash
mkdir Project
cd Project
````

用文本编辑器新建源代码

````bash
# 创建主函数所在源代码
vim main.cpp

# 创建sccount类所在源代码
vim account.h
vim account.cpp
````

## 各个源代码的内容及其作用

``main.cpp``中包含以下代码

````cpp
#inlcude <iostream>
#include "account.cpp"
// ----
int main()
{
  // ......
}
````

``account.h``中包含``account.cpp``中类与方法的声明

````cpp
#ifndef account_h		// 预编译命令,必须添加
#define account_h

//----
class SavingsAccount
{
  //****
  SavingsAccount();
}

#endif
````

``account.cpp``中对上述声明进行实现

````cpp
#include "account.h"
SavingsAccoun::SavingsAccount()
{
  //****
}
````





