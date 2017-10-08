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
#include <string.h>

#include <ctype.h>
#include <getopt.h>

#define INITIAL_MAXARGC 16;

char **buildargv (const char *input)
{
  char *arg;
  char *copybuf;
  int squote = 0;
  int dquote = 0;
  int bsquote = 0;
  int argc = 0;
  int maxargc = 0;
  char **argv = NULL;
  char **nargv;

  if (input != NULL)
    {
      copybuf = (char *) malloc (strlen (input) + 1);
      /* Is a do{}while to always execute the loop once.  Always return an
	 argv, even for null strings.  See NOTES above, test case below. */
      do
	{
	  /* Pick off argv[argc] */
	  while (isblank (*input))
	    {
	      input++;
	    }
	  if ((maxargc == 0) || (argc >= (maxargc - 1)))
	    {
	      /* argv needs initialization, or expansion */
	      if (argv == NULL)
		{
		  maxargc = INITIAL_MAXARGC;
		  nargv = (char **) malloc (maxargc * sizeof (char *));
		}
	      else
		{
		  maxargc *= 2;
		  nargv = (char **) realloc (argv, maxargc * sizeof (char *));
		}
	      if (nargv == NULL)
		{
		  if (argv != NULL)
		    {
		      free (argv);
		      argv = NULL;
		    }
		  break;
		}
	      argv = nargv;
	 		argv[argc] = '\0';
	    }
	  /* Begin scanning arg */
	  arg = copybuf;
	  while ((*input != '\0') )
	    {
	      //if (ISSPACE (*input) && !squote && !dquote && !bsquote)
	      if (isspace (*input) && !squote && !dquote && !bsquote)
		{
		  break;
		}
	      else
		{
		  if (bsquote)
		    {
		      bsquote = 0;
		      *arg++ = *input;
		    }
		  else if (*input == '\\')
		    {
		      bsquote = 1;
		    }
		  else if (squote)
		    {
		      if (*input == '\'')
			{
			  squote = 0;
			}
		      else
			{
			  *arg++ = *input;
			}
		    }
		  else if (dquote)
		    {
		      if (*input == '"')
			{
			  dquote = 0;
			}
		      else
			{
			  *arg++ = *input;
			}
		    }
		  else
		    {
		      if (*input == '\'')
			{
			  squote = 1;
			}
		      else if (*input == '"')
			{
			  dquote = 1;
			}
		      else
			{
			  *arg++ = *input;
			}
		    }
		  input++;
		}
	    }
	  *arg = NULL;
	  argv[argc] = strdup (copybuf);
	  if (argv[argc] == NULL)
	    {
	      free (argv);
	      argv = NULL;
	      break;
	    }
	  argc++;
	  argv[argc] = NULL;

	  while (isspace (*input))
	    {
	      input++;
	    }
	}
      while (*input != '\0');
    }
  return (argv);
}
//###############################################################################/
void usage()
{
 printf("Usage : %s [OPTION]...\n\n", "wenshuna");
 printf("  -d, --delay   delay between receive and send data in seconds. default:%i\n", 23333);
 printf("  -h, --help       print this screen\n");
 printf("  -p, --port       defines server port. default:%i\n", 45);
 printf("  -v, --version    output version information\n");
 exit(0);
}
static struct option long_options[]={
	{"delay", 1, 0, 'd'},
	{"help", 0, 0,'h'},
	{"port", 1, 0, 'p'},
	{"version", 0, 0, 'v'}
};

int main()
{
	char **tmp; 
	tmp=buildargv ("./command  --delay 333    --port 94 --version --help");

	// while( (*tmp))
	// {
	// 	printf("%s\n", *tmp);
	// 	tmp++;
	// }
	
	
	
	int c, option_index;
	while ((c=getopt_long(7, tmp, "d:p:v?h", long_options, &option_index)) != -1)
	{
		switch((char)c) 
		{
			case 'd':
				printf("option --delay with value '%s'\n", optarg);
				break;
			case 'p':
				printf("option --port with value %s\n", optarg);
				break;
			case 'v':
				printf("version is 1.11111\n");
				break;
			case '?':
			case 'h':
				printf("help info \n");
				exit(0);
				break;
		}
	}
	return 0;


}
