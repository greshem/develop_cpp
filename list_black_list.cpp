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

//�ڰ������ṹ
typedef struct
{
	byte	type;//0��ʾip��ַ��1��ʾ��ַ�ۺ���Ϣ��2��ʾ�û���
	int  AddTime;
	byte  AddReason;//��Ӧ�Ĺ���ID
	union
	{
		struct
		{
			unsigned long Ipaddr;	//ip��ַ
			byte ExInfo[32];	//������Ϣ
		};
		char UserName[32];//�û���
	};
    std::list <std::string > name_list; 
}tagListData;
//################################################################################

tagListData *ran_gen(char ch)
{
            tagListData *data;
            //ע��new malloc ֮�������. new �Ѿ��ѹ�ϵ�����������.  
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
