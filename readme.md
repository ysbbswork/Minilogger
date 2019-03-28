# Minilogger

Minilogger这是一个非常小巧的开源的c++日志工具，能实现在程序运行中随时将关键的事件通过log日志的方式保存在log文件中。

使用起来只需要在C++工程中将`minilogger.h`包含进来即可。

Minilogger支持以下内容：

- 自定义输出文件名称格式

- 自定义总日志标题

- 支持多个log文件按需要分类输出

- 可以自定义log的格式和排版

- 支持单日志的开启关闭时间

- 支持每条log记录发生时间

- 使用宏实现（具体详见example.cpp）：

  - 支持输出log的代码位置和函数名称
  - 支持参数输出到日志

  

# 使用

使用的时候只需要包含minilogger头文件到你的C++项目中就可以了，

使用示例：

```c++
#include "minilogger.h"

int main(){
    
    Logger<TextDecorator> mylog("mylogfile.txt","this is title!",true,true);//创建logger
    
    mylog.Log("this is log1.");//打log的方式和在控制台的log一样方便。
	
    return 0;
}
```

在输出的日志文件mylogfile.txt下：

```
[2018.05.23] [19:31:34] Session opened.
[2018.05.23] [19:31:34] this is log1.
[2018.05.23] [19:31:34] Session closed.
```

解释：

```c++
Logger<TextDecorator> mylog("mylogfile.txt","this is title!",true,true);
//创建logger，定义存储log的文件，如果文件不存在则自动创建，文件存在，往文件末尾追加log日志，
//true，true为是否为每一条log附加时间，日期，可以关闭，置为false。
//默认为日志的创建和结束追加时间日期
//每个logger对象可以对指定一个日志文件进行操作，一个logger下的内容都会被放入同一个log文件和标题下
//想要对不同事件分文件打log记录只需要多创建几个logger对象即可
```

logger是带一个装饰器的模板参数，默认的装饰器为TextDecorator

默认的TextDecorator装饰器，只是在每句话后加上换行，并对标题进行了横线分割，

用户也可以自定义装饰器得到自定义的日志类，

可以按照你自己的想法去扩展log装饰器TextDecorator类下的函数。

默认的装饰器TextDecorator：

```c++
class TextDecorator
{
public:
	static std::string FileHeader(const std::string& p_title)
	{
		return "==================================================\n" +
			p_title + "\n" +
			"==================================================\n\n";
	}

	static std::string SessionOpen()
	{
		return "\n";
	}

	static std::string SessionClose()
	{
		return "\n";
	}

	static std::string Decorate(const std::string& p_string)
	{
		return p_string + "\n";
	}
};

```



example中给出一种结合宏定义的方式输出：

- log所处代码行数
- log所处的函数名称
- 打印参数

```
[2019.03.28] [20:13:11] [example.cpp:main:34][LOG_NORMAL]test for LOG,args: number:[1], string:[yoyoyo]
[2019.03.28] [20:13:11] [example.cpp:myfunction:24][LOG_NORMAL]this is a log in function,a+b=3
```



# Minilogger

Minilogger Is a single-head log library for C++ applications. It is very mini, highly scalable and can be configured according to user requirements.

## Quick Start

```c++
#include "minilogger.h"
#include<iostream>
int main(){
    Logger<TextDecorator> mylog("mylogfile.txt","this is title!",true,true);//creat logger
    mylog.Log("this is log1.");//log something
    mylog.Log("this is log2.");//log otherthing
    return 0;
}
```

You can customize the format of the log through the text decorator

```c++
// ============================================================
// Here is an example of a simple log decorator, you can define your own decorator
// ============================================================
class TextDecorator
{
public:
	static std::string FileHeader(const std::string& p_title)
	{
		return "==================================================\n" +
			p_title + "\n" +
			"==================================================\n\n";
	}

	static std::string SessionOpen()
	{
		return "\n";
	}

	static std::string SessionClose()
	{
		return "\n";
	}

	static std::string Decorate(const std::string& p_string)
	{
		return p_string + "\n";
	}
};

```

Easy-to-use log classes, called minilogger.

Log example can log function name ,code line, and some args if you need.

```
[2019.03.28] [20:13:11] [example.cpp:main:34][LOG_NORMAL]test for LOG,args: number:[1], string:[yoyoyo]
[2019.03.28] [20:13:11] [example.cpp:myfunction:24][LOG_NORMAL]this is a log in function,a+b=3
```

