
#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

using namespace std;
/****************************************************************************
 * Description   一块内存用 ascii来随机填充.
 * @param    
 * @return   
 * *************************************************************************/
template <typename T> void  rand_mem_with_ascii (char *input, int strLen)
{
	if(input == NULL|| strLen==0 )
	{
		return ;
	}

    for (int i=0; i< strLen; i++)
    {
        *(input+i)='a'+rand()%26;
    }
    input[strLen]='\0';
}


int main()
{
	return 0;
}
