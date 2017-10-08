//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdio.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif


#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>


#define timeout 2          // wait for 2 seconds


// Do not change something below.

#define VERSION "1.0b"

#define mac_bcast "\xff\xff\xff\xff\xff\xff"

struct dhcpMessage {
	u_int8_t op;
	u_int8_t htype;
	u_int8_t hlen;
	u_int8_t hops;
	u_int32_t xid;
	u_int16_t secs;
	u_int16_t flags;
	u_int32_t ciaddr;
	u_int32_t yiaddr;
	u_int32_t siaddr;
	u_int32_t giaddr;
	u_int8_t chaddr[16];
	u_int8_t sname[64];
	u_int8_t file[128];
	u_int32_t cookie;
	u_int8_t options[308]; /* 312 - cookie */ 
};

struct udp_dhcp_packet {
	struct ethhdr eth;
        struct iphdr ip;
        struct udphdr udp;
        struct dhcpMessage data;
} __attribute__ ((packed)) udp_dhcp_packet;

struct udp_dhcp_packet_for_checksum {
        struct iphdr ip;
        struct udphdr udp;
        struct dhcpMessage data;
};

u_int16_t checksum(void *addr, int count)
{
        /* Compute Internet Checksum for "count" bytes
         *         beginning at location "addr".
         */
        register int32_t sum = 0;
        u_int16_t *source = (u_int16_t *) addr;

        while (count > 1)  {
                /*  This is the inner loop */
                sum += *source++;
                count -= 2;
        }

        /*  Add left-over byte, if any */
        if (count > 0) {
                /* Make sure that the left-over byte is added correctly both
                 * with little and big endian hosts */
                u_int16_t tmp = 0;
                *(unsigned char *) (&tmp) = * (unsigned char *) source;
                sum += tmp;
        }
        /*  Fold 32-bit sum to 16 bits */
        while (sum >> 16)
                sum = (sum & 0xffff) + (sum >> 16);

        return ~sum;
}

int initialize_socket(struct sockaddr_ll * dest, unsigned char *dest_arp, int * fd, unsigned char * mac,char * ifname) 
{

    struct ifreq ifr;
    int ifindex;

    ifr.ifr_addr.sa_family = AF_INET;
    strcpy(ifr.ifr_name, ifname);

    memset(&(*dest), 0, sizeof(dest));

    if ((*fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP))) < 0) 
	{
	printf("Socket error: %s\n", strerror(errno));
	return -1;
    }

    if (ioctl(*fd, SIOCGIFINDEX, &ifr) == 0) 
	{
	printf("Adapter index: %d\n", ifr.ifr_ifindex);
	ifindex = ifr.ifr_ifindex;
    }
    else 
	{
    	printf("SIOCGIFINDEX failed: %s\n", strerror(errno));
		return -1;
    }
    if (ioctl(*fd, SIOCGIFHWADDR, &ifr) == 0) 
	{
    	memcpy(mac, ifr.ifr_hwaddr.sa_data, 6);
    	printf("Adapter hardware address: %02x:%02x:%02x:%02x:%02x:%02x\n",
		(unsigned int) mac[0], (unsigned int)mac[1], (unsigned int)mac[2], (unsigned int)mac[3], (unsigned int)mac[4], (unsigned int)mac[5]);
    } else 
	{
    	printf("SIOCGIFHWADDR failed: %s\n", strerror(errno));
    	return -1;
    }

    dest->sll_family = AF_PACKET;
    dest->sll_protocol = htons(ETH_P_IP);
    dest->sll_ifindex = ifindex;
    dest->sll_halen = 6;
    
    memcpy(dest->sll_addr, dest_arp, 6);

    if (bind(*fd, (struct sockaddr *) dest, sizeof(struct sockaddr_ll)) < 0) 
	{
    	printf("Bind error: %s\n", strerror(errno));
    	close(*fd);
    	return -1;
    }
    return 0;
}

int raw_packet(struct dhcpMessage *payload, unsigned char *dest_arp, struct sockaddr_ll * dest, int * fd,unsigned char * mac)
{
	int result;
	struct udp_dhcp_packet packet;
	struct udp_dhcp_packet_for_checksum packet_c;

	memset(&packet, 0, sizeof(packet));
	memset(&packet_c, 0, sizeof(packet_c));
	memcpy(&packet.eth.h_dest, (unsigned char *) mac_bcast, 6); /* broadcast */
	memcpy(&packet.eth.h_source, (unsigned char *) mac, 6);
	memcpy(&packet.eth.h_proto, (unsigned char *) "\x08\x00", 2); /* Type 0x0800 */
	packet.ip.protocol = IPPROTO_UDP;
	packet.ip.saddr = INADDR_ANY; /* 0.0.0.0 */
	packet.ip.daddr = INADDR_BROADCAST; /* 255.255.255.255 */
	packet.udp.source = htons(68); /* source port */
	packet.udp.dest = htons(67); /* destination port */
	packet.udp.len = htons(sizeof(packet.udp) + sizeof(struct dhcpMessage)); /* cheat on the psuedo-header */
	packet.ip.tot_len = packet.udp.len;

	memcpy(&(packet.data), payload, sizeof(struct dhcpMessage));
	memcpy(&(packet_c.data), payload, sizeof(struct dhcpMessage));

	packet_c.ip = packet.ip;
	packet_c.udp = packet.udp;
	packet.udp.check = checksum(&packet_c, sizeof(struct udp_dhcp_packet_for_checksum));
	packet.ip.tot_len = htons(sizeof(struct udp_dhcp_packet) - sizeof(struct ethhdr));
	packet.ip.ihl = sizeof(packet.ip) >> 2;
	packet.ip.version = IPVERSION;
	packet.ip.ttl = IPDEFTTL;
	packet.ip.check = checksum(&(packet.ip), sizeof(packet.ip));

	result = sendto(*fd, &packet, sizeof(struct udp_dhcp_packet), 0, (struct sockaddr *) dest, sizeof(*dest));
	if (result <= 0) printf("Write error: %s\n", strerror(errno));
	return result;
}

