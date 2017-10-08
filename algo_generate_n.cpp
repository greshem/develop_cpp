#include <list>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>


int main()

{
  using namespace std;
  int i;
  // Demonstrating minmax(

  // Demonstrating minmax_element()
  list<int> L;
  typedef list<int>::const_iterator iterator;
  generate_n(front_inserter(L), 1000, rand);
 //   generate_n(L.begin(), 1000, rand);

cout<<"size"<< L.size()<<endl;


cout << *(std::min_element(L.begin(), L.end())) <<endl;
cout << *(std::max_element(L.begin(), L.end())) <<endl;
//cin >> i;
}
