#include <ext/hash_map>
#include <iostream>
using namespace std;
using namespace __gnu_cxx; 
main()
{     
      int i;
      hash_map <int, int> hmap_info;
      hash_map <int, int>::iterator hmap_it;
      pair<int, int> pair_int;
      hmap_info.insert(make_pair(1, 1111));

      hmap_it = hmap_info.find(1);
      cout<< (*hmap_it).first<< "|||"<<(*hmap_it).second <<endl;

//      cin >>i;
      return 0;
}
