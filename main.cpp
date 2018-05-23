#include "minilogger.h"
#include<iostream>

//this is some example for using minilogger
int main(){
	//The contents of a logger will be putin the same log file with some title.
	//you can define your own Textdecorator and use it.
    Logger<TextDecorator> mylog("mylogfile.txt","this is title!",true,true);
    mylog.Log("this is log1.");
    mylog.Log("this is log2.");
	std::cout << "do something" << std::endl;
	mylog.Log("done something!");
	std::cin.get();
    return 0;

}