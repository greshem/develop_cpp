#include <vector>
#include <list>
#include <iostream>
//#include <conio>
#include <iterator> 
using namespace std;

void printList(list<int> ilist)
{
 list<int>::iterator it_ilist;
 for (it_ilist = ilist.begin(); it_ilist != ilist.end(); it_ilist++)
 {
  cout<<*it_ilist<<"  ";
 }
 cout<<endl;
}

int main()
{
 list<int> ilist,ilist2,ilist3;
 for(list<int>::size_type i= 0 ;i!=4;i++)
 {
  ilist.push_front(i);
  ilist2.push_front(i);
  ilist3.push_front(i);
 }

 copy(ilist.begin(),ilist.end(),front_inserter< list<int> >(ilist2));

 copy(ilist.begin(),ilist.end(),inserter<list<int> >(ilist3,ilist3.begin()) );// 在ilist3.begin()的前面插入

 printList(ilist);

 printList(ilist2);

 printList(ilist3);
 
 //cin.get();
}

//3210
//0123
//3210 

