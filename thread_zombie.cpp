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
#include <pthread.h>
#include <assert.h>

void *start_routine (void *arg)
{
	while (1) {
		sleep (1);
		printf ("start_routine\n");
	}
	return NULL;
}

int main ()
{
	pthread_t   tid;
	pthread_create (&tid, NULL, start_routine, NULL);
	sleep (6);
	printf("after sleep 6 \n");
	pthread_detach (pthread_self ());//自我分离了
	pthread_exit (NULL);
	//return 0;
}
