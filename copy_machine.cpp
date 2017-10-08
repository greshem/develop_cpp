/********************************************************************************************
* Description -  根据毁坏的 程度. 来选择 copy machine.
* Author -      qianzhongjie@gmail.com
* Date -        2011_03_11_16:14:27
* *******************************************************************************************/
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
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
class copyFactory
{
	private:
		string name;
	public:
		//virtual int copy()=0;

		virtual int copy()
		{
			cout<<"baseCopy  Is CopyNwo "<<endl;
			return 1;
		};
};

/****************************************************************************
* Description	 一次拷贝 一次拷贝失败 就退出, 不能用于拯救数据.  
* @param 	
* @return 	
****************************************************************************/
class DdCopy :public copyFactory
{
	public:
		int copy()
		{
			cout<<"DdCopy Is CopyNow"<<endl;
			return 1;
		}
};
/****************************************************************************
* Description	 拷贝文件但是都用 统一的字符填充， 这里根本不在乎文件里面的内容 只在乎 文件占用的空间.  
* @param 	
* @return 	
****************************************************************************/
class ZeroCopy :public copyFactory
{
	public:
		int copy()
		{
			cout<<"ZeroCopy Is CopyNow"<<endl;
			return 1;
		}
};

/****************************************************************************
* Description	硬盘出错的时候的拷贝工具 尽可能的还原数据. 
* @param 	
* @return 	
****************************************************************************/
class RescueCopy :public  copyFactory
{
		public:
		int copy()
		{
			cout<<"RescueCopy Is CopyNow"<<endl;
			return 1;
		}

};

/****************************************************************************
* Description	硬盘损坏 通过硬件进行拷贝
* @param 	
* @return 	
****************************************************************************/
class HareWareCopy :public  copyFactory
{
		public:
		int copy()
		{
			cout<<"HareWareCopy Is CopyNow"<<endl;
			return 1;
		}

};

int Do(copyFactory *ptr)
{
	ptr->copy();
	return 1;
}
/****************************************************************************
* Description	 获取磁盘损坏信息根据 数值.
* @param 	
* @return 	
****************************************************************************/
string get_damage_exentd_message(int damage)
{
	string str;	
	if(damage <0)
	{
		str= string("没有损坏");
	}
	else if (damage==0)
	{
		str=  string("不关心是否损坏,用zero填充");
	}
	else if(damage > 0 && damage< 50)
	{
		str= string ("硬盘有些扇区损坏");
	}
	else 
	{
		str=   string("硬盘遭受物理损坏");
	}
	return str;
}
/****************************************************************************
* Description	: 获取 当前的 copyMachine 只能初始化一次, 有些问题.   
* @param 	
* @return 	
****************************************************************************/
copyFactory *getInstace(int damage)
{
	static copyFactory *ptr=NULL;
	if(ptr==NULL)
	{
		if(damage <0)
		{
			ptr= new DdCopy;
		}
		else if (damage==0)
		{
			ptr= new ZeroCopy;
		}
		else if(damage > 0 && damage< 50)
		{
			ptr=new RescueCopy;
		}
		else 
		{
			ptr= new  HareWareCopy;
		}
	}	
	return ptr;
}
int main(int argc, char *argv[])
{
	
	if(argc !=2)
	{
		cout<<"Usage: "<< argv[0]<<" number" << endl; 
		cout<<"\t number repsent the_extent_of_damage "<<endl;
		exit(-1);
	}		
	int damage= atoi(argv[1]);
	for(int i=0;i<=100; i++)
	{
		damage++;
		copyFactory *cpMache=getInstace(damage);
		cout<< get_damage_exentd_message(damage)<<endl;
		cpMache->copy();	
	}
		
	return 0;
}
