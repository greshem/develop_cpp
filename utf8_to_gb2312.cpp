
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>		/* setlocale() */
#include <stringprep.h>

/*
 * Compiling using libtool and pkg-config is recommended:
 *
 * $ libtool cc -o example example.c `pkg-config --cflags --libs libidn`
 * $ ./example
 * Input string encoded as `ISO-8859-1': ª
 * Before locale2utf8 (length 2): aa 0a
 * Before stringprep (length 3): c2 aa 0a
 * After stringprep (length 2): 61 0a
 * stringprep_utf8_to_locale
 * $
 *
 */

int
main (int argc, char* argv[])
{
	char buf[BUFSIZ];
	char *p;
	int rc;
	size_t i;

	if(argv[1]==NULL)
	{
		printf("Usage:  %s input file\n", argv[0]);
		exit(0);
	}

	FILE *in=fopen(argv[1], "r");
	if(in==NULL)
	{
		printf("open file error\n");
		exit(0);
	}
	setlocale (LC_ALL, "");

	printf ("Input string encoded as `%s': ", stringprep_locale_charset ());
	fflush (stdout);
	
	while(fgets (buf, BUFSIZ, in) )
	{
		//############################################################################### 
		//plain
		printf("###############################################################################\n");
	//	printf("%s", buf);
		printf ("Before locale2utf8 (length %d): ", strlen (buf));
		printf("http://www.google.com/search?q=");
		for (i = 0; i < strlen (buf); i++)
		{	
			printf ("%%%02x", buf[i] & 0xFF);
		}
		printf ("\n");
		//###############################################################################
		//to utf8
		//p = stringprep_locale_to_utf8 (buf);

 		p=stringprep_utf8_to_locale(buf);
		if (p)
		{
		  strcpy (buf, p);
		  free (p);
		}
		else
		{
			printf ("Could not convert string to UTF-8, continuing anyway...\n");
		}
		
		printf ("Before stringprep (length %d): ", strlen (buf));
		for (i = 0; i < strlen (buf); i++)
		printf ("%02x ", buf[i] & 0xFF);
		printf ("\n");
		printf("%s", buf);
//		rc = stringprep (buf, BUFSIZ, 0, stringprep_nameprep);
//		if (rc != STRINGPREP_OK)
//		{
//			printf ("Stringprep failed (%d): %s\n", rc, stringprep_strerror (rc));
//		}
//		else
//		
//		{
//			printf ("After stringprep (length %d): ", strlen (buf));
//			printf("http://www.google.com/search?q=");
//			for (i = 0; i < strlen (buf); i++)
//			{
//				printf ("%%%02x", buf[i] & 0xFF);
//			}
//		  printf ("\n");
//		}

	}
	return 0;
}
