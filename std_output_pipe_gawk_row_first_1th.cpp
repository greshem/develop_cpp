
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
  ���л�����ע����. 
  �ǿ��� ���� 0; 
  ���� ����ע���� ����1 ;
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
* Description: ��ע���� ���߿�����, ��Ҫ���� ��Ҫ��������. 
* @param 	
* @return : Ĭ�ϵ�ע�ͷ����� '#'	
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
				//��Ч��.
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
* Description	 ȥ�����з�, ����ȡ��perl . 
* @param 	
* @return 	
* @notice : ֻ��ȥ��һ��\n
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
* Description	��ȡ�ļ���һ��. 
* @param 	
* @return 	
* @notice:   ���ܺ�fgets һ��, ���Ի��ǽ���ʹ��fgets��.ϵͳ�Դ���. ����. 
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
	
	//��ȡ���е��ַ�
    for (c = getc(stream); (c != EOF) && (c != '\n'); c = getc(stream)) 
	{
        if (numchars == allocated)              
            s = (char *)realloc(s, (allocated += CHARSTEP) * sizeof (char)); //���·����ڴ�.
        s[numchars++] = (char) c;
    }
	
    if ((c == EOF) && (numchars == 0)) return NULL;
	
    if (numchars == allocated)                 
        s = (char *)realloc(s, (allocated += 2) * sizeof (char)); //���·����ڴ�.
    s[numchars++] = '\n';
    s[numchars] = '\0';
	
    return s;
	
}


/****************************************************************************
* Description: ��һ����������, ���ص�vector<string> ����ȥ, �Կո���Ϊ�ָ���, ���������� # ����ľ��Թ���. 
* @param   : in ������	
* 			 out ����� vector<string> 
* @return 	
* @notice:  ������ĺ��������У� �ж��ַ��ǲ��Ƿ���������ʱ��, ת����һ��. 
****************************************************************************/
static int build_vec_string_from_line_with_space(char *in, vector<string> &out)
{
	char *word;
	char c;
	//int count=0;
	int word_capaticty=0;
	int last_word_is_space=1; //����lr(1)�﷨�ر���һ������,  
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
			if(last_word_is_space == 0 ) //��һ�εĲ��ǿո�, �����ǿո���, һ��word ������.  
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
	if(last_word_is_space == 0 &&  c=='\0') //��һ�εĲ��ǿո�, �����ǿո���, һ��word ������.  
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
		if(begin_with_comment_or_empty_line(buffer, sizeof(buffer)))  //ע����.
		{
			continue;
		}
		else
		{
			vector<string> array;
			// һ�к����ע����.  ������ʱ��Ӧ��ȥ�� . 
			build_vec_string_from_line_with_space(buffer, array); // һ�зָ�� vector<string> 
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
