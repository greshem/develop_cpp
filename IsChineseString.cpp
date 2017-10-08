#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
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
//#include <gtest/gtest.h>
//2010_09_03 by greshem. 


int IsChineseString(unsigned char *in, int len);
using namespace std;
int main(int argc, char *argv[])
{
	FILE *fp=fopen("/root/develop_txt/google_word.txt", "r");
	char buffer[1024];
	
	while(fgets(buffer, sizeof(buffer), fp))
	{
		if(IsChineseString((unsigned char *)buffer, strlen(buffer)))
		{
			printf("%s", buffer);
		}		
	}
	return 0;
}

int IsChineseString(unsigned char *in, int len)
{
	//unsigned char word;
	for(int i=0; i<len; i++)
	{
		if(in[i]>128  && in[i]<=255)
		{
			return 1;
		}
	}
	return 0;
}
