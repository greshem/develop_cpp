#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

class AddValue
{
public:
    AddValue(int v) : theValue(v) {}
    void operator() (int &elem) const  //加不加 & 有明显的区别。  
    {
        elem += theValue;
    }
private:
    int theValue;
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    list<int> list_int(a, a+sizeof(a)/sizeof(a[0]));

    for_each (list_int.begin(), list_int.end(), AddValue(10));
   for_each (list_int.begin(), list_int.end(), bind1st(plus <int>(), 10)); 
  // transform (list_int.begin(), list_int.end(), list_int.begin(), bind2nd(plus <int>(), 10));        
    for (list<int>::iterator iter = list_int.begin(); iter != list_int.end(); iter++)
        cout << *iter << " ";
        

    //cin >>i;
    return 0;
}

