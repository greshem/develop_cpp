#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <queue>
#include <map>
using namespace std;
int main(int argc, char *argv[])
{
	cout<<"queue.cpp"<<endl;
	int a[]={0, 1, 2, 3, 4, 5, 6};
	int tmp;
	//queue<int> intQueue(a, a+5);
	queue<int> intQueue;
	for(int i=11; i<=19; i++)
	{
		intQueue.push(i);
	}
	while(!intQueue.empty())
	{
		tmp=intQueue.front();
		intQueue.pop();		
		cout<<"pop "<<tmp<<endl;
		cout<<"after pop "<<"left number is "<<intQueue.size()<<endl;
		
	}
	return 0;
}
