//template< class InputIterator, class Function >
//Function
//for_each( InputIterator first,
//           InputIterator last, Function func );
//对容器中的元素执行func操作,但不执行写操作
//例子:

#include <algorithm>
#include <iostream>
#include <list>
#include <set>   
#include <string>
#include <vector>
using namespace std;     

template <class Type> void print_elements( Type elem ) 
{ 
	cout << elem << " "; 
}
        
int main()
{
    vector< int > ivec;
                
    for ( int ix = 0; ix < 10; ix++ )
	{
		ivec.push_back( ix );
	}
                
    void (*pfi)( int ) = print_elements;
    for_each( ivec.begin(), ivec.end(), pfi );
                
    return 0;
}
