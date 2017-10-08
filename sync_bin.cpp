#include <algorithm>
#include <fstream>
#include <glob.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <mntent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/mount.h>
#include <vector> 
//#include <Baselib.hpp> 
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_13 by qzj. 

using namespace std;
int glob_suffix(vector<string> &in, string pattern);
int mount_sda1();
int copyToSda1(vector<string> &in);

int release();
int main(int argc, char *argv[])
{

	vector<string> shVecStr, plVecStr;
	if(mount_sda1() !=0)
	{
		
		printf("%s\n", strerror(errno));
		die<char> ("mount  to /mnt/sda1 error\n");	
	}


	glob_suffix(shVecStr, "/bin/*.sh");
	glob_suffix(plVecStr, "/bin/*.pl");
	
	copyToSda1(shVecStr);
	copyToSda1(plVecStr);
	release();

	return 1;
}
int copyToSda1(vector<string> &in)
{
	vector<string>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		//cout<<"copy "<<*it<< "\t/mnt/sda1"<<*it<<endl;
		string src=*it;
		string dest="/mnt/sda1"+src;
		cout<<"cp  "<<src<<"\t"<<dest<<endl;;
		int ret=MFile<char>::CopyFile(src.c_str(),  dest.c_str(), false);
		if(ret != 1)
		{
			log.WriteError("拷贝", " %s 文件拷贝错误 %d ", src.c_str(), ret);
		}
	}
	return 1;
}
int glob_suffix(vector<string> &in, string pattern)
{
	glob_t gl;
	int e;
	int cnt;	
	e=glob(pattern.c_str(), 0,NULL, &gl);
	int count=gl.gl_pathc;
	for(int i=0; i<count;i++)
	{
		in.push_back(gl.gl_pathv[i]);
		cnt++;
	}
	globfree(&gl);
	return cnt;
}

int mount_sda1()
{
	int ret=mount("/dev/sda1","/mnt/sda1", "vfat", 0, "iocharset=gb2312");
	// 修改成MS_RDONLY 导致 MFILE::CopyFile 失败，因为这个程序会先删除这个文件的， 
	// 文件也删除不了， 同时create 也会失败。 
	//int ret=mount("/dev/sda1","/mnt/sda1", "vfat", MS_RDONLY, "iocharset=gb2312");
	if( ret!=0 )
	{
		log.WriteError("mount", "mount 失败, 系统错误号%d %s", errno, strerror(errno));
	}
	else
	{
		log.WriteError("mount", "mount 	 成功\n");
	}
	return ret;
}
int release()
{
	int ret=umount("/mnt/sda1");
	if(ret !=0)
	{
		log.WriteError("umount",  "umount ret=%d, %s",  errno, strerror(errno));
		return ret;
	}
	return ret;
}
int release_fstab()
{
	FILE *fp;
	fp=fopen("/etc/fstab", "r");
	if(fp==NULL)
	{
		printf("open file /etc/fstab error\n");
		return -1;
	}
	struct mntent  *mnt;
	while((mnt = getmntent(fp)))
	{
		if(strstr(mnt->mnt_fsname, "sda1"))
		{
			int ret=umount("/mnt/sda1");
			if(ret != 0)
			{
				log.WriteError("umount", "umount ret=%d, %s",  errno, strerror(errno));
				return ret;
			}
		}
	}
	return 1;	
}
