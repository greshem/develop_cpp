/********************************************************************************************
* Description -  class DdCopy :public copyFactory
*				 ��Ҫд��  class DdCopy : copyFactory
*							˽�м̳еĻ����� ���г�������ĺ���������. 
*							  copy1->copy(); ����ִ�����ʾ��. 
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
* Description	 һ�ο��� һ�ο���ʧ�� ���˳�, ����������������.  
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
* Description	 �����ļ����Ƕ��� ͳһ���ַ���䣬 ����������ں��ļ���������� ֻ�ں� �ļ�ռ�õĿռ�.  
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
* Description	Ӳ�̳����ʱ��Ŀ������� �����ܵĻ�ԭ����. 
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
