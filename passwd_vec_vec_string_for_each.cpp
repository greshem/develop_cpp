#include <stdlib.h>
//#include <unitlib.h>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <gtest/gtest.h>
//2011_04_01 by greshem. 


using namespace std;

vector<string > g_lines;
vector<vector<string > > g_words;

/****************************************************************************
* Description	: 一般把从shell_exec 执行返回的字符串进行分割. , 也可以是 file_get_content();
* @param 	
*		stringlist 输出, 
*		soruce 		要被分割的句子.	
*		separator 	分割符号.
* @return, 	
****************************************************************************/
template<typename T>  void split(T & stringlist,const string& source,const string separator=string(":") )
{
	int start = 0;
	//fixme, unsigned int 会造成死循环 , why?  
	//unsigned int end = source.find_first_of(separator);
	int end = source.find_first_of(separator);
	while(end != string::npos)
	{
		stringlist.push_back(source.substr(start,end-start));
		start = end +1;
		end = source.find(separator,start);
	}
	//最后一行是空行 不要加入.
	//stringlist.push_back(source.substr(start,source.length()-start));
}


//用来 for_each vector<string> 的 print string 的hook.   
template <typename T> class print {
		public:
			//========================================================================
			//ok 没有错误的.
			// print  operator ()( string in)
			// {
			// 	//vector<string> array;
			// 	//split<vector<string> > (array, m_line); 	
			// 	cout<<in<<endl;
			// 	return *this;
			// }
			//========================================================================
				int  operator ()( string in)
			{
				//vector<string> array;
				//split<vector<string> > (array, m_line); 	
				cout<<in<<endl;
				return 1;
			}

	};

//用来 for_each vector<string> 的 通过: 分割  string 的hook.   
template <typename T> class split_to_word
{
public:
		int operator() (string in)
		{
		 	vector<string> words;
			split<vector<string> > (words, in);
			g_words.push_back(words);
			return 1;
		}
};


//words vec_vec_str 化后. 对vector<vector<string> > 的 vector<string> 的打印.  
template <typename T> class echo_vec_str
{
	public:
	int operator() (vector<string> &in )
	{
        copy(in.begin(),in.end(),ostream_iterator<string>(cout,"|"));
		cout<<endl;
		return 1;
	}
}
;

//========================================================================
// 把 数组 分割成 矩阵. 
void split_lines_to_words(vector<string> lines, vector<vector<string> > &out )
{	
	//for 方式的循环 不够直接. 
	vector<string>::iterator it;
	for(it= lines.begin(); it!= lines.end(); it++)
	{
		vector<string> tmp_array_words;
		split<vector<string> > (tmp_array_words, *it);	
		out.push_back(tmp_array_words);
	}
	return ;
}

//########################################################################
int main(int argc, char *argv[])
{
	string file_str;
	
	file_get_content<char>("/etc/passwd", file_str);

	//文件放到 vector<string> 中.
	split<vector<string> > (g_lines,  file_str, "\n");
	
	print<string> echo;
	//for_each (g_lines.begin(), g_lines.end(), echo  );  //打印每行. 
	//------------------------------------------------------------------------


	split_to_word<string>  split_words;
	
	for_each (g_lines.begin(), g_lines.end(), split_words );  
	//也可以用下面的方式. 
	//split_lines_to_words(vector<string> lines, vector<vector<string> > &out )

	
	//========================================================================
	//foreach   方式历遍. 
		//split_line_and_save test;
	echo_vec_str< vector<string > >  echo_vec;
	for_each(g_words.begin(),  g_words.end(),	echo_vec);
}


