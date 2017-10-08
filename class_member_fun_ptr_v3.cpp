//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include<iostream>
#include<string>
using namespace std;

class gong;
typedef void(gong::*f_ptr)();
int test(f_ptr hook, int i);

class gong
{
private:
	string str;
public:
	string aaa;
	gong(string a):str(a){cout<<"call the constructor function~"<<endl;};
	~gong(){cout<<"call the deconstructor function~"<<endl;}
	void up()
	{
	cout<<str<<"\t up function ok "<<endl;
	}
	void down()
	{
	  cout<<str<<"\tdown function ok"<<endl;
	}
	void left()
	{
	  cout<<str<<"\tleft function ok"<<endl;
	}
	void right()
	{
	  cout<<str<<"\tright function ok"<<endl;
	}

};

int test(f_ptr hook=&gong::down, int i=0)
{
	gong a("qianzhongje");
	(a.*hook)();
return 1;
}
int main()
{ 
//定义成员指针
typedef string gong::*str_ptr;
//typedef string gong::*string;
//str_ptr test =gong::aaa;
//定义成员函数的指针数组
test();
}

int test3()
{
f_ptr move[4]={&gong::up,&gong::down,&gong::left,&gong::right};
string dire;
gong cls_gong("qiznzhongjie ");

cout<<"请输入你要移动的方向:up,down,left,right"<<endl;
cin>>dire;
while(dire=="up"||dire=="UP"||dire=="down"||dire=="DOWN"||dire=="left"||dire=="LEFT"||dire=="right"||dire=="RIGHT")
{
	if(dire=="up"||dire=="UP")
	   	(cls_gong.*move[0])();
	if(dire=="down"||dire=="DOWN")
		(cls_gong.*move[1])();
	if(dire=="left"||dire=="LEFT")
		(cls_gong.*move[2])();
	if(dire=="right"||dire=="RIGHT")
		(cls_gong.*move[3])();
	cout<<"请选择下次你要移动的方向"<<endl;
	cin>>dire;
}
	 return 1;
}
