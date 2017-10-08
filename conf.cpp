#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <stdio.h>


#include "conf.h"

using namespace std;

CConfFile::CConfFile(const string & conf_fname) : m_conf_fname(conf_fname)
{}

CConfFile::~CConfFile()
{}

#define MAX_SEG_COUNT 	8
#define MAX_SEG_LEN		256
#define MAX_PATH		256
#define min(a,b)    (a) >= (b) ? (b) : (a)
#define ALLOCATE(x) for (int i = 0; i < MAX_SEG_COUNT; i++) \
						x[i] = new char [MAX_SEG_LEN]; 
#define ZERO(x)		for (int i = 0; i < MAX_SEG_COUNT; i++) \
						memset(x[i], 0, MAX_SEG_LEN);
#define FREE(x)		for (int i = 0; i < MAX_SEG_COUNT; i++) \
						delete [] x[i];


int CConfFile::parse_file(string file=string("/etc/nwserv.conf") )
{
	if(file != string(""))
	{
		m_conf_fname=file;
	}

	struct stat stbuf;
	if (lstat(m_conf_fname.c_str(), &stbuf))
		return -ENOENT;
	
	int    file_fd = open(m_conf_fname.c_str(), O_RDONLY);
	if (file_fd < 0)
	{
		return -ENOENT;
	}

	char * file_buf = new char [stbuf.st_size+1];
	read(file_fd, file_buf, stbuf.st_size);
	close(file_fd);
	file_buf[stbuf.st_size]='\0';

	m_data=string(file_buf);

}
/****************************************************************************
* Description	 get 还有 文件读取的职责 , 应该把他们分开, parse_file  
* @param 	
* @return 	
****************************************************************************/
int CConfFile::get_item( int section, int index, string & item)
{
	//fixme index 如何检测 是否操作最大? 单纯的用 MAX_SEG_COUNT 不够通用.  
	if (section <= 0 || index <= 0 || m_conf_fname.length() <= 0)
		return -EINVAL;


	
	char * cr = NULL;
	char * left_string = (char *)m_data.c_str();
	char *ppseg[MAX_SEG_COUNT];

	ALLOCATE(ppseg);
	
	while ((cr = strchr(left_string, '\n')))
	{
		char * line = left_string;
		*cr = '\0';
		left_string = cr + 1;

		ZERO(ppseg);
	
		sscanf(line, "%s%s%s%s%s%s%s%s", ppseg[0], ppseg[1], ppseg[2], ppseg[3], ppseg[4], 
															 ppseg[5], ppseg[6], ppseg[7]);

		if (ppseg[0][0] == '#' || !strlen(ppseg[0])) // 是注释行.
			continue;
		if (atoi(ppseg[0]) == section)
		{
			item = ppseg[index];
			break;
		}
	}

	FREE(ppseg);	
	return item.length() > 0 ? 0 : -1;
}

/****************************************************************************
* Description: set 之后默认 保存文件. 
* @param 	
* @return 	
****************************************************************************/
int CConfFile::set_item(int section, int index, const string & item)
{
	if (section <= 0 || index <= 0 || m_conf_fname.length() <= 0)
		return -EINVAL;
	
		
	char * file_buf = (char*)m_data.c_str();;

	char * cr = NULL;
	int  rc = 0;
	char * left = file_buf;
	char *ppseg[MAX_SEG_COUNT];

	ALLOCATE(ppseg);

	string header_part;
	string middle_part;
	string buttom_part;

	int part1;
	int part2;
	char line[MAX_PATH];	
	while ((cr = strchr(left, '\n')))
	{
		memset(line, 0, MAX_PATH);
		strncpy(line, left, min(MAX_PATH - 1, (size_t)(cr - left)));
		left = cr + 1;

		ZERO(ppseg);
		sscanf(line, "%s%s%s%s%s%s%s%s", ppseg[0], ppseg[1], ppseg[2], ppseg[3],
										 ppseg[4], ppseg[5], ppseg[6], ppseg[7]);
		if (ppseg[0][0] == '#' || !strlen(ppseg[0]))
			continue;
		if (atoi(ppseg[0]) == section)
		{
			memset(ppseg[index], 0, MAX_SEG_LEN);
			strcpy(ppseg[index], item.c_str());

			// file_fd = open(m_conf_fname.c_str(), O_WRONLY);
			// if (file_fd < 0)
			// {
			// 	break;
			// }

			//fix 用这样的方式 逃避 在内存中块的处理,  		或者 职责不分明. 
			//内存中的操作和 文件的操作尽量的分开. 
			int header_length= (size_t)(cr - file_buf) - strlen(line);
			//write(file_fd, file_buf, header_length);
			
			char *buffer= (char*)malloc(header_length+1);
			memcpy(file_buf, buffer, header_length);
			buffer[header_length]='\0';
			free(buffer);	

			header_part=string(buffer);

//========================================================================
			for (int i = 0; i < MAX_SEG_COUNT; i++)
			{
			//	write(file_fd, ppseg[i], strlen(ppseg[i]));
			//	write(file_fd, " ", 1);	

				middle_part+=string(ppseg[i]);
				middle_part+=string(" ");
			}
			//write(file_fd, "\n", 1);
			middle_part+=string("\n");
//========================================================================

			//write(file_fd, left, stbuf.st_size - (left - file_buf)); 
			//close(file_fd);
	
			int buttom_length=(size_t)((m_data.size() - (left -file_buf) ));
			buffer=(char*)malloc(buttom_length+1);
			memcpy(left, buffer, buttom_length);
			buffer[buttom_length]='\0';
	
			buttom_part=string(buffer);
			rc = 0;
			break;

		}
	}

	FREE(ppseg);	
	delete [] file_buf;	
	return rc; 
}


string  CConfFile::get_item(int section, int index)
{
	return "ERROR___";
}
int main()
{
}
