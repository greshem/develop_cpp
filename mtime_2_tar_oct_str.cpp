#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <gtest/gtest.h>
//2010_11_23 by greshem. 


using namespace std;
void putOctal(char *cp, int len, off_t value);  

int main(int argc, char *argv[])
{
	char buf[12];

	
	time_t t;
	time(&t);
	putOctal(buf, sizeof(buf), 100);
	printf("%s\n", buf);
	return 0;
}

void putOctal(char *cp, int len, off_t value)
{
        char tempBuffer[sizeof(off_t)*3+1];
        char *tempString = tempBuffer;
        int width;

        width = sprintf(tempBuffer, "%0*o", len, value);
        tempString += (width - len);

        /* If string has leading zeroes, we can drop one */
        /* and field will have trailing '\0' */
        /* (increases chances of compat with other tars) */
        if (tempString[0] == '0')
                tempString++;

        /* Copy the string to the field */
        memcpy(cp, tempString, len);
}
