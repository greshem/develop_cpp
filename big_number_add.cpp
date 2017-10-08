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

int reverse_str(char *input)
{
	int len=strlen(input);
	int i=0;
	for( i=0; i<len/2; i++)
	{
		char tmp=input[i];
		input[i]=input[len-1-i];
		input[len-1-i]=tmp;	
	}
}

//#include <stringprep.h>
//
//1231232131123569
//9999999999999999
//大数的加法 , 这里只处理他们 长度相等的情况  
void  add_math(unsigned char*number1, unsigned char *number2)
{
	char output[1024]={0};	
	int len1= strlen((char*)number1);
	int len2= strlen((char*)number2);
	unsigned int carry=0;
	int count=0;
	assert(len1>= len2);
	for(int i=0;i<len1;i++)
	{
		unsigned int tmp=0;
		if((len2-i)>0) //游标还在 nubmer2 中 
		{
			tmp= number1[len1-1-i];
			tmp+=number2[len2-1-i];
			tmp-='0';
			tmp-='0';
		}
		else
		{
			tmp=number1[len1-1-i]-'0';
		}

		if(tmp>=10)
		{
			output[count]=tmp-10 +'0'+carry;
			carry=1;
		}	
		else
		{
			if(tmp==9 && carry==1)
			{
				output[count]=tmp+carry+'0'-10;
				carry=1;
			}
			else
			{
				output[count]=tmp+carry+'0';
				carry=0;

			}

		}
		count++;
	}		

	if(carry!=0)
	{
		output[count]=1+'0';
	}

	reverse_str(output);
	printf("%s+%s=%s\n", number1, number2, output);
}


int main()
{
	add_math((unsigned char*)"99998888888", 	 (unsigned char*)"22");
	add_math((unsigned char*)"99998888888", 	 (unsigned char*)"1");
	add_math((unsigned char*)"12345678", 	 (unsigned char*)"1");
	add_math((unsigned char*)"12345679", 	 (unsigned char*)"1");
	add_math((unsigned char*)"123456799999999999999999999999999998", 	 (unsigned char*)"1");
	add_math((unsigned char*)"123456799999999999999999999999999999", 	 (unsigned char*)"11111111111111");
}
