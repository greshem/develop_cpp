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
