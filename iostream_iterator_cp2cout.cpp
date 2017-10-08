#include <iterator>
#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    char a[] = "1212";
    cout.setf(ios_base::hex,ios_base::basefield);
    cout.setf(ios_base::uppercase);
    copy(a,a+sizeof(a)/sizeof(a[0]),ostream_iterator<int>(cout,"\n"));
    int i;
    //cin >> i;
}
