//fill()

//template< class ForwardIterator, class Type >
//void
//fill( ForwardIterator first,
 //      ForwardIterator last, const Type& value );

//将value的值拷贝给容器first、last范围内的元素

#include <algorithm>
#include <list>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;
        
/* generates:
    original array element sequence:
    0 1 1 2 3 5 8
           
    array after fill(ia+1,ia+6):
    0 9 9 9 9 9 8
   
    original list element sequence:
    c eiffel java ada perl
           
    list after fill(++ibegin,--iend):
    c c++ c++ c++ perl
*/
        
        /*
        20100602. qzj ,把对应的代码都拷贝过来了，利于理解问题。  
        template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy(_InputIter __first, _InputIter __last,
           _OutputIter __result,
           input_iterator_tag)
    {
      for ( ; __first != __last; ++__result, ++__first)
        *__result = *__first;
      return __result;
    }
     注意这里copy的定义。  
        */
        
        /*
            ostream_iterator< int > ofile( cout, " " );的
            ostream_iterator 的构造函数。 
             内部的 *_M_string 编程了cout了，             
                  ostream_iterator& 
             =就是copy 里面的=号， 这里， 就是 << cout 的操作符号了， 
              所以这里会打印 int 的所有的值。  
      operator=(const _Tp& __value) 
      { 
        *_M_stream << __value;
        if (_M_string) *_M_stream << _M_string;
        return *this;
      }
 
          */ 
int main()
{
    const int value = 9;
    int ia[]   = { 0, 1, 1, 2, 3, 5, 8 };
    ostream_iterator< int > ofile( cout, " " );
            
    cout << "original array element sequence:\n";
    copy( ia, ia+7, ofile ); cout << "\n\n";
            
    fill( ia+1, ia+6, value );
   
    cout << "array after fill(ia+1,ia+6):\n";
    copy( ia, ia+7, ofile ); cout << "\n\n";
            
    string the_lang( "c++" );
    string langs[5] = { "c", "eiffel", "java", "ada", "perl" };
            
    list< string> il( langs, langs+5 );
    ostream_iterator< string > sofile( cout, " " );
            
    cout << "original list element sequence:\n";
    copy( il.begin(), il.end(), sofile ); cout << "\n\n";
            
    typedef list<string>::iterator iterator;
   
    iterator ibegin = il.begin(), iend = il.end();
    fill( ++ibegin, --iend, the_lang );
            
    cout << "list after fill(++ibegin,--iend):\n";
    copy( il.begin(), il.end(), sofile ); cout << "\n\n";
    int j;
    //cin >>j;
}
