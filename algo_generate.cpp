// 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

template <class TYPE > struct my_print
{
       int operator () (TYPE &in ) // &in in ��������. ע�� û������, �ؼ����� () ʵ����������.  
       {
                cout<<in<<endl;
                return 1;
       } 
};

main()
{     int i;
      my_print<int> print_my;
      vector<int> vec_int(10);
      cout<<vec_int.size()<<endl;
      //generate(vec_int.begin(), vec_int.end(), rand);
      generate_n(vec_int.begin(), 5, rand);
   //   print_my(1000);
      
      //transform(vec_int.begin(), vec_int.end(), my_print<int>() ); // ������ʽ����.  
      for_each(vec_int.begin(), vec_int.end(), my_print<int>() ); // ע��� ���߲���Ҳͬ��������.  
      //cin >> i;
}
