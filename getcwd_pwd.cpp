#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//#include <unistd.h>
//2010_09_02 by greshem. 



using namespace std;
string getpwd(void);
int main(int argc, char *argv[])
{

	string  str("getcwd.cpp");
	char buffer[256]={0};
	printf("%s\n", getcwd(buffer, sizeof(buffer)));
	//getcwd(buffer, sizeof(buffer));
	//getcwd(buffer );
	//perror("getcwd");
	//cout<< getpwd<char>()<<endl;
	return 0;
}


/****************************************************************************
* Description	
* @param 	
* @return 	
* *************************************************************************/
string getpwd_for_win(void)
{
#ifdef WINDOWSCODE
	char						tempbuf[256];

	if ( ::GetCurrentDirectory(256,tempbuf) == 0 )
	{
		return("");
	}
	
	if ( strlen(tempbuf) > 0 && tempbuf[strlen(tempbuf)-1] != '\\' )
	{
		strcat(tempbuf,"\\");	
	}

	return(tempbuf);
#else
	string tmp;
	return tmp;
#endif

}
string getpwd(void)
{
	char						tempbuf[256];
	
	if ( getcwd(tempbuf,256) < 0 )
	{
		return("");	
	}
	
	if ( strlen(tempbuf) > 0 && tempbuf[strlen(tempbuf)-1] != '/' )
	{
		strcat(tempbuf,"/");	
	}
	
	return(tempbuf);
}
