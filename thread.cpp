#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include  <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//2010_06_30 by qzj. 
using namespace std;
static 
void * __stdcall work( void *in)
{

	int i;
	i=*(int *)in;
	//while(1)
	for(int i=0;i<3; i++)
	{
		printf("%d\n", i);
		i++;
#ifdef WINDOWSCODE
		Sleep(1000);
#else
		sleep(1);
#endif
	}
	return '\0';
}
int main(int argc, char *argv[])
{
	MThread<char> thread;
	int a=100;
	int b=1000;
	thread.StartThread("test1", work, &a);
	thread.StartThread("test2", work, &b);
	return 0;
}
