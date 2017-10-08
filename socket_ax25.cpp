#include <stdlib.h>
//###################################################
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <algorithm>
#include <arpa/inet.h>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <string> 
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_09_16 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	//int fd=socket(AF_AX25, SOCK_STREAM, 0); //AF_AX25没有 stream
	//int fd=socket(AF_ECONET, SOCK_DGRAM, 0);
	//int fd=socket(AF_IPX, SOCK_STREAM, 0);
	//int fd=socket(AF_AX25, SOCK_DGRAM, PF_AX25);
	//int fd=socket(AF_AX25, SOCK_DGRAM, 0);
	//int fd=socket(PF_AX25, SOCK_SEQPACKET, 0);
	//int fd=socket(AF_BLUETOOTH, SOCK_STREAM, 0);
	//SOCK_SEQPACKET
	//int fd=socket(AF_BLUETOOTH, SOCK_SEQPACKET, 0);
	//
	//tcp ip 
	//int fd=socket(PF_INET6, SOCK_STREAM, 0); //0就是 IPPROTO_IP
	//int fd=socket(AF_INET, SOCK_STREAM, 0);
	//int fd=socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	//int fd=socket(AF_INET, SOCK_STREAM,  IPPROTO_ICMP );//not ok
	// int fd=socket(AF_INET, SOCK_RAW,  IPPROTO_ICMP );// ok
	// 错误 int fd=socket(AF_INET, SOCK_STREAM,  IPPROTO_UDP );
	// int fd=socket(AF_INET, SOCK_DGRAM,  IPPROTO_UDP );//ok
	//int fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //ok 
	//int fd=socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP); //ok
	//int fd=socket(AF_INET, SOCK_STREAM, IPPROTO_RAW); //not ok
	//int fd=socket(AF_INET, SOCK_RAW, IPPROTO_RAW); //ok
	//int fd=socket(AF_INET, SOCK_RAW, IPPROTO_MAX); //ok
	//int fd=socket(AF_INET, SOCK_RAW,  333333); //ok SOCK_RAW 不会关心后面的另外的参数的。 
	//int fd=socket(AF_INET, SOCK_PACKET, IPPROTO_MAX); //ok
	int fd=socket(AF_INET, SOCK_PACKET, IPPROTO_MAX+1); //ok SOCK_PACKET 也不关心 第二个参数
	if(fd < 0)
	{
		perror("socket");
	}
	else
	{
		cout<<"ok fd="<<fd<<endl;
	}
	return 0;
}
