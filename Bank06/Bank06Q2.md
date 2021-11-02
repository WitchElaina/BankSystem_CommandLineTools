# 问题二

## 如何处理用户新命令

定义文件输入输出流`fstream usr_cmd`, 并使用`usr_cmd.open("commands.txt",ios::app)`以追加方式打开存放历史指令的文件`command.txt`

在结构中, 读取用户输入的操作,  当操作不是退出`e`时即为有效操作,使用`usr_cmd<<cmd`存入`command.txt`中并给末尾追加空格,`usr_cmd<<" "`\

存入完成后正常进入`switch`执行指令即可

````cpp
do
{
  		cin>>cmd
      
      if(cmd!='e')
      {
        usr_cmd<<cmd;
        usr_cmd<<" ";
      }
    	//......
  		switch  (cmd) {
        case 'a': //....
          //....
      }
  	
} while(cmd != 'e')
````

$$
\varepsilon
$$

