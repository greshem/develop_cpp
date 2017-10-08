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
//#2011_04_27_ 星期三 add by greshem

// 返回行的字符串的长度.
int escape_string(char* buf, const char* str, int str_len)
{
  const char* str_end = str + str_len;
  char* buf_start = buf;
  
  for(; str < str_end; ++str)
    {
      char c = *str;
      if(c == '\'' || c == '"' || c == '\\')
        {
          *buf++ = '\\';
        }
      *buf++ = c;
    }
  return (int)(buf - buf_start);
}

int main()
{
	char tmp[]="this \" is the one \n";	
	char output[1024]={0};
	int len=escape_string(output, tmp, strlen(tmp));
	printf("%s\n", output); 
}

