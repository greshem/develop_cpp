#ifdef WINDOWSCODE
#include <io.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define O_RDONLY 0x0000
#else
#include <sys/fcntl.h>
#include <unistd.h>
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
#endif

#include <sys/types.h>
#include <sys/stat.h>

typedef struct 
{
	double total;
	double idle;
}CPU_SAMPLE;

/****************************************************************************
* Description	
* @param
* @return 	
* @notice errorcode��������ÿ�λ�ȡ��total ,idle��ֵ��tempptr,nextptr
* ���������ȡ�ļ�ʱ��ָ��λ��	
****************************************************************************/
int GetCPUSample(CPU_SAMPLE &cpu_sample_in)
{
    char                tempbuf[8192];
    char                *   tempptr;
    char                *   nextptr;
    double              errorcode;
    int                 fd;

    #ifdef WINDOWSCODE
     _snprintf(tempbuf, 32, "/proc/stat");
    #else
    snprintf(tempbuf, 32, "/proc/stat");
    #endif
    if ((fd = open(tempbuf, O_RDONLY, 0) ) == -1 )
    {
        return -1;
    }
    else
    {
        int num = read(fd, tempbuf, sizeof tempbuf - 1);
        if(num < 0)
        {
        	close(fd);
        	return -1;
        }
        if ( (tempptr = strstr(tempbuf,"cpu")) == NULL )
        {
    		close(fd);
        	return  -1;
        }
        else
        {
            tempptr += 3;
            errorcode = strtol(tempptr,&nextptr,10);
            cpu_sample_in.total+=errorcode;
            tempptr = nextptr;

            errorcode = strtol(tempptr,&nextptr,10);
            cpu_sample_in.total+=errorcode;
            tempptr = nextptr;

            errorcode = strtol(tempptr,&nextptr,10);
            cpu_sample_in.total+=errorcode;
            tempptr = nextptr;

            errorcode = strtol(tempptr,&nextptr,10);
            cpu_sample_in.total+=errorcode;
            tempptr = nextptr;

            cpu_sample_in.idle =errorcode;
    		
			close(fd);
  			return 0;
        }
    }
}

/****************************************************************************
* Description	
* @param 
* @return 	
* @notice flag_is_first���ڱ��ÿ���β�����Ϊһ�����ݣ������β���������ǰ���β�����ֵ 	
* fixme: һ��Ҫ��  flag_is_first ����õ���cpu������ֵ�ܴ�������
****************************************************************************/
bool DiffLargeThanNSecond(int sec)
{
    static int flag_is_first = 0;
	static long last_time = 0;
    long current_time = 0;
    if(0 == flag_is_first)
    {
        last_time = time(NULL);
        flag_is_first++;
    }
    current_time = time(NULL);
    if((current_time - last_time) < sec)
	{
		return true;
	}
	else
	{
        flag_is_first = 0;
		return false;
	}
}
/****************************************************************************
* Description	
* @param 	
* @return 	
* @notice ����ǵ�һ�β������ò���ֵ��
* ����ǵڶ��β��������������β�����ֵ���м���	
****************************************************************************/
float  GetCPUPercent(void)
{
    static float last_cpu_usage = 0;
	static CPU_SAMPLE cpu_sample_last;
	static CPU_SAMPLE cpu_sample_current;
    
    if(DiffLargeThanNSecond(2))
	{
		GetCPUSample(cpu_sample_last); 
        return last_cpu_usage;
    }
    else
    {
        GetCPUSample(cpu_sample_current);
		double sample_total_diff = cpu_sample_current.total-cpu_sample_last.total;
		double sample_idle_diff = cpu_sample_current.idle-cpu_sample_last.idle;		
        last_cpu_usage = (100*(sample_total_diff - sample_idle_diff))/(sample_total_diff);

        cpu_sample_last.total = cpu_sample_current.total;
        cpu_sample_last.idle= cpu_sample_current.idle;
        return last_cpu_usage;
    }
}

int main()
{
	while(1)
	{
		printf("��ǰϵͳCPU ������Ϊ %.3f%\n",GetCPUPercent());
		sleep(5);
	}
	return 0;
}

