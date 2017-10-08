#include <pcap.h>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <stringprep.h>
//#include "hacking.h"

void pcap_fatal(const char *failed_in, const char *errbuf) 
{
	printf("Fatal Error in %s: %s\n", failed_in, errbuf);
	exit(1);
}

int main() 
{
	struct pcap_pkthdr header;
	const u_char *packet;
	char errbuf[PCAP_ERRBUF_SIZE];
	char *device;
	char dev[]="eth0";
	pcap_t *pcap_handle;
	int i;

	device = pcap_lookupdev(errbuf);
	if(device == NULL)
	{
		pcap_fatal("pcap_lookupdev", errbuf);
	}

	printf("Sniffing on device %s\n", dev);
	
	//pcap_handle = pcap_open_live(device, 4096, 1, 0, errbuf);
	pcap_handle = pcap_open_live(dev, 4096, 1, 0, errbuf);
	if(pcap_handle == NULL)
	{
		pcap_fatal("pcap_open_live", errbuf);
	}
	
	for(i=0; i < 3; i++) {
	//while(1)
		packet = pcap_next(pcap_handle, &header);
		printf("Got a %d byte packet\n", header.len);
//		dump(packet, header.len);
	}

	pcap_close(pcap_handle);
}
