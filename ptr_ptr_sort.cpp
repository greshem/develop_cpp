#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#2010_09_08_15:10:07 add by greshem
//指针的指针的用法。 
void my_sort(char **p);
int main(int argc,char *argv[])
{
	char *line[256];
	FILE *fp;
	char tmp[256];
	int i=0;

	memset(line,'\0',4*256);

	if(argc!=2)
	{
		printf("Usage: %s file.txt\n", argv[0]);
		exit(0);
	}
	fp=fopen(argv[1],"r");
	while(fgets(tmp,sizeof(tmp),fp))
	{
		line[i]=strdup(tmp);	
		i++;
	}

	my_sort(line);
	for(i=0;i<256;i++)
	{
		if(line[i])
		{
			printf("%s",line[i]);
		}
	}
	return 0;
}
//########################################################################
//对指针数组进行排序。 
void my_sort(char **p)
{
	int i,j;
	char *pstr;
	for(i=0;i<256;i++)
	{ 
		for(j=i+1;j<256;j++)
		{
			if(*(p+i)&&*(p+j))
			{
				if(strcmp(*(p+i),*(p+j))>0)
				{
					pstr  =*(p+j);
					*(p+j)=*(p+i);
					*(p+i)=pstr;
				}
			}
		}
	}
}
