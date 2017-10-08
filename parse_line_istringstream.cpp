
//#2011_04_14_ 星期四 add by greshem

#include <iostream> 
#include <sstream> 
using namespace std; 

class data {
public:
	int a;
	float b;


    friend ostream &  operator << (ostream &out , const data &in)
	{
		out<<"a="<<in.a<<"|";
		out<<"b="<<in.b<<endl;	
		return out;
	}

	friend istream & operator >> (istream &is , data &in)
	{
		return 	is >> in.a >> in.b;
	}

	//friend 
};
int main()  
{ 
	istringstream istr; 
	istr.str("1 56.7  1 56.7 1 56.7 1 56.7 1 56.7 1 56.7 1 56.7 1 56.7 1 56.7 1 56.7 1 56.7  1 "); 
	//上述两个过程可以简单写成 istringstream istr("1 56.7"); 
	
	cout << istr.str()<<endl; 

	data tmp;
	// istr >> tmp.a;	
	// istr >> tmp.b;
	//
	while(	istr >> tmp)
	{
		cout<< tmp;
	}

	cout<<tmp;
} 

