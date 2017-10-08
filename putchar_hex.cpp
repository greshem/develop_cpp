//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  

using namespace std;

int char2HexStr(unsigned char *tmp, int size);

int main(int argc, char *argv[])
{
	char tmp[]={ 255, 254, 253, 252};
	
	char2HexStr((unsigned char *)tmp, sizeof(tmp));
	return 0;
}

void putCharHex( char *tmp, int size)
{
	for (int i=0; i<size ; i++)
	{
		//putchar(tmp[i]);
		write(1, tmp+i, 1);
	}
}
int char2HexStr(unsigned char *tmp, int size)
{
	unsigned char low;
	unsigned char high;
	char num2hex[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd' ,'e' , 'f'};
	for(int i=0; i<size;i++)
	{
		low=tmp[i]%16;	
		high=(tmp[i]-low)/16;
		//low+='0';
		//high+='0';
		write(1, num2hex+high, 1);
		write(1, num2hex+low , 1);
	}	
	putchar('\n');
	return 1;
}
