//########################################################################
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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int file;
	int i;
	int k,j;
	char buffer[1024*768];
	// if(file <0) 
	// {
	// 	perror("read");
	// } 
	for (i=0;i<=8;i++)
	{
		file=open("/dev/fb0",O_RDWR);
		if(file<0)
		{
			die<char>("open dev_fb0 error\n");
		}
		
		for(k=0;k<1024;k++)
		{
			for(j=0;j<=768;j++)
			{	
				if((k%100>50)||(j%100)>50)
				{
					buffer[k*768+j]=254;
				}
				else
				{
					buffer[k*768+j]=0;
				}
			}
		}
		
		if(write(file,buffer,sizeof(buffer))!=sizeof(buffer))
		{
			perror("write");
		}
		close(file);
	//	sleep(1);
	}
	
}
