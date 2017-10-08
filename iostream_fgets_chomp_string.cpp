#include <stdio.h>
#include <string.h>
//fgets 的终止条件是, 直到出现换行字符、读到文件尾或是已读了size-1个字符为止
int  chomp( char *line, int size )
{
     if (size == 0)
     {
             return -1;
     }     
     while(size--)
     {
                  if(line[size] == '\n') 
                  {
                    line[size]='\0';
                    break;
                  }
     }
	 return 1;
}
main( void )
{
   FILE *stream;
   char line[100];

   if( (stream = fopen( "fgets.cpp", "r" )) != NULL )
   {
      while( fgets( line, 100, stream ) )
      {
         chomp( line, 100);
         printf( "%s", line);
      }
      fclose( stream );
   }
//   getchar();
}
