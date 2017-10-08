#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>


using namespace std;

    typedef struct kmb {
        string a;
        string b;
    }stkmb;
    
    // 二元函数对象:查找编号，返回指针
    struct findWithoutTime : binary_function<kmb,string, bool>
    {
        bool operator()(const kmb & x, string y) const
        {
            if (x.a == y)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    };   

int rand_name(char *name, int size)
{
	int i;
	for (i=0; i< size; i++)
	{
		*(name+i)='a'+rand()%26;
	}	
	*(name+size)='\0';
	return 0;
}

main()
{
    char name[32];
    list<kmb>::iterator kmbiter;
    list<kmb> kmbList;
    int i;
 //   kmbList.push_front("1001");
    stkmb tmp;
    
    for(i=0; i<=100; i++)
    {rand_name(name, 8);
             tmp.a=string(name);
     rand_name(name, 16);
            tmp.b=string(name);
            kmbList.push_front(tmp);
    }
    
    tmp.a="qianlong";
    tmp.b="qianlong2";
    kmbList.push_back(tmp);
    
    string csTmp;
    csTmp="100";
   // for_each(kmbList.begin(),kmbList.end(), );
   for (kmbiter=kmbList.begin(); kmbiter!=kmbList.end(); kmbiter++)
   {
       cout<<(*kmbiter).a<<"     "<<(*kmbiter).b<<endl;
       
   }
    kmbiter = find_if(kmbList.begin(),kmbList.end(), bind2nd(findWithoutTime(),"qianlong"));
    if(kmbiter == kmbList.end())
    {
        cout<<"没找到"<<endl;
    }
    else
        cout<<"OK"<<endl;
    //cin >> csTmp;
    return 0;
}
