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
//2010_07_06 by qzj. 

//���ɵ�word �б� �ضϵ������ �е㲻ˬ�� ��Ҫ�Ľ�, ���ɵ�word ��������Ӧ���� 3 ����ĸ���ϡ� 
using namespace std;
int main(int argc, char *argv[])
{
	MFile<char>  word;
#ifdef WINDOWSCODE
	srand(100);
#else
	srandom(getpid());
#endif
	word.Open(MString<char> ("/usr/share/dict/linux.words"));
	int size=word.GetFileLength();
	for(int i=0; i<10;	i++)
	{
		word.Seek(rand()%size, SEEK_SET);
		//cout<<word.ReadString()<<endl;
	}
	return 0;
}
