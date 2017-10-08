#include <functional>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
main()
{     int b;
      string  test;
      //b = (plus<int>)(33,44);
      plus<int> my_plus;
      minus<int> my_minus;
      multiplies <int> my_multi;
      divides <int> my_divides;
      modulus <int> my_modulus;
      equal_to <int> my_equal_to;
      greater <int>  my_greater;
      logical_and <int> my_logical_and;
      b = my_plus(33,33);
      cout<<b<<endl;
      cout<<my_equal_to(33,33);
//      test<<b<<endl;
//        b>>test;
      cout<<test<<endl;
      //cin >> b;
}
