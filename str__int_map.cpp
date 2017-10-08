#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
using namespace std;
//map 的构造函数， 没有下面这种形式的。常看代码就知道了 
typedef map<string, int>  strIntMap;
typedef struct 
{
	struct key;
	strIntMap value;
}MapMap;
int main(int argc, char *argv[])
{
	cout<<"str_Int_map.cpp"<<endl;

	//strIntMap a=strIntMap(string("qianqian"),33333);;
	strIntMap *a=new map<string, int> ;
	a->insert((pair<string, int>(string("qianqian"),33333)));
	//a.push(
	return 0;
}
