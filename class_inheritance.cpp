//��˽�������У���������г�Ա���������о�Ϊ˽�еġ����ԣ���
//�������ⲻ����ֱ��ʹ�û���̳й����ĳ�Ա�������������
//�ڲ������ڻ���̳й����ĳ�Ա��Ҳֻ��ֱ��ʹ���䱣���͹���
//���Եĳ�Ա��

//���¸Ľ������ο�
#include "iostream" 
using namespace std;
class CA
{ 
int value; 
public: 
	CA(int v) 
	{ 
		value=v; 
	} 
	int ReadValue() 
	{ 
		return value; 
	} 
}; 

class CB:private CA 
{ 
int total; 
public: 
	CB(int v,int t):CA(v) 
	{ 
		total=t; 
	} 
	int ReadTotal() 
	{ 
		return total; 
	} 
	int ReadValue1()
	{
		return ReadValue();
	}
}; 

class CC:private CB 
{ 
int count; 
public: 
	CC(int v,int t,int c):CB(v,t) 
	{ 
		count=c; 
	} 
	int ReadCount() 
	{ 
		return count; 
	} 
	int ReadTotal1()
	{
		return ReadTotal();
	}
	int ReadValue2()
	{
		return ReadValue1();
	}
}; 

int main( ) 
{ 
 CA a(2); 
 CB b(4,6); 
 CC c(8,10,12); 
 
 cout<<"value of a="<<a.ReadValue()<<endl; 
 cout<<"value of b="<<b.ReadValue1()<<endl; 
 cout<<"total of b="<<b.ReadTotal()<<endl; 
 cout<<"value of c="<<c.ReadValue2()<<endl; 
 cout<<"total of c="<<c.ReadTotal1()<<endl; 
 cout<<"count of c="<<c.ReadCount()<<endl; 
 return 0; 
} 
