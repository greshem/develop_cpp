
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
using namespace std;
/****************************************************************************
* Description	
* @param 	
* @return 	
* @notice: 注意 return 的时候 需要返回 ret %256 这样的值.
****************************************************************************/
int  shell_exec(string const in, string &out)
{
	#ifdef WINDOWSCODE
	FILE *pipe=_popen(in.c_str(), "r");
	#else
    FILE *pipe=popen(in.c_str(), "r");
    #endif
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
	#ifdef WINDOWSCODE
	int ret=_pclose(pipe);
	#else
    int ret=pclose(pipe);
	#endif
	return (ret%255); //不是256
}


int main(int argc, char *argv[])
{
	return 0;
}
