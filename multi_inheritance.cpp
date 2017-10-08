

#include <stdio.h>

class t1 
{
	public:
	virtual void f() 
	{ puts("t1::f()"); 
	}
	virtual void g() { puts("t1::g()"); }
};

class t2 : public virtual t1 
{
public:
virtual void g() { puts("t2::g()"); }
};

class t3 : public virtual t1 
{
public:
virtual void f() { puts("t3::f()"); }
};

//class t4 : public t2, public t3, public virtual t1 { ...};
class t4 : public t2, public t3, public virtual t1
{
	
} ;

int main() 
{

t4 *tt4=new t4; t2 *tt2=tt4; t3 *tt3=tt4;

tt4->f(); tt4->g(); tt2->f(); tt3->g();
return 1;
} 
