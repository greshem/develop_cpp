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
typedef void (*_fun_ptr )(char *);
void my_printf(char *ptr)
{
	printf("%s\n", ptr);
}


typedef struct  _book
{
	int number;
	char name[64];
	_fun_ptr echo;
	//char *name;
} book;

book books[]=
{
	{1, "qianzhongje", my_printf},

	{2, "qianzhongje1" , my_printf},
	{3, "qianzhongje2" , my_printf},
	{4, "qianzhongje3" , my_printf},
	{5, "qianzhongje4" , my_printf},
	{0, {0}, 0}
};
int main(int argc, char *argv[])
{
	printf("%s\n", "main.c");
	book *ptr=books;
	for(;ptr->name[0]; ptr++)
	{
		ptr->echo(ptr->name);
	}
	return 1;
}
