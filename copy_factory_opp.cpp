/********************************************************************************************
* Description -  ���ݻٻ��� �̶�. ��ѡ�� copy machine.
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

/****************************************************************************
* Description	Ӳ���� ͨ��Ӳ�����п���
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
* Description	 ��ȡ��������Ϣ���� ��ֵ.
* @param 	
* @return 	
****************************************************************************/
string get_damage_exentd_message(int damage)
{
	string str;	
	if(damage <0)
	{
		str= string("û����");
	}
	else if (damage==0)
	{
		str=  string("�������Ƿ���,��zero���");
	}
	else if(damage > 0 && damage< 50)
	{
		str= string ("Ӳ����Щ������");
	}
	else 
	{
		str=   string("Ӳ������������");
	}
	return str;
}
/****************************************************************************
* Description	: ��ȡ ��ǰ�� copyMachine ֻ�ܳ�ʼ��һ��, ��Щ����.   
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
