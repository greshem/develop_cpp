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
	//virtual ~CA()
	~CA()
	{
		cout<<"CA����"<<endl;
	}
	 CA(int v) 
	{ 
		cout<<"CA����"<<endl;
		value=v; 
	} 
	int ReadValue() 
	{ 
		return value; 
	} 

}; 

//class CB:private CA 
class CB:public CA 
{ 
int total; 
public: 
	CB(int v,int t):CA(v) 
	{ 
		cout<<"CB����"<<endl;
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
	~CB()
	{
		cout<<"CB����"<<endl;
	}

}; 

//class CC:private CB 
class CC:public CB 
{ 
int count; 
public: 
	CC(int v,int t,int c):CB(v,t) 
	{ 
		cout<<"CC ����"<<endl;
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
	~CC()
	{
		cout<<"CC����"<<endl;
	}

}; 

int release( CC &a)
{
	cout<<"########enter release "<<endl;
	//������ײ�Ļ��๹�캯�����麯���� ֻ����� ~CA(),�����
	a.~CA();
	cout<<"########out release "<<endl;
	return 0;
}
int main( ) 
{ 
 	CC c(8,10,12); 
	cout<<"------------"<<endl;
	c.~CC();
	cout<<"------------"<<endl;
	c.~CC();
	cout<<"------------"<<endl;
	c.~CC();
	cout<<"------------"<<endl;
	release(c);
 return 0; 
} 
