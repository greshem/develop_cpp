#include   <stdio.h>
int   f();
int   main()
{
	void   *p=reinterpret_cast <void   *> (f);
	int   (*pf)()=reinterpret_cast <int   (*)()> (p);
	printf( "%d\n ",pf());
	return   0;
}

int   f()
{
	return   123;
}
