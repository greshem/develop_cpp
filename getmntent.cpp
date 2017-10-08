#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
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
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <mntent.h>
#include <map>
//2010_07_13 by qzj. 
using namespace std;
int dump(mntent *in)
{
	cout<<"####################################"<<endl;
	cout<<in->mnt_fsname<<"\t";
	cout<<in->mnt_dir<<"\t";
	cout<<in->mnt_type<<"\t";
	cout<<in->mnt_opts<<endl;
	return 1;
}
int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen("/etc/fstab","r");
	if(fp ==NULL)
	{
		die<char> ("getmntent failed");
	}
	//struct mntent mef;
	struct mntent *mnt;
	while( (mnt=getmntent(fp)) )
	{
		dump(mnt);
	}
	
	fclose(fp);	
	return 0;
}

