
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
string  get_ip_net_addr_range(string ip );

int main(int argc, char *argv[])
{ 
	printf("this is main \n");
	get_ip_net_addr_range("1.1.1.1");
	get_ip_net_addr_range("3.1.1.1");
	get_ip_net_addr_range("192.168.111.1");
	get_ip_net_addr_range("192.168.1.333");
	return 1;
} 

string  get_ip_net_addr_range(string ip )
{
   	string ip_range= ip.substr(0, ip.rfind(".")+1);
    ip_range+="0";
	cout <<ip_range<<endl;
	return ip_range ;
}
