#include <stdlib.h>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
//#include <locale.h>
//#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
//#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
#include <list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char * rand_name(int size)
{    
   
	int i;
	char *tmp='\0';
	tmp=(char *)malloc(size+1);
	if (tmp=='\0')
	{
       printf("malloc error\n");
       return 0;
    }
	for (i=0;i < size; i++)
	{
		*(tmp + i) = 'a'+rand()%26;
	}	
	*(tmp +size) = '\0';
	printf("%s\n", tmp);
	return tmp ;
}

main()
{
//std::list <std::string > name_list; 
//name_list.push_front(std::string(rand_name(16)));
    int i;
    char *tmp;
    char buf[32];
//    srand((double)time('\0'));
 
     
    std::vector <std::string > name_vect; 
    for(int i = 0; i < 50; i++)
    {
      //printf("%x\n", rand_name(16));
      tmp =  rand_name(16);
     /* if(tmp != '\0')
      {
          name_vect.push_back( string(tmp) );
      }*/
         name_vect.push_back( tmp );
      // rand_name(16);
    }
    cout<<name_vect.size()<<endl;
    
    //cin >>i;
}
