#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>

#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//2010_08_20 by qzj. 



class FastLogger
{
int m_recordLen;
private: 
	int 	mCount;
	char 	*data;
	int		m_curRec; 
	FILE	*m_filePtr;
	MString<char> m_filename;
public:
	FastLogger(MString<char> filename, unsigned int count=1024);
	int WriteError(MString<char> in);
	~FastLogger();

};

FastLogger::~FastLogger()
{
}
FastLogger::FastLogger(MString<char> filename , unsigned  int count)
{
	mCount=count;
	m_curRec=0;
	m_recordLen=256;

	if(filename=="")
	{
		m_filename="logger.log";	
	}
	else
	{
		m_filename=filename;		
	}

	m_filePtr=fopen(m_filename.c_str(), "w+");
	
	if(m_filePtr==NULL)
	{
		cout<<"logger.log 创建失败"<<endl;
	} 
	else
	{	
		//data= malloc(count* m_recordLen);
		if( ftruncate(fileno(m_filePtr), count*m_recordLen))
		{
			cout<<"设置文件长度失败"<<endl;
		}
	}
}

int FastLogger::WriteError(MString<char> in)
{
	if(m_filePtr==NULL)
	{
		cout<<in.c_str()<<endl;
		return 1;
	}
	char buffer[m_recordLen];
	int len;
	memset(	 buffer, ' ', sizeof(buffer));
	len=snprintf(buffer, strlen(in.c_str()), "\n%s", in.c_str());
	buffer[len-2]='\n';	
	fseek(m_filePtr, m_curRec*m_recordLen, SEEK_SET);
	fwrite(buffer, sizeof(buffer), 1, m_filePtr);
	m_curRec++;	
	if(m_curRec>=mCount)
	{
		m_curRec=0;
	}
	return 1;			
}
		
using namespace std;
int main(int argc, char *argv[])
{
	FastLogger logger("bbb.log", 256);
	for(int i=0; i<=1000; i++)
	{
		logger.WriteError("bbbbbbdfsadfafsafsafasfasfasfasfasfasfasfasfafafafafaf");
	}
	return 0;	
}

