#include <stdlib.h>
#include <stdio.h>
#include <iterator>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <iostream> 
#include <map>
#include <sys/stat.h>
#include <magic.h> 
#include <unistd.h>
#include <boost/regex.hpp> 
//todo
//1. 添加网络层， 做成服务器， 提供查询信息。 
//2. 压缩， 如何压缩， 字符串， 导入导出 二进制。 
//3. 内存里面的多索引， 用BOOST
//4。把 对sf_mirror 的处理， 进行优化，  sf 
//5. 所有的url basename, -> url , 
//6. 打印颜色。 
//7. 索引所有的文件类型， key->value 的方式。  value 用 |进行分割， 或者再用 rope 进行封装。 
using namespace std;
struct magic_set *gMagic=NULL;
//qzj 20100622 , 处理一个目录下的文件信息的索引， 
//之前写的 readdir 的历遍的函数都有些问题， 不过明确， 这个和之前perl 写的 readdir 差不多了， 足够明确了， 
//用一个 static char tmp[1024] 肯定有问题， 每个递归的函数都需要有自己的堆栈控件， static 一写就没有了， 递归的上一层的函数， 就不知道自己的
//状态了。  
//20100623 添加 file magic 
//添加getText , getTargz
void  number2Hum( int num);
 class printSize
			{
				public:
				printSize(){};	
				void operator () ( string  &in)
				{
					struct stat st;
					stat(in.c_str(), &st);
					cout<<in<<"--> "<< st.st_size<<endl;
				}	
			};
void printSize2(string &in)
			{
					struct stat st;
					stat(in.c_str(), &st);
					cout<<in<<"--> "<< st.st_size<<endl;
					number2Hum(st.st_size);
			};
string myMtime( time_t in)
{
		struct tm *tmp;
		char buffer[1024];
		memset(buffer, '\0', sizeof(buffer));
		tmp=localtime(&in);
		strftime(buffer, sizeof(buffer), "%Y_%m_%d_%T", tmp);
		return string(buffer);
		
}
void printMtime(string &in)
			{
					struct stat st;
					stat(in.c_str(), &st);
					cout<<in<<"--> "<< myMtime(st.st_mtime)<<endl;
				//	number2Hum(st.st_size);
			};


int find(char *in, vector<string> &out );
string basename(string &in)
{
	string basename=in.substr(in.rfind('/')+1, in.length());
	return basename;
}

int path2map(vector<string> &in  , map<string, string>  &out)
{
	vector<string>::iterator it;
	for(it=in.begin(); it != in.end(); it++)
	{
		string tmp=basename(*it);
		out.insert(make_pair(tmp, *it));
	}
	return 1;
}
//dump 处理的是map 的时候
template < class A , class T> ostream &  operator   << (ostream &in ,const pair<A, T> &my)
{
    in << my.first;
	in << "\t -->";
    in << my.second;
    in << endl;
    return in; 
};

//
//template< typename   >int  dump( P &in)
//{
/*	typedef P::iterator tt ;
	tt it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		cout<< *it<<endl;
	}
	return 1;
}*/
int  dump( map<string, string>  &in)
{
	map<string , string> ::iterator it ;
	for(it=in.begin(); it!= in.end(); it++)
	{
		cout<< *it ;
	}
	return 1;
}

void  number2Hum( int num)
{
//#define out cout;	
	if(0 < num && num  < 1024)
	{
		cout << num;
	}
	else if (1024< num && num  < 1024 * 1024)
	{
		num/=1024;
		cout << num <<"k";
	}
	else if( 1024*1024 < num && num  < 1024*1024*1024)
	{
		num/=1024*1024;
		cout << num<<"M";
	}
	else if( 1024*1024*1024 < num  && num < 1024*1024*1024*1024)
	{
		num/=1024*1024*1024;
		cout<<num<<"G";
	}
	else
	{
	cout<<num;
	}
	//return out;
//#undef out
	
}
bool  CmpBySize(const string &lhs, const string &rhs)
{
		struct stat st_lhs, st_rhs;
		stat(lhs.c_str(), &st_lhs);
		stat(rhs.c_str(), &st_rhs);

		if( stat(lhs.c_str(), &st_lhs)< 0)
		{
			cout<<lhs<<"文件错误"<<endl;
			return false;
		}
		if(stat(rhs.c_str(), &st_rhs)< 0)
		{
			cout<<rhs<<"文件错误"<<endl;
			return false;
		}

		return ( st_lhs.st_size < st_rhs.st_size);
}
bool  CmpByMtime(const string &lhs, const string &rhs)
{
		//cout<<"lhs ->"<<lhs<<endl;;
		//cout<<"rhs ->"<<rhs<<endl;
		struct stat st_lhs, st_rhs;
		if( stat(lhs.c_str(), &st_lhs)< 0)
		{
			cout<<lhs<<"文件错误"<<endl;
			return false;
		}
		if(stat(rhs.c_str(), &st_rhs)< 0)
		{
			cout<<rhs<<"文件错误"<<endl;
			return false;
		}
		int a=st_lhs.st_mtime;
		int b=st_rhs.st_mtime;
		return (  a < b );
		//return ( st_lhs.st_size < st_rhs.st_size);
}


string getMagicString(string &file)
{
	const char *str=NULL;
	str=magic_file(gMagic, file.c_str());
	string magStr(str);
	return magStr;
}

