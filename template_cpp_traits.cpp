#include <iostream>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
using namespace std;

class CComplexObject // a demo class
{
public:
    void clone() { cout << "in clone" << endl; }
};

template <typename T, bool isClonable>   class Traits
{
};

template <typename T>    class Traits< T, true>
{
public:
	void clone(T* pObj)
	{
		cout << "before cloning Clonable type" << endl;
		pObj->clone();
		cout << "after cloning Clonable type" << endl;
	}
};

template <typename T > class Traits< T, false>
{
public:
	void clone(T* pObj)
	{
		cout << "cloning non Clonable type" << endl;
	}
};


// Solving the problem of choosing method to call by inner traits class
template <typename T, bool isClonable>  class XContainer
{
public:
    enum {Clonable = isClonable};

    void clone(T* pObj)
    {
        Traits<T, isClonable>().clone(pObj);
    }

};

int main()
{
    int* p1 = 0;
    CComplexObject* p2 = 0;

    XContainer<int, false> n1;
    XContainer<CComplexObject, true> n2;

    n1.clone(p1);
	cout<<"###############################################################################"<<endl;
    n2.clone(p2);
	return 0;
}
