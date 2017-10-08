#include <stdarg.h>
#include <algorithm>
#include <algorithm>
#include <dirent.h>
#include <fstream>
#include <fstream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
// 2011_04_06_17:05:12   星期三   add by greshem
//  之前的 singleton 的例子写的不算完整, 这个是比较完整的单例 方案. 
using namespace std;
class log
{
private:
static	FILE *m_fp;	
	static log *m_data;

public:
	log(string filename);
	int logger(char *format, ...);

	static log *InstancePtr();
	static log Instance();
};


log* log::m_data = NULL;
FILE *log::m_fp =NULL;
log::log(string filename=string("all.log"))
{
	if(m_fp==NULL)
	{
		m_fp=fopen(filename.c_str(), "w");
		//m_fp=fopen(filename.c_str(), "a"); 导致文件无限增大.
	}
}
int log::logger( char *format, ...)
{	
	static char tmp[1024];
	memset(tmp,'\0', sizeof(tmp));
	va_list(marker);
	va_start(marker, format);
	vsprintf(tmp, format, marker);
	va_end(marker);
	fprintf(m_fp,"%s", tmp);
	if(ftell(m_fp)> 1024*1024*1)
	{
		fseek(m_fp, 0,SEEK_SET);
	}
	return 1;
}


log* log::InstancePtr()
{
	if(m_data == NULL)//未被初始化
	{ 
		m_data = new log;
	}
	return m_data;
}

log log::Instance()
{
	if(m_data == NULL)//未被初始化
	{ 
		m_data = new log;
	}
	return *m_data;
}


int main(int argc, char *argv[])
{
	for(int i=0; i<=1000;i++)
	{
		log::Instance().logger("%s\n","tes33333333333333333333333333t");
		log::Instance().logger("%d\n",333);
		log::InstancePtr()->logger("%d\n",333);
	}
}

