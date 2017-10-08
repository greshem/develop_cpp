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
#include <map>
using namespace std;
string basename(string &path);
string dirname(string &path);

//cout<<path.substr(path.rfind("/")+1, path.size()) <<endl;

int main(int argc, char *argv[])
{
	string path("aa/bbb/cc/dd/ff/gggg");
	cout<<"path="<<path<<endl;	
	cout<<"basename="<<basename(path)<<endl;
	cout<<"dirname=" <<dirname(path) <<endl;
	return 0;
}

string basename(string &path)
{
	return (path.substr(path.rfind("/")+1, path.size()));
}


string dirname(string &path)
{
	return (path.substr(0, path.rfind("/")+1 ));
}
