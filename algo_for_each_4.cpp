//template< class InputIterator, class Function >
//Function
//for_each( InputIterator first,
//           InputIterator last, Function func );
//对容器中的元素执行func操作,但不执行写操作

//例子:

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;     
#include <list>
#include <set>   

        
   template <class Type>
void print_elements( Type elem ) { cout << elem << " "; }
        
int main()
{   
    int i;
    vector< int > ivec;
                
    for ( int ix = 0; ix < 10; ix++ )
          ivec.push_back( ix );
                
    void (*pfi)( int ) = print_elements;
   //print_elements< int> pfi;
    random_shuffle(ivec.begin(), ivec.end());
    for_each( ivec.begin(), ivec.end(), pfi );
    //cin >> i;
    return 0;
}
