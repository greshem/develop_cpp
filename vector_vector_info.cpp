#include <vector>
#include <iostream>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
using namespace std;

int rand_name(char *name, int max_size)
{
    
	int i;
	int size;
	
	size = rand() % max_size;
	for (i=0; i< size-1; i++)
	{
		*(name+i)='a'+rand()%26;
	}	
	*(name+i)='\0';
	return 0;
}


typedef struct {
       int a;
       char name[32];
}info;

int rand_info(info &in)
{
    
    in.a=rand();
    rand_name(in.name, sizeof(in.name));

    return 0;
}
int dump(const info &in)
{
              cout<<"a -> "<<in.a<<endl;
              cout<<"name -> "<<in.name<<endl;
//              in.a=5555;
			  return 1;
}

 int const  dump( const  info   *in) 
{
             cout<<"a -> "<<in->a<<endl;
             cout<<"name -> "<<in->name<<endl;
//              in->a = 5555;
			 return 1;
}
main()
{
      int i;
      info tmp;
      vector<info> man;
  //    man.push_back()
      for(i=0; i< 100; i++)
      {
         //rand_info(man[i]);
         rand_info(tmp);
         man.push_back(tmp);
      }
      
      for(i=0; i < man.size(); i++)
      {
         dump(man[i]);
      }
      //cin>> i;
      
      
}
