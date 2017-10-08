#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
void Show(double v)
{

    cout << v << ' ';
}
double multipiles( int a , int b)
{
       return a*b;
}

main()
{
int i;
list<double>  prod(10);
list<double>  gr8;

gr8.push_back(1);
gr8.push_back(2);
gr8.push_back(3);
gr8.push_back(4);
gr8.push_back(5);
gr8.push_back(6);



 //transform(gr8.begin(), gr8.end(), prod.begin(),bind1st(std::ptr_fun(multiplies),2.5) );
 //copy(gr8.begin(), gr8.end(), prod.begin());
 copy_backward(gr8.begin(), gr8.end(), prod.begin());
 // cout << "prod:\t";

 for_each(prod.begin(), prod.end(), Show);
 //cin >> i;
}
