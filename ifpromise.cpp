/*
   ifpromisc - This is a simple subset of Fred N. van Kempen, 
               <waltje@uwalt.nl.mugnet.org>'s ifconfig.
               Show state of all ethernet interface 
               xxx is PROMISC 
               or
               xxx is not promisc

   Version:      @(#)ifpromisc.c        0.5     2000/12/21
   Last Changes: Ports for Solaris  
                 Andre Gustavo <gustavo@anita.visualnet.com.br> 
                 Port for OpenBSD 
                 Nelson Murilo, <nelson@pangeia.com.br>
  
   Author:      Nelson Murilo, <nelson@pangeia.com.br>
                Copyright 1997-2000 (C) Pangeia Informatica
  
                This program is free software; you can redistribute it
                and/or  modify it under  the terms of  the GNU General
                Public  License as  published  by  the  Free  Software
                Foundation;  either  version 2 of the License, or  (at
                your option) any later version.
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#ifdef __linux__
#include <linux/if.h>
#include <linux/if_arp.h>
#include <linux/if_ether.h>
#else
#include <net/if.h>
#ifndef __OpenBSD__
#include <net/if_arp.h>
#endif
#endif
#ifdef SOLARIS2
#include <sys/sockio.h>
#endif
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct interface 
{
  char                  name[IFNAMSIZ];         /* interface name       */
  short                 type;                   /* if type              */
  short                 flags;                  /* various flags        */
};

/* This structure defines protocol families and their handlers. */
struct aftype {
  char          *name;
  char          *title;
  int           af;
  int           alen;
  char          *(*print)       (unsigned char *);
  char          *(*sprint)      (struct sockaddr *, int numeric);
  int           (*input)        (char *bufp, struct sockaddr *);
  void          (*herror)       (char *text);
};
  
char *Release = "chkrootkit package",
     *Version = "@(#) ifpromisc 0.3 (20/02/97)";

int skfd = -1;                          /* AF_INET raw socket desc.     */

static void ife_print(struct interface *ptr)
{
  printf("%s is ", ptr->name);
  if (ptr->flags & IFF_PROMISC) 
     printf("PROMISC"); 
  else
     printf("not promisc"); 
  putchar('\n');
}

/* Fetch the inteface configuration from the kernel. */
static int if_fetch(char *ifname, struct interface *ife)
{
  struct ifreq ifr;

  memset((char *) ife, 0, sizeof(struct interface));
  strcpy(ife->name, ifname);

  strcpy(ifr.ifr_name, ifname);
  if (ioctl(skfd, SIOCGIFFLAGS, &ifr) < 0) return(-1);
  ife->flags = ifr.ifr_flags;
  return(0);
}

static void if_print()
{
  char buff[1024];
  struct interface ife;
  struct ifconf ifc;
  struct ifreq *ifr;
  int i;

   ifc.ifc_len = sizeof(buff);
   ifc.ifc_buf = buff;
   if (ioctl(skfd, SIOCGIFCONF, &ifc) < 0) 
   {
      fprintf(stderr, "SIOCGIFCONF: %s\n", strerror(errno));
      return;
   }

   ifr = ifc.ifc_req;
   for (i = ifc.ifc_len / sizeof(struct ifreq); --i >= 0; ifr++) 
   {
      if (if_fetch(ifr->ifr_name, &ife) < 0) 
      {
#ifdef __linux__
         fprintf(stderr, "%s: unknown interface.\n", ifr->ifr_name);
#endif
         continue;
      }
      if (!memcmp(ifr->ifr_name, "lo", 2))
         continue; 
      ife_print(&ife);
   }
}

int main(int argc, char **argv)
{
  struct sockaddr sa;
  struct aftype *ap;

  /* Create a channel to the NET kernel. */
  if ((skfd = socket(AF_INET, SOCK_DGRAM,0)) < 0) {
        perror("socket");
        exit(-1);
  }
  if_print();
  (void) close(skfd);
  exit(0);
}

