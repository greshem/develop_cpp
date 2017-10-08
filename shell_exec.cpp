#include <algorithm>
#include <fstream>
//#include <gtest/gtest.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 

using namespace std;

int  shell_exec(string  in, string &out);

int main(int argc, char *argv[])
{
	string output;
#ifdef WINDOWSCODE
	int ret  = shell_exec("ipconfig", output);
#else
	int ret  = shell_exec("ifconfig", output);
#endif
	cout<<output;
	//file_put_content<char>("ipconfig.txt", ifcfg);
	return 0;
}


/****************************************************************************
 * Description: 执行 shell 的命令。 
 * @param:	out 是 执行命令行之后 输出的字符串 
 * @return  	
 * 			返回值是 命令最后的返回值  
 * 			返回值的值 位于0-255 所以 需要对返回的值 对256 取mod.
 ***************************************************************************/
int  shell_exec(string in, string &out)
{
#ifdef WINDOWSCODE
		return 1;
#else
    FILE *pipe=popen(in.c_str(), "r");
    char buffer[1024];
    //string out;

    if(! pipe)
    {
        cout<<"pipe open error"<<endl;
    }

    while((fgets(buffer, sizeof(buffer), pipe)))
    {
        out+=buffer;
    }
    //fclose(pipe);
    int ret=pclose(pipe);
	//return ret;
    return (ret%255); //不是256
#endif

}


