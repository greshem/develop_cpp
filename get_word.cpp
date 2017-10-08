#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <iostream>
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
#define  WORD_CAPACITY 32 
using namespace  std;
char *get_word_from_line(char ** in, int size)
{
 //   printf("###########################################%s################\n", *in);
	char *word;
	static int last_word_is_space=0;
	int pt = 0;
    int word_capaticty=0;
//	int WORD_CAPACITY;
   word_capaticty = WORD_CAPACITY;
	word=(char *)malloc(WORD_CAPACITY);

	char c;
	//防止死循环.  
	if(**in == '\0') 
	{
		return NULL;
	}	
	while(c = **in) 
    {
//        printf("start\n");
        //putchar(c);
 //       cout<<c<<endl;
		if (c == '\0' )//|| pt == size ) 
		{
			return NULL; 
		}/* end of file */
		if (isspace(c)) 
        {
		/*	if (c == '\n')  
			{
				(*in)++;
				break;
			}*/
		//	if (pt == 0) continue; /* nothing was read, start over */
			(*in)++;
			last_word_is_space=1;
			break;
		   //continue;
		}
		word[pt]=c;
		pt++;
		//	if (pt == fr->WORD_CAPACITY) { /* expand word size */
		if(pt == WORD_CAPACITY)
		{	
			word= (char *) realloc(word, 2* word_capaticty);
			word_capaticty*=2;
		}

		(*in)++;
		last_word_is_space=0;
    }
    
    word[pt]='\0';
	return word;

} 
int get_word(char *in, vector<string> &out)
{
   char *word;
   char c;
   int count=0;
   int word_capaticty=0;
   int last_word_is_space=1; //对于lr(1)语法必备的一个常量,  
   int pt=0;
   
   word_capaticty = WORD_CAPACITY;
   word=(char *)malloc(word_capaticty);
   memset(word, 0, WORD_CAPACITY );

 //  if( isspace(in[0]) )
  // {
  //     last_word_is_space=1;
  // }
   
  while(c = *in)
  {
      if(!isspace(c))
      {
       word[pt]=c;
       pt++;
       if(pt>=word_capaticty)
       {
            word= (char *) realloc(word, 2* word_capaticty);
			memset(word+word_capaticty,0,word_capaticty);
			word_capaticty*=2;
       }
       last_word_is_space=0;
      }
      else 
      {
          if(last_word_is_space == 0 ) //上一次的不是空格, 现在是空格了, 一个word 结束了.  
          {
            out.push_back(word);
            memset(word, '\0', word_capaticty);
            pt=0;
          }
          last_word_is_space=1;   
      }  
      in++;  
  }
  
  if(last_word_is_space == 0 &&  c=='\0') //上一次的不是空格, 现在是空格了, 一个word 结束了.  
  {
      out.push_back(word);
  }
  free(word);
  return 1;
}
main()
{
      char *tmp;
      FILE *fp;
      int i;
      char *start;
      char test[1];
      test[0]='\0';
      vector<string>  vec_string;
      vector<string>::iterator it;
 //     char line[1024]="0000000     1111   222                 333     444     555    666   7777    88888899999999999999999999999999999999999 \n";
      char line[1024];
      start=line;
/*      while( tmp = get_word_from_line(&start, sizeof(line)) )
      {
             //printf("%s", tmp);
             vec_string.push_back(tmp);
             free(tmp);
      }
      for(i=0;i<=10;i++)
      {
            vec_string.push_back(test);
            
      }*/
      fp=fopen("get_word.cpp", "r");
      if(fp == NULL)
      {
            cout<<"open the file error\n"<<endl;
            exit(-1);
      }
      while(fgets(line, sizeof(line), fp) )
      {
          vec_string.clear();
          get_word(line, vec_string);
          for(it = vec_string.begin(); it != vec_string.end(); it++)
          {
              cout<<*it<<endl;
          }
      }
      cout<<"sizeof vector<string>"<<vec_string.size()<<endl;
//      getchar();
}
