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
#include <gtest/gtest.h>
//2010_08_25 by qzj. 

struct WinImeHead {
    char mName[12];
    int mMaxCodes;
    char mCodeSet[47];
    char mWildChar;
};

int main(int argc, char *argv[])
{

	WinImeHead head;
	
	assert(sizeof(head)==( 12+4+47+1));
	MFile <char> file;
	if(file.Open("winpy.mb")!=1)
	{
		return 0;
	}

	file.Read((char*)&head, sizeof(head));
	printf("%s\n", head.mName);

	cout<<"mMaxCodes "<<head.mMaxCodes<<endl;
	printf("%s\n", head.mCodeSet);
	printf("len of codeset %d\n", strlen(head.mCodeSet));
	printf(" mWildChar %d\n", head.mWildChar);
	
	char **index=(char **)malloc(26* sizeof(char*));
	
	file.Read( (char*)index, 26*sizeof(char*));	
	for(int i=0;i<26;i++)
	{
		printf(" %c %d\n", i+'a', index[i]);
	}

	
	
	char **index2= (char **) malloc(26*26*sizeof(char *));
	if(index2==NULL)
	{
		die<char>("ÄÚ´æ·ÖÅä´íÎó");
	}	
	file.Read((char*)index2, 26*26*sizeof(char *));

	long long  textOffset=sizeof(head)+26*sizeof(char *)+26*26*sizeof(char *);
	assert(textOffset == file.GetCurOffset());
	printf("Text offset %d\n", textOffset);
	for(int i=0; i<26; i++)
	{
		for(int j=0; j<26; j++)
		{
			if( (long long ) index2[26*i+j] !=  -1)
			{
				printf("#########################\n");
				printf("%c %c %d \n", i+'a', j+'a',  index2[26*i+j]);
									
				//printf("fseek_and_print  %d %d\n", textOffset+(int) index2[26*i+j] , (int) index2[26*i+j+1] - (int)index2[26*i+j]);

			}
		}
	}		
	return 0;
}
