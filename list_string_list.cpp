#include <stdlib.h>
#include <list>
#include <iostream>
#include <string>
#include <vector>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <stringprep.h>
char *rand_name(int size)

{    
   
	int i;
	char *string='\0';
	string=(char *)malloc(size);
	if (string=='\0')
	{
       printf("malloc error\n");
       return 0;
    }
	for (i=0;i<=size;i++)
	{
		*(string+i)='a'+rand()%26;
	}	
	*(string+size)='\0';
	printf("%x\n", string);
	return string;
}

main()
{
//std::list <std::string > name_list; 
//name_list.push_front(std::string(rand_name(16)));
printf("%d\n",sizeof(char *));
rand_name(16);
rand_name(32);
rand_name(64);
#ifdef WINDOWSCODE
	srand(100)
#else
	 srandom((double)time('\0'));
#endif
    std::vector <std::string > name_vect; 
    for(int i=0; i<20; i++)
    {
   //    name_vect.push_back(std::string(rand_name(16)));
         name_vect.push_back( "aaaaaaaaa" );
         // rand_name(16);
    }
   // getchar();
}
