#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif


#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>  
#include <netinet/ip.h> 
#include <netdb.h> 
#include <netinet/tcp.h> 
#include <netinet/udp.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h> 
#include <net/if.h> 
#include <sys/ioctl.h> 
#include <fcntl.h> 
#include <linux/if_ether.h>

#include <sys/stat.h> 
#include <string.h> 
#include <stdio.h>
#include <unistd.h>
void die(char *why, int n) 
{ 
	perror(why); 
	exit(n); 
} 

int do_promisc(char *nif, int sock ) 
{ 

	struct ifreq ifr; 
	strncpy(ifr.ifr_name, nif,strlen(nif)+1); 
  	if((ioctl(sock, SIOCGIFFLAGS, &ifr) == -1)) 
  	{        
    	die("ioctl", 2); 
  	} 

  	ifr.ifr_flags |= IFF_PROMISC; 
  	if(ioctl(sock, SIOCSIFFLAGS, &ifr) == -1 ) 
  	{ 
  	  die("ioctl", 3); 
  	} 
	return 1;
} 
char buf[2*32767]; 

int main() 
{ 
	struct sockaddr_in addr;
	struct ethhdr *peth;
	struct iphdr *pip;        																				
	struct tcphdr *ptcp;
	struct udphdr *pudp;

	/*add more protocol head here....*/

	int sock, r, len;        																				
	char *ptemp;
	
	char ss[32], dd[32];     

  	if((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) 
	{
		die("socket", 1); 
	}
	do_promisc("eth0", sock); 
  	for(int i=0 ;i < 100 ;i++) 
	{ 
		len = sizeof(addr); 
		r = recvfrom(sock,(char *)buf,sizeof(buf), 0, (struct sockaddr *)&addr,(socklen_t*)&len); 
		buf[r] = 0; 
		ptemp = buf;
		/*which can get source mac address and destnation address, and which network packet, here is OSI-2, link layer*/
		peth = (struct ethhdr *)ptemp;
		ptemp += sizeof(struct ethhdr);
		/*which get IP layer informations, includes which transport protocol, source and destnation IP address...*/		

		pip = (struct iphdr *)ptemp;

		/*	
		  * which can get transport layer informations, such as: transport socket port, transport layer includes
		  * TCP, UDP, ICMP, IGMP......, can get which transport protocol from IP header
		*/

		ptemp += sizeof(struct iphdr);
		switch(pip->protocol)
		{
			case	IPPROTO_TCP:
				ptcp = (struct tcphdr *)ptemp;
				printf("TCP pkt:\n");
				/*
				 * and your service code....
				 */
			break;
			case	IPPROTO_UDP:
				pudp = (struct udphdr *)ptemp;
				printf("UDP pkt:\n len:%d payload len:%d from %s:%d to %s:%d\n", 
   							r, 
   							ntohs(pudp->len),
   							strcpy(ss, inet_ntoa(*(struct in_addr*)&(pip->saddr))),
   							ntohs(pudp->source),
   							strcpy(dd, inet_ntoa(*(struct in_addr*)&(pip->daddr))),
   							ntohs(pudp->dest)
				); 
			break;
			case 	IPPROTO_ICMP:
				printf("ICMP pkt:\n");
			break;
			case 	IPPROTO_IGMP:
				printf("IGMP pkt:\n");
			break;

			default:
				printf("Unkown pkt, protocl:%d\n", pip->protocol);
			break;
		}
   	}	
	return 0;
}
