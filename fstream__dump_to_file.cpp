#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#include <iostream> 
#include <algorithm>
#include <fstream> 

using namespace std;

vector<string> RandVecString(int strLen, int size);
int  DumpToFile(vector<string> &In, string FileName);
string RandString(int strLen);
int main(int argc, char *argv[])
{
	cout<<"fstream.cpp"<<endl;
	vector<string> vecStr=RandVecString(10, 100);
	DumpToFile(vecStr, "output.txt");
	return 0;
}
//########################################################################
int  DumpToFile(vector<string> &In, string FileName)
{
	ofstream output(FileName.c_str(),ios::out|ios::trunc);
//	ostream output(FileName);
	vector<string >::iterator it;
	for(it=In.begin(); it!= In.end(); it++)
	{
		output<< *it<<endl	;
	}
	output.close();
	return 1;
}

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
//	int i;
	vector<string> vecStr;
	for(int i=0; i< size; i++)
	{
		
		vecStr.push_back(RandString(strLen));
	}
	return vecStr;
}
