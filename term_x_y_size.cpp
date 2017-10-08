#include	<signal.h>
#include	<termios.h>
#ifndef	TIOCGWINSZ
#include	<sys/ioctl.h>	/* 44BSD requires this too */
#endif
//#include	"ourhdr.h"
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

static void	pr_winsize(int), sig_winch(int);

int
main(void)
{
	if (isatty(STDIN_FILENO) == 0)
		exit(1);

	if (signal(SIGWINCH, sig_winch) == SIG_ERR)
		perror("signal error");

	pr_winsize(STDIN_FILENO);	/* print initial size */
//	for ( ; ; )					/* and sleep forever */
//		pause();
}

static void
pr_winsize(int fd)
{
	struct winsize	size;

	if (ioctl(fd, TIOCGWINSZ, (char *) &size) < 0)
		perror("TIOCGWINSZ error");
	printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}

static void
sig_winch(int signo)
{
	printf("SIGWINCH received\n");
	pr_winsize(STDIN_FILENO);
	return;
}
