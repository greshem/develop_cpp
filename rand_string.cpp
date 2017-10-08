#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#include <iostream> 
#include <algorithm>
#include <iterator> 
using namespace std;
string RandString(int strLen);
vector<string> RandVecString(int strLen, int size);

struct Print
{
	int operator() (string &in)
	{
		cout<<in<<endl;
		return 1;
	}
}myPrint ;
struct  addSuffix
{
        string m_suffix;
        addSuffix(string in):m_suffix(in){};
        int operator() ( string &in)
        {
            in+=m_suffix;
            return 1;
        }
};

int main(int argc, char *argv[])
{
	vector<string> vecStr =  RandVecString(10, 100);
	cout<<"size = "<<vecStr.size()<<endl;
	//for_each(vecStr.begin(), vecStr.end(), myPrint );
	sort(vecStr.begin(), vecStr.end());
	//for_each(vecStr.begin(), vecStr.end(), myPrint );
	for_each(vecStr.begin(), vecStr.end(), addSuffix(".mp3"));
	for_each(vecStr.begin(), vecStr.end(), addSuffix(".mp3"));
   copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "\n"));
//   getchar();
	return 0;
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
