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

#define INITIAL_MAXARGC 16;

#ifdef WINDOWSCODE
#define isblank(a) ((a=='\n')|| (a=='\ ')||(a=='\t'))
#else
#endif
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
int main()
{
	char **tmp; 
	tmp=buildargv ("--help test --version 3.3.33  --port 94");

	while( (*tmp))
	{
		printf("%s\n", *tmp);
		tmp++;
	}
#ifdef BUG
	free(tmp);
#endif

}
