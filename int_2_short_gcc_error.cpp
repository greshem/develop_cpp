#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp> 
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_27 by qzj. 
//2010_07_27_18:15:22 add by qzj

//64λ������Ҫע�⣬ 64 λϵͳ�ϵ� char * ��64 λ�ģ� ������ת���� int
using namespace std;
struct info{int a;
			int b;};

int main(int argc, char *argv[])
{
	struct info test;
	int  b= (long long) (&test);
//	size_t b= ((void*)&test);
	short s=(short )b;
	
	s+=1;
	return 0;
}
