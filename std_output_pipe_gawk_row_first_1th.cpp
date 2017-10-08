
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "template_tools.h"
#include "conf_parser.h"
#include "data_dict_comment.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <assert.h> 

using namespace std; 

#define CHARSTEP 256
#define  WORD_CAPACITY 32 



/*
  空行或者是注释行. 
  非空行 返回 0; 
  空行 或者注释行 返回1 ;
*/

static void TrimLeft(char * String)
{
	register int				errorcode;
	register int				offset = 0;
	register int				i;
	
	errorcode = strlen(String);
	for ( i=0;i<=errorcode-1;i++ )
	{
		if ( String[i] != ' ' && String[i] != 0x09 && String[i] != 0x0D && String[i] != 0x0A )
		{
			offset = i;
			break;
		}
	}
	
	if ( offset != 0 )
	{
		memmove(String,String + offset,errorcode - offset);
		String[errorcode - offset] = 0;
	}
}

static void TrimRight(char * String)
{
	register int				errorcode;
	register int				i;
	
	errorcode = strlen(String);
	for ( i=errorcode-1;i>=0;i-- )
	{
		if ( String[i] != ' ' && String[i] != 0x09 && String[i] != 0x0D && String[i] != 0x0A )
		{
			String[i+1] = 0;
			return;
		}
	}
	
	String[0] = 0;
}

/****************************************************************************
* Description: 是注释行 或者空行吗, 需要跳过 不要解析的行. 
* @param 	
* @return : 默认的注释符号是 '#'	
****************************************************************************/
static int begin_with_comment_or_empty_line(const char * in, int size)
{
	int last_word_is_space=1;
	int i=0;
	char c;
	char comment_char='#';
	while((c = *in))
	{
		if(isspace(c))
		{
			last_word_is_space=1;
		}
		else
		{
			if(c== comment_char)
			{
				return 1;
			}
			else
			{
				//有效行.
				return 0;
			}
		}
		in++;
		i++;
		if( i >= size)
		{
			break;
		}	
	}
	return 1;
}

/****************************************************************************
* Description	 去除换行符, 名字取自perl . 
* @param 	
* @return 	
* @notice : 只能去除一个\n
****************************************************************************/
static int  chomp( char *line, int size )
{
	if (size == 0)
	{
		return -1;
	}     
	while(size--)
	{
		if(line[size] == '\n') 
		{
			line[size]='\0';
			break;
		}
	}
	return 1;
}


/****************************************************************************
* Description	获取文件的一行. 
* @param 	
* @return 	
* @notice:   功能和fgets 一样, 所以还是建议使用fgets吧.系统自带的. 方便. 
****************************************************************************/
static char* Get_Line(FILE *stream)
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


/****************************************************************************
* Description: 从一行数据里面, 返回到vector<string> 里面去, 以空格作为分隔符, 假如碰到了 # 后面的就略过了. 
* @param   : in 输入行	
* 			 out 输出的 vector<string> 
* @return 	
* @notice:  是上面的函数的特列， 判断字符是不是符合条件的时候, 转换了一下. 
****************************************************************************/
static int build_vec_string_from_line_with_space(char *in, vector<string> &out)
{
	char *word;
	char c;
	//int count=0;
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

int  parse_file(string file, vector<vector<string> >  &output )
{

	output.clear();
	FILE *fp=fopen(file.c_str(), "r");
	char buffer[1024];
	if(fp==NULL)
	{
		//die<char>("open file error\n");
		cout<<"open file error"<<file<<endl;
		return 0;
	}

	while(fgets(buffer, sizeof(buffer), fp))
	{
		if(begin_with_comment_or_empty_line(buffer, sizeof(buffer)))  //注释行.
		{
			continue;
		}
		else
		{
			vector<string> array;
			// 一行后面的注释项.  解析的时候应该去掉 . 
			build_vec_string_from_line_with_space(buffer, array); // 一行分割成 vector<string> 
			output.push_back(array);		
		}
	}
	fclose(fp);
	return 1;
}; 

int  dump(vector<vector<string> >  & data)
{
		typedef 	 vector<vector<string> >::iterator X; 
		X x;
		typedef  vector<string>::iterator Y; 
		Y y;

		for(X x=data.begin(); x!=  data.end(); x++)
		{
			for( y=(*x).begin();  y!= (*x).end(); y++)
			{
				cout << (*y)<<" ";
			}
			cout<<endl;
		}
}

int  get_1th_row(vector<vector<string> >  & data,  vector<string> &output)
{
		typedef 	 vector<vector<string> >::iterator X; 
		X x;
		typedef  vector<string>::iterator Y; 
		Y y;

		output.clear();
		for(X x=data.begin(); x!=  data.end(); x++)
		{
			output.push_back((*x)[0] );
			cout<<(*x)[0]<<endl;
		}
}


int main()
{
	vector< vector< string> >  data;	
	vector< string>   row_1th;
	parse_file("/etc/nwserv.conf",data);
	//dump(data);
	get_1th_row(data, row_1th);
}
