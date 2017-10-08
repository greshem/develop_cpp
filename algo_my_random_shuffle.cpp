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
       int operator () (TYPE &in ) // &in in 就有区别. 注意 没有区别, 关键在于 () 实例化的问题.  
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
       TYPE  operator () (int a) //// &in in 就有区别. 注意 没有区别, 关键在于 () 实例化的问题.  
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
        //对于这个仿函数， 一定要先初始化才可以， 为什么， my_print<int> 就可以不初始化就可以使用呢？  
        rand2 test;
        for( i=0; i <= 20; i++)
        {
              vec_int.push_back(i);
        }
         // random_shuffle( vec_int.begin(), vec_int.end(), test);
         //在这里初始化， 好像不行。  
           random_shuffle( vec_int.begin(), vec_int.end(), my_rand<int>);
        //  random_shuffle( vec_int.begin(), vec_int.end(), my_rand);
          //random_shuffle( vec_int.begin(), vec_int.end());      
        for_each(vec_int.begin(), vec_int.end(), my_print<int>() );
        
        //cin >>i;
}
