#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
using namespace std;
int main()
{

	string m_strFilaName="/etc/passwd";
	std::ofstream  file( m_strFilaName.c_str(), std::ios::out );

	if( file )
	{
		file<<"reconnect count:\t"<<m_lReconnectCount<<std::endl;

		TIMESTAT::const_iterator iter;
		for( iter = m_timeStat.begin(); iter != m_timeStat.end(); ++iter )
		{
			file<<"reqNo:"<<iter->first<<std::endl;
			file<<iter->second ;
			file<<std::endl;
		}

		file.close();
	}
}
