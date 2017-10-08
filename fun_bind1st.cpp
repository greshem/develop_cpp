#include <functional>
#include <iostream>
using namespace std;
bool print(int i, int j) 
{
    cout<< i << "---" << j << endl; 
    return i>j;
}
int main(int argc, char *argv[])
{   int j;
    (std::bind2nd(std::ptr_fun(print), 2))(1);
    (std::bind1st(std::ptr_fun(print), 2))(1);
    //cin>>j;
    return 0;
}
