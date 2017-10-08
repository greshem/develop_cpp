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
	int ret  = shell_exec("ifconfig", output);
	cout<<output;
	
	return ret;
}


/****************************************************************************
 * Description: ִ�� shell ����� 
 * @param:	out �� ִ��������֮�� ������ַ��� 
 * @return  	
 * 			����ֵ�� �������ķ���ֵ  
 * 			����ֵ��ֵ λ��0-255 ���� ��Ҫ�Է��ص�ֵ ��256 ȡmod.
 ***************************************************************************/
int  shell_exec(string in, string &out)
{
    FILE *pipe=popen(in.c_str(), "r");
    char buffer[1024];

    if(! pipe)
    {
        cout<<"pipe open error"<<endl;
    }

    while((fgets(buffer, sizeof(buffer), pipe)))
    {
        out+=buffer;
    }
    int ret=pclose(pipe);
    return (ret%255); //����256

}


