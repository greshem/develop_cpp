#include <stdio.h>
#include <stdlib.h>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
//#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
#include <openssl/md4.h>

#define BUFSIZE 1024*16

void do_fp(FILE *f);
void pt(unsigned char *md);
#if !defined(_OSD_POSIX) && !defined(__DJGPP__)
int read(int, void *, unsigned int);
#endif

int main(int argc, char **argv)
        {
        int i,err=0;
        FILE *IN;

        if (argc == 1)
                {
                //do_fp(stdin);
                return 0;
                }
        else
                {
                for (i=1; i<argc; i++)
                        {
                        IN=fopen(argv[i],"r");
                        if (IN == NULL)
                                {
                                perror(argv[i]);
                                err++;
                                continue;
                                }
                        printf("MD4(%s)= ",argv[i]);
                        do_fp(IN);
                        fclose(IN);
                        }
                }
        exit(err);
        }

void do_fp(FILE *f)
        {
        MD4_CTX c;
        unsigned char md[MD4_DIGEST_LENGTH];
        int fd;
        int i;
        static unsigned char buf[BUFSIZE];

        fd=fileno(f);
        MD4_Init(&c);
        for (;;)
                {
                i=read(fd,buf,sizeof buf);
                if (i <= 0) break;
                MD4_Update(&c,buf,(unsigned long)i);
                }
        MD4_Final(&(md[0]),&c);
        pt(md);
        }

void pt(unsigned char *md)
        {
        int i;

        for (i=0; i<MD4_DIGEST_LENGTH; i++)
                printf("%02x",md[i]);
        printf("\n");
        }
