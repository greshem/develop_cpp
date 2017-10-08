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
//2010_07_13 by qzj. 

int version;
using namespace std;
#define MAJ(x) 		((x>>8)<<24)
#define SEN(x) 		((x>>8)<<16)
#define BUILD(x) 	((x>>8)<<8)
#define SEQ(x)
#define VER(a,b,c,d) (((a&0xff)<<24) | ((b&0xff)<<16) |((c&0xff)<<8) | (d&0xff) )
int dump(int in)
{
	printf("%d.%d.%d.%d\n", (0xff000000&in)>>24, (0x00ff0000&in)>> 16, (0x0000ff00&in)>>8, (0x000000ff&in));
	return 1;
}

int main(int argc, char *argv[])
{
	int tmp = VER(1,2,3,4);
	printf("%d\n", tmp);
	dump(tmp);
	cout<<version<<endl;

	return 0;
}
