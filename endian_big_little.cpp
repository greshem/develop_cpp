#include <stdlib.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <iterator>  
#include <vector> 
#include <iostream> 

#ifndef WINDOWSCODE
#include <unistd.h>
#endif

//2012_02_23 by greshem. 

using namespace std;
int swap(int input);
long long   swap_64(long long  input);
int main(int argc, char *argv[])
{
	int test=0x1;
	int revert= * ((char*)&test);
	if( revert  == 1)
	{
		printf("little endian \n");
	}
	else
	{
		printf("big endian %d \n", revert);
	}

	printf("0x%x\n", swap(0x01020304));
	printf("0x%lx\n", swap_64(0x0102030405060708));
	return 0;
}

int swap(int input)
{
	return( (input&0xff000000)>>24  | (input&0xff0000)>> 8 | (input&0xff00)<< 8 | (input&0xff) << 24);
}
long long   swap_64(long long  input)
{
	return( (input&0xff00000000000000) >>(7*8)|
			(input&0x00ff000000000000) >>(5*8)|
			(input&0x0000ff0000000000) >>(3*8)|
			(input&0x000000ff00000000) >>(1*8)|
			(input&0x00000000ff000000) <<(1*8)|
			(input&0x0000000000ff0000) <<(3*8)|
			(input&0x000000000000ff00) <<(5*8)|
			(input&0x00000000000000ff) <<(7*8));
}
