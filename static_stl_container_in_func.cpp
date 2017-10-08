
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
int get_all_user( vector<string> &out)
{
	#ifdef WINDOWSCODE


	#else
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
	#endif
	return 1;
}

class equal_user
{
    private:
        string user;
    public:
        equal_user(string tmp):user(tmp){};
        bool operator  () ( string &a)
        {
            if( user == a )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};


class bbb
{
	public:
	static int  change();
};
int bbb::change()
{

	static vector<string> vec_users;
	get_all_user(vec_users);

	string user="bbbb";
    if( find_if(vec_users.begin(), vec_users.end(),  equal_user(user)) == vec_users.end())
    {
        //cout<<"root 不存在"<<endl;
        printf("%s 这个用户不存在 \n", user.c_str() );
        //memset(&out, '\0', sizeof(out));
        return 1;
    }

	return 1;
}

int main()
{
	bbb::change();
}
