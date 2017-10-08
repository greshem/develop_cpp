#include<map>
#include<iostream>
#include <stdio.h>

using namespace std;

typedef map<int, string, less<int> > M_TYPE;
typedef M_TYPE::iterator M_IT;
typedef M_TYPE::const_iterator M_CIT;

int main()
{
M_TYPE MyTestMap;

MyTestMap[3] = "No.3";
MyTestMap[5] = "No.5";
MyTestMap[1] = "No.1";
MyTestMap[2] = "No.2";
MyTestMap[4] = "No.4";

M_IT it_stop = MyTestMap.find(2);

cout << "MyTestMap[2] = " << it_stop->second << endl;
it_stop->second = "No.2 After modification";
cout << "MyTestMap[2] = " << it_stop->second << endl;

cout << "Map contents : " << endl;
for(M_CIT it = MyTestMap.begin(); it != MyTestMap.end(); it++)
{
  cout << it->second << endl;
  cout << it->first <<endl;
}
//getchar();
return 0;
}
