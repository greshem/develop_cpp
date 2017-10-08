#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>

//#include <gtest/gtest.h>
//2010_08_27 by greshem. 
//1.tar 文件， 文件后面有很多的填充的扇区， 最少是10k的文件， 好像， 可以用 几个小的文件测试一下。 
//2. 最后填充的 block 不一定只有一个, 记得有些资料上说是1个其实是错误的。  
//name[100] 
using namespace std;
#ifdef WINDOWSCODE
#else
int find(char *in, vector<string> &out)
{
	//printf("##### %s\n", in);
	string pwd(in);
	static char cwd[1024];
	DIR *dirp;
	struct dirent *dp;
	if((dirp=opendir(pwd.c_str() ) )==NULL)
	{
		printf("opendir error\n");
		return -1;
	}
	chdir(pwd.c_str());
	getcwd(cwd, 1024);

	while((dp=readdir(dirp)))
	{
		if(dp->d_type==DT_DIR)
		{
			if(strcmp(dp->d_name, ".")==0)			
			{
				continue;
			}
			if(strcmp(dp->d_name,"..") == 0)
			{
				continue;
			}

			//printf("%s/%s", cwd, dp->d_name);
			 char    path[1024];
			memset(path, '\0', 1024);
			sprintf(path, "%s/%s", pwd.c_str(), dp->d_name);
			find(path, out );
		}
		else //if (dp->d_type==DT_FILE)
		{
			//printf("%s/%s\n",cwd, dp->d_name);
			char file[1024];
			
			sprintf(file, "%s/%s", pwd.c_str(), dp->d_name);
			struct stat st;
			stat(file,  &st);
			if(  S_ISREG(st.st_mode))
			{
				out.push_back(file);
			}
		}
	}
	closedir(dirp);
return 0;
}
#endif


typedef struct tar_header
{
char name[100];
char mode[8];
char uid[8];
char gid[8];
char size[12];
char mtime[12];
char chksum[8];
char typeflag;
char linkname[100];
char magic[6];
char version[2];
char uname[32];
char gname[32];
char devmajor[8];
char devminor[8];
char prefix[155];
char padding[12];
} HEADER;


using namespace std;
int dump_one_tar(string filename);

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

int putToTarball( FILE *out, string &in);


int putToTarball( FILE *out, string &in)
{
		HEADER tarheader;	
		char buffer[512];
		FILE * fd=fopen(in.c_str(), "r");
		if(fd ==NULL)
		{
		//	warn<char>("open file %s error\n", in.c_str());		
			return -1;
		}

	   const unsigned char *cp;
        int chksum, size;

		memset(&tarheader, '\0', sizeof(tarheader));
		strncpy(tarheader.name, in.c_str(), sizeof(tarheader.name));
		
	 	memset(tarheader.chksum, ' ', sizeof(tarheader.chksum));
        cp = (const unsigned char *) &tarheader;
        	
		 //sprintf(tarheader.size, "%o", filesize<char>(argv[i]));
		 //
		
#ifdef WINDOWSCODE
		struct _stat st;
		::_stat(in.c_str(), &st);
		sprintf(tarheader.size, "%12o",st.st_size);	
#else
		sprintf(tarheader.size, "%12o", filesize<char>(in.c_str()));
#endif
		for(int i=0; i<=11; i++)
		{
			if(tarheader.size[i] == 0x20)
			{
				tarheader.size[i]='0';
			}
		}	
		tarheader.version[0]=0x20;
		tarheader.version[1]=0x20;
		//printf("%s\n", tarheader.size);
		strncpy(tarheader.magic,"ustar", 6);
		//checksum code. 	
		chksum = 0;
        size = sizeof( tarheader);
        do { chksum += *cp++; } while (--size);
		printf("### %o\n", chksum);
        putOctal(tarheader.chksum, sizeof(tarheader.chksum)-1, chksum);

		fwrite((void *)&tarheader, 1, sizeof(buffer), out);
		int ret=0;
		while( (ret=fread( buffer, 1, sizeof(buffer),fd))>0)
		{
			fwrite( buffer, 1, ret, out);	
			//printf("%d\n", ret);
			if(ret < 512)
			{
				//fseek(out, SEEK_END, (512-ret));
				memset(buffer, '\0', sizeof(buffer));
				fwrite( buffer, 1, 512-ret, out);
			}
		}
		printf("%d, %d\n",  ftell(out), ftell(out)%512);
		assert((ftell(out) %512) ==0);
		fclose(fd);

}

//########################################################################
int main(int argc, char *argv[])
{
//	logger.Instance(MString<char>(argv[0])+".log", 1000);
//	logger.WriteError("test", "test");


	assert(sizeof(HEADER)==512);
	
	if(argc < 2)
	{
	printf("Usage: %s in_file  in_file1 file2 file3     out_file.tar \n", argv[0]);
	exit(0);
	}

	FILE* out=fopen(argv[argc-1], "wb+");
	if(out== NULL)
	{
#ifdef WINDOWSCODE
		printf("create dest file error %s\n", argv[argc-1]);
#else
		die<char>("create  dest file error\n");		
#endif
	}

	for(int i=1;i< argc-1; i++)
	{
		string file(argv[i]);
		putToTarball(out, file);	
	}
	vector<string> vecStr; 
#ifdef WINDOWSCODE
#else
	find("/etc/", vecStr);
	
	for(vector<string>::iterator it=vecStr.begin(); it!= vecStr.end(); it++)
	{
		putToTarball(out, *it);
	}
#endif
	fclose(out);

	//assert(filesize<char>(argv[1]) == filesize<char>(argv[2]));
	return 0;

	return 0;
}

