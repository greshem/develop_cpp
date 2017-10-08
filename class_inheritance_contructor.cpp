//在私有派生中，基类的所有成员在派生类中均为私有的。所以，在
//派生类外不可以直接使用基类继承过来的成员，而在派生类的
//内部，对于基类继承过来的成员，也只可直接使用其保护和公有
//属性的成员。

//以下改进仅供参考
#include "iostream" 
using namespace std;
class CA
{ 
int value; 
public: 
	//virtual ~CA()
	~CA()
	{
		cout<<"CA构析"<<endl;
	}
	 CA(int v) 
	{ 
		cout<<"CA构造"<<endl;
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
		cout<<"CB构造"<<endl;
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
		cout<<"CB构析"<<endl;
	}

}; 

//class CC:private CB 
class CC:public CB 
{ 
int count; 
public: 
	CC(int v,int t,int c):CB(v,t) 
	{ 
		cout<<"CC 构造"<<endl;
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
		cout<<"CC构析"<<endl;
	}

}; 

int release( CC &a)
{
	cout<<"########enter release "<<endl;
	//假如最底层的基类构造函数是虚函数， 只会调用 ~CA(),奇怪了
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
