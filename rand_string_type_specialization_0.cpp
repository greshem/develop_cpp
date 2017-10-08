// //
//qzj 20100629, 把之前的零散的 randstring 函数 整理一下 . 
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#include <iostream> 
#include <algorithm>
#include <iterator> 
using namespace std;
//string RandString(int strLen);
//vector<string> RandVecString(int strLen, int size);

struct  addSuffix
{
        string m_suffix;
        addSuffix(string in):m_suffix(in){};
        int operator() ( string &in)
        {
            in+=m_suffix;
            return 1;
        }
};
//###############################################################################
template <typename T>  string RandString(int strLen)
{
	return string("");
};

template <> string RandString< char > (int strLen)
{
	char *tmp;

	tmp=new char[strLen+1];
	tmp[strLen]='\0';
	
    for (int i=0; i< strLen; i++)
    {   
        *(tmp+i)='a'+rand()%26;
    }  
    string retStr(tmp);		
	delete[] tmp;
	return retStr;
}
//###############################################################################
template <typename T> string RandPath (int number)
{
	 return string("");
};

template <> string RandPath< char > (int number)
{
	static int  pathLength=8;
	string path("./");
	for(int i=0;i<=number; i++)
	{
		path+=RandString<char>(rand()%pathLength +1 );
		path+="/";	
	}
	return path;
}
//###############################################################################/
template < typename T> string  RandFilePath(int number)
{
	return string("");	
}

template <> string RandFilePath<char > (int number)
{
	static int  pathLength=8;
	string path("./");
	for(int i=0;i<=number; i++)
	{
		path+=RandString<char>(rand()%pathLength +1 );
		path+="/";	
	}
	
	path+=RandString<char>(rand()%pathLength +1 );
	return path;

}
//###############################################################################
template <typename T> vector<string> RandVecString(int strLen, int size)
{
	vector<string> tmp;
	return tmp;
}

template <> vector<string> RandVecString<char > (int strLen, int size)
{
	//int i=0;
	vector<string> vecStr;
	for(int i=0; i< size; i++)
	{
		
		vecStr.push_back(RandString<char>(strLen));
	}
	return vecStr;
}
//###############################################################################
template < typename T> char  * stringFromFile(char *fileName)
{
	return NULL;
}

template <>  char  * stringFromFile<char > (char *fileName)
{	
    char *str;
	struct stat st;
	if(stat(fileName, &st)< 0)
    {
       return "";
    }
	int fd;
	fd=open(fileName, O_RDONLY);
	if(fd <0 )
	{	
		return "";
	}
	str=(char*)malloc(st.st_size+1);
	read(fd,str,st.st_size);
	str[st.st_size+1]='\0';
	close(fd);
	return str;
	
}


int main()
{
	printf("%s\n", stringFromFile<char> ("/etc/passwd"));
}
/*int main(int argc, char *argv[])
{
	vector<string> vecStr =  RandVecString(10, 100);
	cout<<"size = "<<vecStr.size()<<endl;
	//for_each(vecStr.begin(), vecStr.end(), myPrint );
	sort(vecStr.begin(), vecStr.end());
	//for_each(vecStr.begin(), vecStr.end(), myPrint );
	for_each(vecStr.begin(), vecStr.end(), addSuffix(".mp3"));
	for_each(vecStr.begin(), vecStr.end(), addSuffix(".mp3"));
   copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "\n"));
   getchar();
	return 1;
}*/
