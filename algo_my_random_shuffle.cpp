/*template<typename _Distance>
    inline _Distance
    __random_number(_Distance __n)
    {
      return rand() % __n;
    }*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <iostream> 

        using namespace std;

template <class TYPE > struct my_print
{
       int operator () (TYPE &in ) // &in in ��������. ע�� û������, �ؼ����� () ʵ����������.  
       {
                cout<<in<<endl;
                return 1;
       } 
};
int my_rand(int n)
{
    return rand() % n;
};
template <class TYPE > struct rand3
{
         rand3(int test):a(test)
         {};
       TYPE  operator () (int a) //// &in in ��������. ע�� û������, �ؼ����� () ʵ����������.  
       {
             return rand();
       }
       TYPE a;
};

  template<typename _Distance>
    inline _Distance
   my_rand(_Distance __n)
    {

      return rand() % __n;
    };
class rand2
{
      public:
       rand2()
       {
       };
       int operator () (int n )
       {
           return rand()%n;
       }
}
;
main()
{
#ifdef WINDOWSCODE
	srand(100);
#else
        srandom(time(NULL));
#endif
        
        int i;
        vector<int> vec_int;
        //��������º����� һ��Ҫ�ȳ�ʼ���ſ��ԣ� Ϊʲô�� my_print<int> �Ϳ��Բ���ʼ���Ϳ���ʹ���أ�  
        rand2 test;
        for( i=0; i <= 20; i++)
        {
              vec_int.push_back(i);
        }
         // random_shuffle( vec_int.begin(), vec_int.end(), test);
         //�������ʼ���� �����С�  
           random_shuffle( vec_int.begin(), vec_int.end(), my_rand<int>);
        //  random_shuffle( vec_int.begin(), vec_int.end(), my_rand);
          //random_shuffle( vec_int.begin(), vec_int.end());      
        for_each(vec_int.begin(), vec_int.end(), my_print<int>() );
        
        //cin >>i;
}
