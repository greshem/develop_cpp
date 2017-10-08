#include <stdlib.h>
#include <list>
#include <iostream>
#include <iterator>
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
//#include "../auth.h"
//#include "../MDateTime.cpp"

typedef unsigned char byte ;
//################################################################################

//黑白名单结构
typedef struct
{
	byte	type;//0表示ip地址，1表示地址综合信息，2表示用户名
	int  AddTime;
	byte  AddReason;//对应的规则ID
	union
	{
		struct
		{
			unsigned long Ipaddr;	//ip地址
			byte ExInfo[32];	//其他信息
		};
		char UserName[32];//用户名
	};
    std::list <std::string > name_list; 
}tagListData;
//################################################################################

tagListData *ran_gen(char ch)
{
            tagListData *data;
            //注意new malloc 之间的区别. new 已经把构系函数处理掉了.  
  //          data=(tagListData *)malloc(sizeof(tagListData)); 
		      data = new tagListData;
 //          memset(data,ch, sizeof(tagListData));
            printf("%d\n", sizeof(tagListData));
            return(tagListData*) data;
}
//################################################################################

char *rand_name(int size)
{
	int i;
	char *string;
	string=(char *)malloc(size);
	for (i=0;i<=size;i++)
	{
		*(string+i)='a'+rand()%26;
	}	
	*(string+size)='\0';
	return string;
}
//################################################################################
using namespace std;
main()
{
      char *name2;
      
      std::list <tagListData * > data; 
      data.push_front( ran_gen('a'));
      data.push_front( ran_gen('b'));
      data.push_front( ran_gen('c'));
      data.push_front( ran_gen('d'));
      
      std::list<tagListData*>::iterator it = data.begin();
	  if( it != data.end() )
		// std::cout <<(*it)->UserName<<std::endl;
      
      //name2=rand_name( 16);
      //printf("%s\n", name2);
      //((*it)->name_list).push_front(std::string(name2));
	  for (int i=0; i<=100; i++)
	  {  
			((*it)->name_list).push_front(string("qianlong")+string("i"));
	  }
	  
	  //list<std::string>::iterator  it_list;
      copy( ((*it)->name_list).begin(), ((*it)->name_list).end(), ostream_iterator<string>(cout, "\n"));
      
      
      //getchar();
      
}
