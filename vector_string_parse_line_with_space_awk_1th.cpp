
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <locale.h>
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <vector> 

using namespace std;

// from  /root/netware_emulator//tags/1.1/data_engine/conf_parser.cpp
static int build_vec_string_from_line_with_space(char *in, vector<string> &out)
{
#define WORD_CAPACITY 256
	char *word;
	char c;
	//int count=0;
	int word_capaticty=0;
	int last_word_is_space=1; //对于lr(1)语法必备的一个常量,  
	int pt=0;
	
	//word_capaticty = WORD_CAPACITY;
	word_capaticty = WORD_CAPACITY;
	word=(char *)malloc(word_capaticty);
	memset(word, 0, WORD_CAPACITY );
	
	//  if( isspace(in[0]) )
	// {
	//     last_word_is_space=1;
	// }
	
	while((c = *in))
	{
		if( c =='#')  goto out;
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

out:	
	if(last_word_is_space == 0 &&  c=='\0') //上一次的不是空格, 现在是空格了, 一个word 结束了.  
	{
		out.push_back(word);
	}
	if(word) {free(word);};

	return 1;
}

int main()
{
	
	vector<string>  output;
	build_vec_string_from_line_with_space("aa bb cc dd ee ff gg ", output );
	cout<<output[0]<<endl;
	cout<<output[1]<<endl;
}
