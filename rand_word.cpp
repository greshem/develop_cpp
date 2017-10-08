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

//生成的word 有被 截断的情况， 有点不爽， 需要改进, 生成的word 起码最少应该有 3 个字母以上。 
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
