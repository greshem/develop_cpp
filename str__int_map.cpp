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
//map �Ĺ��캯���� û������������ʽ�ġ����������֪���� 
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
