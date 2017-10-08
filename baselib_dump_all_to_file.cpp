#include <algorithm>
#include <dirent.h>
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
//#include <gtest/gtest.h>
//2010_11_25 by greshem. 


using namespace std;

string RandWord(int strLen=8)
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
void RandWord(int  count, vector<string> & output)
{
	int i=0;
	for(i=0; i<count; i++)
	{
		string tmp= RandWord(8);
		output.push_back( tmp);
	}
}


/****************************************************************************
* Description	
* @param 	
* @return 	
* *************************************************************************/
//template <class T>  
int dump_all_to_file( vector<string> &in , string FileName, int append=1)
{
    //typedef typename T::iterator IT; 
	ofstream output(FileName.c_str(), (append==0)?(ios::out|ios::trunc):(ios::out|ios::app));

	//########################################################################
	// 下面的定义的方式有点累赘了， 	
	// if(append!=0)
	// {
	// 		ofstream output(FileName.c_str(), ios::out|ios::trunc);
	// }
	// else
	// {
	// 		ofstream output(FileName.c_str(), ios::out|ios::app);
	// }

    vector<string>::iterator  it; 
    for(it=in.begin(); it!= in.end(); it++)
    {   
        output<<*it<<endl;
    }   
    return 1;
}


int main(int argc, char *argv[])
{
	vector<string> vecStr;//=RandWord(100);
	RandWord(100,  vecStr);
	dump_all_to_file(vecStr, "list.list");
	return 0;
}

