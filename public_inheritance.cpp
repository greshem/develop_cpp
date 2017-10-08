/********************************************************************************************
* Description -  class DdCopy :public copyFactory
*				 不要写成  class DdCopy : copyFactory
*							私有继承的话不能 进行抽象出来的函数调用了. 
*							  copy1->copy(); 会出现错误提示了. 
* Author -      qianzhongjie@gmail.com
* Date -        2011_03_11_15:43:20
* *******************************************************************************************/
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
//
////
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
class FastCopy :public copyFactory
{
	public:
		int copy()
		{
			cout<<"FastCopy Is CopyNow"<<endl;
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

int Do(copyFactory *ptr)
{
	ptr->copy();
	return 1;
}

int main(int argc, char *argv[])
{
	//DdCopy dd;
	//dd.copy();
	// FastCopy *copy1=new FastCopy();
	// DdCopy  *copy2=new DdCopy;
	// FastCopy  *copy3=new FastCopy;

	copyFactory  *copy1=new FastCopy();
	copyFactory  *copy2=new DdCopy;
	copyFactory  *copy3=new FastCopy;
	copyFactory  *copy4=new copyFactory;


	Do(copy1);
	Do(copy2);
	Do(copy3);
	Do(copy4);
	
	//  copy1->copy();
	//  copy2->copy();
	//  copy3->copy();
	//  copy4->copy();
	return 0;
}
