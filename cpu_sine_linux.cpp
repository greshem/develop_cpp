#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#define ARRAYSIZE 1000  //ȡ�������� ����ֵ����ȡ100,1000,10000�ȣ�����100����������
unsigned int PersentCounter[ARRAYSIZE];
unsigned int SleepTime[ARRAYSIZE];
//�ú�����ȡCPU��1������Խ��м�1����Ĵ����������ں����̼߳�1���㣬�ú�æ����
unsigned int OneMicroSecondCounter()
{
    struct timeval begin,end;
    unsigned int counter=0;
    unsigned int uTimeVal=0;
    gettimeofday(&begin,NULL); //ȡ��ǰʱ��
    while(counter < 0x3FFFFFFF)
       counter++;
    gettimeofday(&end,NULL);
   //����ʱ��
    uTimeVal=(end.tv_sec-begin.tv_sec)*1000*1000+(unsigned int)(end.tv_usec-begin.tv_usec);
    printf("uTimeVal=%d\n",uTimeVal);
  if(uTimeVal != 0)
       return counter/uTimeVal;
    return 0;
}
        
//CPU �ٷֱ�æ�̣߳�
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
  //��ȡCPU��������
   int nCoreNum=sysconf(_SC_NPROCESSORS_CONF);
   unsigned int period = 20; //ȡ������Ϊ20��
   float PI=3.1415926;
   unsigned int nTimeStep=period*1000*1000/ARRAYSIZE;
   int i=0; 
   unsigned int counter_unit=OneMicroSecondCounter();
   //�������Һ�������ÿ��ȡ��ʱ�������1������������Լ�����ʱ�䣺
   for(i =0; i < ARRAYSIZE; i++)
   {
      PersentCounter[i]=(unsigned int)(abs(sin(PI*2.0*i/ARRAYSIZE)*nTimeStep*counter_unit));
      SleepTime[i] =nTimeStep-abs(nTimeStep*sin(PI*2/ARRAYSIZE*i));
   }
   printf("unit counter:%u,nTimeStep:%u\n",counter_unit,nTimeStep);
   //����CPU�������������߳�
   for(i =0; i < nCoreNum;i++)
   {
      pthread_t tid;
      pthread_create(&tid,NULL,CpuThread,&i);  //cpu ռ�ðٷֱ������߳�
      sleep(1);
   }
  //��ֹ���߳��˳�������4�����̻߳��Զ��˳�����
   while(1)
     sleep(1);
   return 0;
} 
