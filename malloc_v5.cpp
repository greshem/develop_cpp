#include <stdlib.h>
//#include <MLmyUnit.hpp>
//qianzj 20100511 add block 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
using namespace std;
#define BLOCK 102400
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout<<"#Usage: "<<argv[0]<<" number Mbytes"<<endl;
		cout<<"#这里输入的数值是百兆"<<endl;
		cout<<"#程序一直会消耗内存直到 指定的数值, 或者系统内存耗尽"<<endl;
		exit(-1);
	}
	cout<<"malloc.cpp"<<endl;
	char *ptr;
	int i=0;
	long long  total=0;
	long long count_mb=atoi(argv[1]);  
	count_mb*=1024*1024;
	cout<<atoi(argv[1])<<"M"<<endl;
	while(1)
	{
		i++;
		ptr='\0';
		//ptr=(char *)malloc(1024*1024*1024);
		//ptr=(char *)new char[1024];
		ptr=(char *)malloc(BLOCK);
		memset(ptr, '1', BLOCK);	
		if(! ptr)
		{
			cout<<"malloc failuer "<<i<<endl;
			sleep(1);
		}
		else
		{
			total+=BLOCK;
			//nMB size 
			//printf("%d\n", total);
			if(total>= count_mb )
			{
				goto  tooBig;
			}
		}
		
	}
	
tooBig:
	cout<<"malloc mem big than "<<atoi(argv[1])<<"M"<<endl;
	string tmp;
	i=0;
	// while(1)
	// {
	// 	//std::cin>>tmp;
	// 	//cout<<tmp<<endl;
	// 	//sleep(1);
	// 	ptr=(char *)malloc(BLOCK);
	// 	
	// 	if(! ptr)
	// 	{
	// 		cout<<"malloc failuer "<<i<<endl;
	// 	}
	// 	else
	// 	{
	// 		//cout<<"another 100*"<<BLOCK<<"\t"<<i<<"\t times"<<endl;
	// 		free(ptr);
	// 	}
	// 	i++;
	// }
	
	cout<<"现在sleep 20秒"<<endl;
	sleep(20);
	return 1;
}
