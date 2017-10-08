#include <iostream> 
#include <string> 
#include <vector> 
#include <iterator> 
#include <algorithm>

using namespace std;
string RandString(int strLen)
{
	char *tmp;

	tmp=new char[strLen+1];
	tmp[strLen]='\0';
	
    for (int i=0; i< strLen; i++)
    {   
        *(tmp+i)='a'+rand()%26;
    }  
    string retStr(tmp);		
	delete[] tmp;
	return retStr;
};

typedef struct info {
       int age;
       string name;
       info(int age, string name):age(age),name(name){};
       info()
       {};
       
       friend ostream & operator << (ostream &os, const info &in)
       {
              os<<in.age<<"||"<<in.name<<endl;
              return os;
       }
      info & operator = (const info &in)
       {    
                age=in.age;
                name=in.name;
                return *this;
       }
}INFO ;
       
       INFO randInfo()
       {
            return INFO(rand(), RandString(10));
       }
int main()
{
    //20091208 ע������ vec_info, ��ʼ����ʱ��û���ƶ���С�� �������generate_n ����ڴ������� this ָ��Ϊ0
    //�������� vec_info(100), ��Ϻ���� generate_n  n=100 �������  
      vector<info> vec_info(100); 
      int i=0;
      //vec_info.push_back(info(i,"w2enwen"));
      
      generate_n( vec_info.begin(), 100, randInfo);
     
      INFO a;
      //while(1)
      /*{
      a=randInfo();
      cout<<a<<endl;
      getchar();
      }*/
      cout<<"size "<<vec_info.size()<<endl;
      copy(vec_info.begin(), vec_info.end(), ostream_iterator<info>(cout," "));
      //getchar();
      //cout<<vec_info[0]<<endl;
      
}
