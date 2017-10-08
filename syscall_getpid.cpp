//#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef WINDOWSCODE
#include <windows.h>
#else
#include <sys/types.h>
#include "syscall.h"
#endif

int main(int argc, char *argv[])
{
#ifdef WINDOWSCODE
	printf("%d\n", GetCurrentProcessId());
#else
	pid_t tid;
	tid = syscall(SYS_gettid);
	printf("%d\n", tid);	
#endif
}

