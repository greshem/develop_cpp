//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
#include <gtest/gtest.h>
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
class ClassA
{
	private:
		int data;
		static ClassA* ap;
	protected:
	ClassA(){};
	public:
		int Getdata();
		int Setdata(int m_data);
		static ClassA *Instance();
		~ClassA();
};

int ClassA::Getdata()
{
	return data;
}

int ClassA::Setdata(int m_data)
{
	data = m_data;
	return m_data;
}
ClassA* ClassA::Instance()
{
	if(ap == NULL)//Î´±»³õÊ¼»¯
	ap = new ClassA;
	//ap = (ClassA*)malloc(sizeof(ClassA));
	return ap;
}
ClassA::~ClassA()
{
	delete ap;
}

ClassA* ClassA::ap = NULL;

int main(void)
{
	ClassA *instance_a;
	instance_a = ClassA::Instance();
	int d = instance_a->Getdata();
	cout<<d<<endl;
	return 0;
}
