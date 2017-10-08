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
#include <iterator> 
#include <map>
using namespace std;

string RandString(int strLen)
{
    char *tmp;

    tmp=new char[strLen+1];
    tmp[strLen]='\0';
    
    for (int i=0; i< strLen; i++)
    {   
        *(tmp+i)='a'+rand()%26;
    }   
    string retStr(tmp);    
    delete[] tmp;
    return retStr;
}
vector<string> RandVecString(int strLen, int size)
{
    int i;
    vector<string> vecStr;
    for(int i=0; i< size; i++)
    {   
    
        vecStr.push_back(RandString(strLen));
    }   
    return vecStr;
}


/*##############################################################################
#把 vector<string> dump 到 txt文件， 把日志的规则导出到txt 文件。 
#
#
##############################################################################*/
int  DumpToFile(vector<string> &In, string FileName)
{
	ofstream output(FileName.c_str(),ios::out|ios::trunc);


//	ostream output(FileName);
	vector<string >::iterator it;
/*	for(it=In.begin(); it!= In.end(); it++)
	{
		output<< *it<<endl	;
	}*/
	copy(In.begin(), In.end(), ostream_iterator<string>(output, "\t"));
	output.close();
	return 1;
}

int main( int argc, char * argv[])
{
    vector<string> vecStr;
    vecStr =  RandVecString(10, 100);
    DumpToFile(vecStr, "error.txt");
    
}
