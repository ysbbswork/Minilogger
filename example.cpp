#include "minilogger.h"
#include<iostream>
#include<string>

using namespace std;

#define LOG(fmt, args...)	do{\
			char _buf[1024] = {0};\
			snprintf(_buf, sizeof(_buf), "[%s:%s:%d][LOG_NORMAL]"fmt"\n",__FILE__,__FUNCTION__,__LINE__, ##args);\
			mylog.Log(string(_buf));\
		}while(false)



//you can define your own Textdecorator and use it.
Logger<TextDecorator> mylog("mylogfile.txt","this is title!",true,true);

void myfunction(){
    //test LOG in function
    //
    int a = 1;
    int b = 2;

    LOG("this is a log in function,a+b=%d",a+b);
}


//this is some example for using minilogger
int main(){
    //log with no args.
    mylog.Log("this is log.");
	std::cout << "do something" << std::endl;
    // log with args and function name and line number.
	LOG("test for LOG,args: number:[%d], string:[%s]",1,"yoyoyo");

    myfunction();
	std::cin.get();
    return 0;

}
