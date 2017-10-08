// name:example2_3.cpp
// alias:aesthetic version

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
	typedef vector<int>				int_vector;
	typedef istream_iterator<int>				istream_itr;
	typedef ostream_iterator<int>				ostream_itr;
	typedef back_insert_iterator< int_vector >	back_ins_itr;
	vector<int> num;

//	copy(istream_itr(cin), istream_itr(), back_ins_itr(num));

	sort(num.begin(), num.end());

	copy(num.begin(), num.end(), ostream_itr(cout, "\n"));
//	cin.get();
	return 0;
}
     
