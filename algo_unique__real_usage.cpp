#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	vector<int> vecInt;
	vector<int> vecInt2;
	vector<int>::iterator it;
	for(int j=0; j<=3; j++)
	{
		for(int i=0; i<=10; i++)
		{
			vecInt.push_back(i);
		}	
	}	

	cout<<"Size"<<vecInt.size()<<endl;

	sort(vecInt.begin(), vecInt.end());

	copy(vecInt.begin(), vecInt.end(), ostream_iterator<int>(cout, "\n"));
	cout<<"______________________"<<endl;
	it=unique(vecInt.begin(), vecInt.end());
		copy(vecInt.begin(), vecInt.end(), ostream_iterator<int>(cout, "\n"));
	//需要注意这里， 否则不能真正的删除数据。  
	vecInt.erase(it, vecInt.end());
	cout<<"######################"<<endl;
	copy(vecInt.begin(), vecInt.end(), ostream_iterator<int>(cout, "\n"));

	cout<<"Size"<<vecInt.size()<<endl;
	//getchar();

}