static void init_packet(struct dhcpMessage *packet, unsigned char * mac)
{
	memset(packet, 0, sizeof(struct dhcpMessage));
	packet->op = 1;				 /* Bootrequest */
	packet->htype = 1;			 /* 10mb */
	packet->hlen = 6; 			 /* 10mb_len */
	packet->cookie = htonl(0x63825363); 	 /* magic cookie */

	/* we're sending Discover */
	packet->options[0] = 0x35;
	packet->options[1] = 0x1;
	packet->options[2] = 0x1;
	/* end */
	packet->options[3] = 0xFF; 		 /* dhcp end delimiter */
	memcpy(packet->chaddr, mac, 6);
}

int send_discover(struct sockaddr_ll * dest, int * fd, unsigned char * mac)
{
	struct dhcpMessage packet;

	init_packet(&packet, mac);
	packet.xid = 0x3903F326;
	return raw_packet(&packet, (unsigned char *) mac_bcast, dest, fd, mac);
}

int get_raw_packet(struct dhcpMessage *payload, int fd)
{
	int bytes;
	struct udp_dhcp_packet packet;
	struct udp_dhcp_packet_for_checksum packet_c;
	u_int32_t source, dest;
	u_int16_t check;

	memset(&packet, 0, sizeof(struct udp_dhcp_packet));
	bytes = read(fd, &packet, sizeof(struct udp_dhcp_packet));
	if (bytes < 0) 	return -1;  /* cannot read on socket */
	
	if (bytes < (int) (sizeof(struct iphdr) + sizeof(struct udphdr))) return -2; /* msg too short */

	
	if (bytes < ntohs(packet.ip.tot_len)) return -2; /* truncated */
	
	/* ignore any extra garbage bytes */
	bytes = ntohs(packet.ip.tot_len);
	
	/* Make sure its the right packet for us, and that it passes sanity checks */
	if (packet.ip.protocol != IPPROTO_UDP || packet.ip.version != IPVERSION ||
	    packet.ip.ihl != sizeof(packet.ip) >> 2 || packet.udp.dest != htons(68) /* Client port */ ||
	    bytes > (int) sizeof(struct udp_dhcp_packet) ||
	    ntohs(packet.udp.len) != (short) (bytes - sizeof(packet.ip))) return -2;

	memcpy(payload, &(packet.data), bytes - (sizeof(packet.ip) + sizeof(packet.udp) + sizeof(packet.eth)));
	
	if (ntohl(payload->cookie) != 0x63825363 /* Dhcp magic cookie */) return -2;
	
	printf("Dhcp server detected: mac=%02x:%02x:%02x:%02x:%02x:%02x, ", packet.eth.h_source[0],
	       packet.eth.h_source[1],packet.eth.h_source[2], packet.eth.h_source[3], packet.eth.h_source[4],
	       packet.eth.h_source[5]);
	printf("ip=%d.%d.%d.%d\n", packet.ip.saddr & 0xFF, packet.ip.saddr >> 8 & 0xFF, 
	       packet.ip.saddr >> 16 & 0xFF, packet.ip.saddr >> 24 & 0xFF);

	return bytes - (sizeof(packet.ip) + sizeof(packet.udp) + sizeof(packet.udp));	
}

int main (int argc, char * argv[]) {
    int i, fd;
    struct sockaddr_ll dest;
    struct dhcpMessage packet;
    clock_t start, end;
    struct tm * timeinfo;
    unsigned char mac[6];

	if (argc != 2 || strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0) 
	{
		printf("OPTIONS: [-h (this help)]  [-v (version info)] [interface]\nUsage:\n\n");
        printf("DHCPDetector discovers all DHCP servers on your network and gives some info about them.\n");
        printf("The program can be used to detect rouge DHCP servers.\n");
        printf("This program needs root privileges.\n");
        return 0;
    }
	if (strcmp(argv[1],"-v")==0 || strcmp(argv[1],"-version")==0 || strcmp(argv[1],"--version")==0) 
	{
        printf("DHCPDetector %s (c) andras && suletom (NetClub 2007.)\n\n", VERSION); 
        return 0;
    }
    
    if (initialize_socket(&dest, (unsigned char *) mac_bcast, &fd, &(*mac), argv[1]) == -1) return -1;
    send_discover(&dest, &fd, mac);

    start = clock();

    /* Set non-blocking mode for listening */
    int on = 1;
    ioctl(fd, FIONBIO, &on);

    while (1) 
	{
		end = clock();
		//	if (((int)timeout) <= (int)(end/1000000)) return 0;
		sleep(1);
		get_raw_packet(&packet, fd);
    }
}
