#include <asm/unistd.h>
//gcc hello_asm_gcc.cpp 

static inline void exit(int status)
{
  int __res;
  __asm__ volatile ("movl %%ecx,%%ebx\n"\
                    "int $0x80" \
                    :  "=a" (__res) : "0" (__NR_exit),"c" ((long)(status)));
}

static inline int write_1(int fd, const char * buf, int len)
{
  int status;
  __asm__ volatile ("pushl %%ebx\n"\
                    "movl %%esi,%%ebx\n"\
                    "int $0x80\n" \
                    "popl %%ebx\n"\
                    : "=a" (status) \
                    : "0" (__NR_write),"S" ((long)(fd)),"c" ((long)(buf)),"d" ((long)(len)));
  return status;
}

void _start(void)
{
    write_1(1, "Hello World\n", 12);
    exit(0);
}

int main()
{
	_start();
}
