
#include <list>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
main()
{
      std::list <int >  test;
      int j;
      for (int i=1;i<=100;i++)
      {
          test.push_front(rand());
      }
      test.reverse();
      copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, "\n"));
//      std::cin  >>j;
      printf("%d\n",j);
}
