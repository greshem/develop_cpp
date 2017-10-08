//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
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

class random
{
public:
	void  print()
	{
		cout<<"random base print"<<endl;
	};
};

class HexRandom:public random
{
public:
	void print() 
	{
		cout<<"HexRandom"<<endl;
	}
};

class AsciiRandom:public random
{
public:
	void print()
	{
		cout<<"Ascii random"<<endl;
	}
};

class RandName :public AsciiRandom
{
public:
	void print()
	{
		char buf[256]={0};
		int i=rand()%32;
		for(int j=0;j<i;j++)
		{
			buf[j]='A'+rand()%26;	
		}
		cout<<buf<<endl;
	}
};

int MyPrint(class RandName &in)
{
	in.print();
	return 1;
}
int MyPrint(class random &in)
{
	in.print();
	return 1;
}
int MyPrint(class random *in)
{
	in->print();
	return 1;
}

int main()
{
	timeval tv;

	gettimeofday(&tv, NULL);
	srandom(tv.tv_usec);
	//AsciiRandom asciiRnd;
	//asciiRnd.print();
	//HexRandom hexRnd;
	
	RandName rndName;	
	//MyPrint(asciiRnd);
	//MyPrint(hexRnd);
	MyPrint(rndName);
}
