#include <stdio.h>
#include <magic.h>
int main(int argc, char *argv[])
{
	int i;
	magic_t magic;
	const char *str;
	magic=magic_open(MAGIC_NONE);
	if(magic==NULL)
	{
		printf("Error:: out of memory\n");
		return 1;
	}
	if(magic_load(magic,NULL)==-1)
	{
		printf("Error: %s\n", magic_error(magic));
		return 1;
	}
	for( i=0; i< argc; i++)
	{
		if( (str=magic_file(magic, argv[i])) ==NULL)
		{
			printf("Error: %s\n", magic_error(magic));
		}
		else
		{
			printf("%s: %s\n", argv[i], str);
		}
	}
}