bool IsText(string &filename)
{
	using namespace boost;
	string magicStr	= getMagicString(filename);
	regex reg("ascii\\s+text", regex::icase|regex::perl);
	if(regex_search(magicStr, reg) ==true)
	{
		return true;
	}	
	return false;
}
bool IsTargz(string &filename)
{
	using namespace boost;
	string magicStr	= getMagicString(filename);
	regex reg("gzip\\s+compressed", regex::icase|regex::perl);
	if(regex_search(magicStr, reg) ==true)
	{
		return true;
	}	
	return false;

}
void printText( string &filename)
{
		if(IsText(filename))
		{
			cout<<filename<<endl;
		}
}
void printTargz(string &filename)
{
		if(IsTargz (filename))
		{
			cout<<filename<<endl;
		}
}
class magicPrint{
public:
	magicPrint(){};
	void operator() (string &in )
	{
		cout<<in<<"\t-->"<<getMagicString(in)<<endl;
	}
};
void Usage();
magic_t magic_file_init()
{
	magic_t magic;
	magic = magic_open(MAGIC_NONE);
	if(magic==NULL)
	{
		cout<<"magic_open error\n";
		return NULL;
	}
	if(magic_load(magic, NULL) == -1)
	{
		cout<<"magic_load error\n";
		return NULL;
	}
	return magic;
}
int main(int argc, char *argv[])
{
	if((gMagic= magic_file_init()) ==NULL)
	{
		cout<<"magic system error"<<endl;
	}	
	string cmd;
	vector<string> fileName;
	map<string, string> mapFile2path;
	char *tmpbuf="/root";
	find(tmpbuf, fileName);
	path2map(fileName, mapFile2path);
	//sort(fileName.begin(), fileName.end(), CmpByMtime);
	
	Usage();
	//exit(1);
	while(1)
	{ 
		//getline(cin, cmd);
		cmd="quit";
		if(cmd=="size")
		{
			cout<< fileName.size()<<endl;		
		}
		else if( cmd== "print")
		{
			copy(fileName.begin(), fileName.end(), ostream_iterator<string> (cout, "\n"));
		}
		else if( cmd=="magicPrint")
		{
						for_each(fileName.begin(), fileName.end(),  magicPrint() );
		}
		else if( cmd=="sort")
		{
			sort(fileName.begin(), fileName.end());
		}
		else if( cmd=="basenameSet")
		{
			cout<<"basenameSet"<<endl;
		}
		else if( cmd=="printWithSize")
		{
						for_each(fileName.begin(), fileName.end(),  printSize2 );
						//for_each(fileName.begin(), fileName.end(),  printSize() );
		}
		else if( cmd=="sortByMtime")
		{
			cout<<"sortByMtime"<<endl;
			sort(fileName.begin(), fileName.end(), CmpByMtime);
			//sort(fileName.begin(), fileName.end(), CmpBySize);
			cout<<"sortByMtime OK "<<endl;
		}
		else if( cmd=="printWithMtime")
		{
						for_each(fileName.begin(), fileName.end(),  printMtime );
		}
		else if( cmd=="sortBySize")
		{
			cout<<"sortBySize"<<endl;
			sort(fileName.begin(), fileName.end(), CmpBySize);
			cout<<"sortBySize OK "<<endl;
			cout<<"printWithSize: print all file with size"<<endl;
			//for_each(fileName.begin(), fileName.end(),  printSize2 );
		}
		else if( cmd=="matach")
		{
			
		}
		else if( cmd=="path2map")
		{
			path2map(fileName, mapFile2path);
			//dump(mapFile2path);
			cout<<"mapdump:  dump all the mapFile2path "<<endl;
			
		}
		else if( cmd=="mapdump")
		{
			dump(mapFile2path);
		}
		else if( cmd=="mapSize")
		{
			cout<<"mapFile2path --> "<<mapFile2path.size()<<endl;
		}
		else if( cmd=="exit" || cmd=="quit" )
		{
			break;
		}
		else if( cmd=="help" || cmd=="Help")
		{
			Usage();
		}
		else if( cmd=="getText")
		{

			for_each(fileName.begin(), fileName.end(),  printText );
			cout<<"getText ok"<<endl;
		}
		else if( cmd=="getTargz")
		{

			for_each(fileName.begin(), fileName.end(),  printTargz );
			cout<<"getTargz ok"<<endl;
		}

		else
		{
			if(mapFile2path.find(cmd) == mapFile2path.end())
			{
				cout<<"not found"<<endl;
			}
			else
			{
				//下面的写法， 类型的隐藏太深了
				//cout<< *(mapFile2path.find(cmd)); 
				//magicPrint()( mapFile2path.find(cmd)->second); 
				//代码说明类型的转换， 
				//注意  *it 是pair<string, string> 类型. 
				map<string, string>::iterator it;
				it=mapFile2path.find(cmd);
				cout<< *it;
				magicPrint()(it->second);

			}
		}
	}
	return 0;
}

void Usage()
{
			cout<<"help: size , print,  sort, basenameSet, sortByMtime, sortBySize  path2map mapSize "<<endl;
			cout<<"\t nthSizeFile, top10Size , sortByWc, getTextFile, Match , nth, top100Size, "<<endl;
			cout<<"\t searchByType, FileTypeStat, histogram, indexText, Top10Mtime"<<endl;
}
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
		else//(dp->d_type==DT_FILE)
		{
			//printf("%s/%s\n",cwd, dp->d_name);
			char file[1024];
			sprintf(file, "%s/%s", pwd.c_str(), dp->d_name);
			out.push_back(file);
		}
	}
	closedir(dirp);
return 0;
}

