
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <sstream>
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

int get_all_user(vector<string> &out)
{
	std::ifstream passwd("/etc/passwd");
	if(!passwd)
	{
		cout<<"open passwd failure \n"<<endl;
		return 0;
	}
	
 	while (!passwd.eof()) 
    {   
        std::string line;
        std::getline(passwd, line);
	 	string::size_type pos_end=line.find_first_of(":");
		string user= line.substr(0, pos_end);
		//cout<<user<<endl;
		out.push_back(user);
	}	
	return 1;
}

class equal_user
{
private:
	string user;
public:
	equal_user(string tmp):user(tmp){};
	bool operator  () (  string &a)
	{
		if( user ==a )
		{
			return true;
		}
		return false;
	}
};
int main(int argc, char *argv[])
{
	vector<string> vec_users;
	get_all_user(vec_users);	
	if( find_if(vec_users.begin(), vec_users.end(),  equal_user("rootbbb")) != vec_users.end())
	{
		cout<<"root 确实存在"<<endl;
	}
	else
	{
		cout<<"root 不存在"<<endl;
	}
}
