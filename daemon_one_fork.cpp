
//#2010_09_28_17:37:28 add by greshem
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#include <sys/stat.h>
#include <stringprep.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>


void init_daemon(void)
{
	int pid;
	int i;
	
	if((pid=fork()))
	{
		exit(0);//�Ǹ����̣�����������
	}
	else if(pid< 0)
	{
		exit(1);//forkʧ�ܣ��˳�
	}
	//�ǵ�һ�ӽ��̣���̨����ִ��
	
	setsid();//��һ�ӽ��̳�Ϊ�µĻỰ�鳤�ͽ����鳤
	//#2010_09_28_17:46:37 add by greshem
	//������ΪֻҪFORKһֱ�Ϳ����ˣ� ����ΪʲôҪFORK�����أ� 
	// //��������ն˷���
	// if((pid=fork()))
	// {
	// 	exit(0);//�ǵ�һ�ӽ��̣�������һ�ӽ���
	// }
	// else if(pid< 0)
	// {
	// 	exit(1);//forkʧ�ܣ��˳�
	// }
	// //�ǵڶ��ӽ��̣�����
	// //�ڶ��ӽ��̲����ǻỰ�鳤
	
	for(i=0;i< NOFILE;++i)//�رմ򿪵��ļ�������
		close(i);
	chdir("/tmp");//�ı乤��Ŀ¼��/tmp
	umask(0);//�����ļ�������ģ
	return;
}
//2�� test.c�嵥

void init_daemon(void);//�ػ����̳�ʼ������

int main()
{
	FILE *fp;
	time_t t;
	init_daemon();//��ʼ��ΪDaemon
	
	while(1)//ÿ��һ������test.log��������״̬
	{
		if((fp=fopen("test.log","a")) >=0)
		{
			t=time(0);
			fprintf(fp,"I'm here at %s\n",asctime(localtime(&t)) );
			fclose(fp);
		}

		sleep(60);//˯��һ����
	}
} 
