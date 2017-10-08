#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#define ARRAYSIZE 1000  //取样点总数 （该值可以取100,1000,10000等，尽量100的整数倍）
unsigned int PersentCounter[ARRAYSIZE];
unsigned int SleepTime[ARRAYSIZE];
//该函数获取CPU核1毫秒可以进行加1计算的次数。（用于后续线程加1计算，让核忙！）
unsigned int OneMicroSecondCounter()
{
    struct timeval begin,end;
    unsigned int counter=0;
    unsigned int uTimeVal=0;
    gettimeofday(&begin,NULL); //取当前时间
    while(counter < 0x3FFFFFFF)
       counter++;
    gettimeofday(&end,NULL);
   //计算时间差：
    uTimeVal=(end.tv_sec-begin.tv_sec)*1000*1000+(unsigned int)(end.tv_usec-begin.tv_usec);
    printf("uTimeVal=%d\n",uTimeVal);
  if(uTimeVal != 0)
       return counter/uTimeVal;
    return 0;
}
        
//CPU 百分比忙线程：
void * CpuThread(void *arg)
{
   int nCoreIndex=*((int *)arg);
   unsigned int mask=1 << nCoreIndex;
   sched_setaffinity(0,sizeof(mask),&mask);
   unsigned int counter=0;
   int i=0;
   while(1)
   {
     i=(i+1)%ARRAYSIZE;
     counter=0;
     while(counter < PersentCounter[i])
          counter++;
     usleep(SleepTime[i]);
   }
}
int main()
{
  //获取CPU核数量：
   int nCoreNum=sysconf(_SC_NPROCESSORS_CONF);
   unsigned int period = 20; //取样周期为20秒
   float PI=3.1415926;
   unsigned int nTimeStep=period*1000*1000/ARRAYSIZE;
   int i=0; 
   unsigned int counter_unit=OneMicroSecondCounter();
   //根据正弦函数计算每个取样时间区间加1计算的数量，以及休眠时间：
   for(i =0; i < ARRAYSIZE; i++)
   {
      PersentCounter[i]=(unsigned int)(abs(sin(PI*2.0*i/ARRAYSIZE)*nTimeStep*counter_unit));
      SleepTime[i] =nTimeStep-abs(nTimeStep*sin(PI*2/ARRAYSIZE*i));
   }
   printf("unit counter:%u,nTimeStep:%u\n",counter_unit,nTimeStep);
   //根据CPU核数量，创建线程
   for(i =0; i < nCoreNum;i++)
   {
      pthread_t tid;
      pthread_create(&tid,NULL,CpuThread,&i);  //cpu 占用百分比运行线程
      sleep(1);
   }
  //防止主线程退出（否则4个子线程会自动退出！）
   while(1)
     sleep(1);
   return 0;
} 
