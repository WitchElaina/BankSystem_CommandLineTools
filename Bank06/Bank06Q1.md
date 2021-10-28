# 问题一

## 如何处理`command.txt`中的命令

### 判断`command.txt`是否存在

如果`command.txt`不存在, 则说明程序第一次被运行, 没有存入历史 指令,因此无需读入`command.txt`, 判断代码如下:

创建`bool`变量`rec`存放**是否需要读取历史指令的真值**, 创建文件输入输出流`fstream`并使用`open()`方法打开文件, 如果打开成功`rec`赋值`true`,否则为`false`

````cpp
fstream usr_cmd;
bool rec;
usr_cmd.open("commands.txt", ios::in);

if(!usr_cmd)
{
  // cout<<"Error! No command history!"<<endl;
  usr_cmd.close();
  rec=false;
}
else
{
  // cout<<"Recovering commands history..."<<endl;
  usr_cmd.close();
  rec=true;
  usr_cmd.open("commands.txt", ios::in);
}
````



### 处理指令及空格

#### 处理指令

`command.txt`中按行存放指令, 每条指令的第一个字符为**操作类型**, 第二个字符为**操作参数**, 比如`a s S3755217 0.015`这条指令, `a`为操作创建账户, 剩余的`s S3755217 0.015`为操作参数`账户类型`,`账户ID`,`账户利率`

对于这种`操作 操作参数`结构的命令,选用`switch-case`结构, 首先读取`操作`,进入对应操作分支,随后按照操作读取`操作参数`, 执行即可.

#### 处理空格

使用`fstream usr_cmd` 对象的运算符`>>`可以将数据以空格隔开传入变量中,每次读取时首先执行`usr_cmd>>cmd`,传入操作类型,根据`char cmd`的数值进入相应的操作分支`case`, 随后执行`usr_cmd>>op_value1>>op_value2>>/*....*/`陆续读取操作参数,完成当前行读取后使用`break`,在外层循环中继续读取下个操作, 代码如下

````cpp
// Recovery
while (rec) 
{

  char type;
  int index, day;
  double amount, credit, rate, fee;
  string id, desc;
  Account* account;
  Date date1, date2;

  if(!(usr_cmd>>cmd))
  {
    break;
  }

  switch (cmd) {
    case 'a'://增加账户
      usr_cmd >> type >> id;
      if (type == 's') {
        usr_cmd >> rate;
        account = new SavingsAccount(date, id, rate);
      }
      else {
        usr_cmd >> credit >> rate >> fee;
        account = new CreditAccount(date, id, credit, rate, fee);
      }
      accounts.push_back(account);
      break;

    case 'd'://存入现金
      usr_cmd >> index >> amount;
      getline(usr_cmd, desc);
      accounts[index]->deposit(date, amount, desc);
      break;

    case 'w'://取出现金
      usr_cmd >> index >> amount;
      getline(usr_cmd, desc);
      accounts[index]->withdraw(date, amount, desc);
      break;

    case 's'://查询各账户信息
      for (size_t i = 0; i < accounts.size(); i++) {
        cout << "[" << i << "] ";
        accounts[i]->show();
        cout << endl;
      }
      break;

    case 'c'://改变日期
      usr_cmd >> day;
      if (day < date.getDay())
        cout << "You cannot specify a previous day";

      else if (day > date.getMaxDay())
        cout << "Invalid day";

      else
        date = Date(date.getYear(), date.getMonth(), day);
      break;

    case 'n'://进入下个月
      if (date.getMonth() == 12)
        date = Date(date.getYear() + 1, 1, 1);
      else
        date = Date(date.getYear(), date.getMonth() + 1, 1);
      for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
        (*iter)->settle(date);
      break;

    case 'q'://查询一段时间内的账目
      date1 = Date::read();
      date2 = Date::read();
      Account::query(date1, date2);
      break;

  }
}

usr_cmd.close();
````

### 特殊空格

需要注意的是, **账目描述变量**`string desc`中可能包含有空格, 如`get salary`, 但是不能将这个变量按空格分开,否则会影响后面的读取, 又因为每种指令中, 账目描述总是作为最后一个操作参数出现的, 因此在读取账目描述变量时, 直接使用`getline(usr_cmd, desc)`即可将整个字符串存放到`desc`中,完成操作.