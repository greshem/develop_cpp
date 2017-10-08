#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator> 
#include <vector> 
using namespace std;

class AddValue
{
public:
    AddValue(int v) : theValue(v) {}
    void operator() (int &elem) const  //�Ӳ��� & �����Ե�����  
    {
        elem += theValue;
    }
private:
    int theValue;
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int i;
    list<int> list_int(a, a+sizeof(a)/sizeof(a[0]));
	//����� 10 
    for_each (list_int.begin(), list_int.end(), AddValue(10));
	copy(list_int.begin(), list_int.end(), ostream_iterator<int>(cout, "\t"));
	cout<<endl;
	// �������10. 
   for_each (list_int.begin(), list_int.end(), bind1st(plus <int>(), 10)); 
	copy(list_int.begin(), list_int.end(), ostream_iterator<int>(cout, "\t"));
	cout<<endl;
  // transform (list_int.begin(), list_int.end(), list_int.begin(), bind2nd(plus <int>(), 10));        

    //cin >>i;
    return 0;
}

