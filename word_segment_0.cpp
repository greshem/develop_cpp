#include <vector> 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm> 
//需要一行一个WORD才可以. 
#define WORD_CAPACITY 256
#define CHARSTEP 16
using namespace std;
char* Get_Line(FILE *stream)
{
	if(stream==NULL)
	{	
		printf("file error\n");
		return NULL;
	}
	
	int c, numchars = 0, allocated = 0;
    char *s = NULL;
	
	//读取所有的字符
    for (c = getc(stream); (c != EOF) && (c != '\n'); c = getc(stream)) 
	{
        if (numchars == allocated)              
            s = (char *)realloc(s, (allocated += CHARSTEP) * sizeof (char)); //重新分配内存.
        s[numchars++] = (char) c;
    }
	
    if ((c == EOF) && (numchars == 0)) return NULL;
	
    if (numchars == allocated)                 
        s = (char *)realloc(s, (allocated += 2) * sizeof (char)); //重新分配内存.
    s[numchars++] = '\n';
    s[numchars] = '\0';
	
    return s;
	
}
//################################################################################
char *Get_word_from_line(char ** in, int size)
{
 //   printf("###########################################%s################\n", *in);
	char *word;
	int pt = 0;
    int word_capaticty=0;
//	int WORD_CAPACITY;
   word_capaticty = WORD_CAPACITY;
	word=(char *)malloc(WORD_CAPACITY);

	char c;
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
			if (c == '\n')  
			{
				(*in)++;
				break;
			}
		//	if (pt == 0) continue; /* nothing was read, start over */
			(*in)++;
			break;
		}
		word[pt++]=c;
		//	if (pt == fr->WORD_CAPACITY) { /* expand word size */
		if(pt == WORD_CAPACITY)
		{	
			word= (char *) realloc(word, 2* word_capaticty);
			word_capaticty*=2;
		}

		(*in)++;
    }
    
    word[pt]='\0';
	return word;

} 

int chomp(char *line, int size)
{
	if(size==0)
	{
		return -1;
	}
	while(size--)
	{
		if(line[size]=='\n')
		{
			line[size]='\0';
			break;
		}
	}
	return 1;
}
int main( int argc, char *argv[])
{	
	int i;
	char *tmp_word;
	char *ptr;
	char buf[256];
	string stence;
	vector<string> dict;
	FILE *fp=NULL;
	if(	(fp=fopen("rand_words.cpp", "r"))==NULL)
	{
		cout<<"open "<<argv[1]<<"error"<<endl;
		exit(-1);
	}
	while( fgets(buf, sizeof(buf), fp))
	{
	  chomp(buf, sizeof(buf));
	  ptr=buf;
//	  printf("%s\n", buf);
	  while((tmp_word = Get_word_from_line(&ptr, sizeof(buf))) != NULL )
	  {
 //        cout<<"push word"<<endl;
         cout<<tmp_word<<endl;
       dict.push_back(buf);
         free(tmp_word);
      }
	}
	
	cout<<"before unique size "<<dict.size()<<endl;
	sort(dict.begin(), dict.end());
	unique(dict.begin(), dict.end());
	
	cout<<"after unique size "<<dict.size()<<endl;
	
	
	for(i=0; i<=10; i++)
	{
//	   	stence+=dict[rand()%dict.size()];
//		stence+="\n";
	}
	cout<<stence<<endl;
	//cin >>i;
}
