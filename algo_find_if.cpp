#include <algorithm>
#include <iostream>

using namespace std;


// returns true if n is an odd number
int IsOdd( int n)
{
    return n % 2 ;
}

 main()
{
    const int ARRAY_SIZE = 11 ;
    int IntArray[ARRAY_SIZE] = { 22, 34, 36, 1, 2, 3, 4, 4, 5, 6, 7 } ;
    int *location ;   // stores the position of the first
                      // element that is an odd number
    int i ;

        // print content of IntArray
    cout << "IntArray { " ;
    for(i = 0; i < ARRAY_SIZE; i++)
        cout << IntArray[i] << ", " ;
    cout << " }" << endl ;

    // Find the first element in the range [first, last -1 ]
    // that is an odd number
    location = find_if(IntArray, IntArray + ARRAY_SIZE, IsOdd) ;

    //print the location of the first element
    // that is an odd number
    if (location != IntArray + ARRAY_SIZE)  // first odd element found
        cout << "First odd element " << *location
             << " is at location " << location - IntArray << endl;
    else         // no odd numbers in the range
        cout << "The sequence does not contain any odd numbers"
             << endl ;
    //cin >> i;
    return 0;

}

