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

#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <sys/mount.h>

//2010_07_12 by qzj. 
// 自己把 /mnt/sda1 写成了 mnt/sda1 错误
using namespace std;

int main(int argc, char *argv[])
{
	int ret=mount ("/dev/sda1", "/mnt/sda1", "vfat", MS_RDONLY ,"iocharset=gb2312");
	cout<<ret<<endl;
	cout<<errno<<endl;
	perror("bbbb");
	cout<<"################"<<endl;
	//perror();

	/*int ret=mount ("/mnt/sda1", "/mnt/sda1", "vfat", MS_RDONLY ,"iocharset=gb2312");
	cout<<ret<<endl;
	cout<<errno<<endl;
	cout<<"################"<<endl;*/
	return 0;
}
