#include <algorithm>
#include <arpa/inet.h>
#include <asm/types.h> 
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <iostream> 
#include <iterator>  
#include <linux/if_ether.h> 
#include <linux/if_packet.h>
#include <locale.h>
#include <map>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <vector> 
//########################################################################
//#include <stringprep.h>

//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#2010_09_02_16:36:27 add by greshem , baselib 和模板。 
//#2010_09_17_09:11:01 add by greshem


//fd=socket(AF_INET, SOCK_RAW, IPPROTO_IP); //这个会错误 why ? 
using namespace std;
int main(int argc, char *argv[])
{
	int addr;
	char *interface="eth1";
	int fd;
	struct ifreq ifr;
	struct sockaddr_in *our_ip;
	memset(&ifr, '\0', sizeof(struct ifreq));
	//fd=socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	fd=socket(AF_INET, SOCK_RAW, IPPROTO_IP); //这个会错误 why ? 
	//fd=socket(AF_INET, SOCK_RAW, 3333);
	if(fd<0)
	{
		printf("create socket error\n");
	}
	ifr.ifr_addr.sa_family=AF_INET;
	strcpy(ifr.ifr_name, interface);
	
	if(ioctl(fd, SIOCGIFADDR, &ifr)==0)
	{
		our_ip=(struct sockaddr_in *) &ifr.ifr_addr;
		addr=our_ip->sin_addr.s_addr;
		//printf("%s\n", 
	}
	else
	{
		printf("SIOCGIFADDR failed\n");
	}	
	
	if( ioctl(fd, SIOCGIFINDEX, &ifr) ==0)
	{
		//int ifindex=ifr.ifr_ifindex;
	}
	else
	{
		printf("SIOCGIFINDEX error\n");
	}
	unsigned char arp[6];	
	if(ioctl(fd, SIOCGIFHWADDR, &ifr)==0)
	{
		memcpy(arp, ifr.ifr_hwaddr.sa_data, 6);
		printf("hardware addr %02x:%02x:%02x:%02x:%02x:%02x\n", 
			arp[0], arp[1], arp[2], arp[3], arp[4], arp[5]);	
	}
	else
	{
		printf("SIOCGIFHWADDR  error");
	}
	close(fd);
	return 0;
}
