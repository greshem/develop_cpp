#include <iostream>
#include <string.h>
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

using namespace std;

void multiply(const char *a,const char *b); 

int main()
{
    //cout<<"hicjiajia"<<endl;
    
    string num1,num2;     // ��ʼ״̬��string���洢����
    cout<<"���ڣ������������ɣ� "<<endl;
    cin>>num1>>num2;
    
    const char *p1=num1.c_str();    // ��stringתΪ const char *
    const char *p2=num2.c_str();    // ��stringתΪ const char *
    multiply(p1,p2);
    
    //system("pause");
    return 0;
} 

void multiply(const char *a,const char *b)
{
     int i,j,ca,cb,*s;
     ca=strlen(a);
     cb=strlen(b);
     s=(int *)malloc(sizeof(int)*(ca+cb));   //����洢�ռ�
     for (i=0;i<ca+cb;i++) s[i]=0;      // ÿ��Ԫ�ظ���ֵ0
     
     for (i=0;i<ca;i++)
         for (j=0;j<cb;j++)
             s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
             
     for (i=ca+cb-1;i>=0;i--)        // ����ʵ�ֽ�λ����
         if (s[i]>=10)
         {
             s[i-1]+=s[i]/10; 
             s[i]%=10;
         }
     
     char *c=(char *)malloc((ca+cb)*sizeof(char));  //�����ַ�����ռ䣬��Ϊ����int����ʡ��
     i=0;while(s[i]==0) i++;   // ����ͷ��0Ԫ��
     for (j=0;i<ca+cb;i++,j++) c[j]=s[i]+'0';
     c[j]='\0';
     for (i=0;i<ca+cb;i++) cout<<c[i];
     cout<<endl; 
     free(s);
}
