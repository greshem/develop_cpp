
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

using namespace std;
//int save(const std::string& filename, int append=1) const
int save(const std::string& filename, int append=1) 
{
	std::ofstream out(filename.c_str(), (append==0)?(ios::out|ios::trunc):(ios::out|ios::app));
	//save(out);
	return 1;
}


using namespace std;
int main(int argc, char *argv[])
{
	return 1;
}

