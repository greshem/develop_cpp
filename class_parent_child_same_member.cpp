/********************************************************************************************
* Description -  子类 和父类 里面 有名字重名的情况. 
* Author -      qianzhongjie@gmail.com
* Date -        2011_03_11_16:39:39
* *******************************************************************************************/
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
using namespace std;
//========================================================================
class copyFactory
{
	private:
		string name;
	public:
		//virtual int copy()=0;
		copyFactory():name("base default name"){};
		copyFactory(string a):name(a){};
		virtual int copy()
		{
			cout<<"baseCopy  Is CopyNwo "<<endl;
			return 1;
		};
		void getName()
		{
			cout<<"baseFactory_Name: "<<name<<endl;
		}
};
//------------------------------------------------------------------------
class DdCopy :public copyFactory
{
	private:
		string name;
	public:
		DdCopy(string a):name(a){};
		DdCopy(string a, string b ):copyFactory(b),name(a){};
		int copy()
		{
			cout<<"DdCopy Is CopyNow"<<endl;
			return 1;
		}
		void getName()
		{
			cout<<"DdCopy_Name: "<<name<<endl;
		}

};
//########################################################################

using namespace std;
int main(int argc, char *argv[])
{
	DdCopy dd("linux_dd", "cp_line");
	dd.getName();
	dd.copyFactory::getName();
	return 0;
}
