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
* Description	: һ��Ѵ�shell_exec ִ�з��ص��ַ������зָ�. , Ҳ������ file_get_content();
* @param 	
*		stringlist ���, 
*		soruce 		Ҫ���ָ�ľ���.	
*		separator 	�ָ����.
* @return, 	
****************************************************************************/
template<typename T>  void split(T & stringlist,const string& source,const string separator=string(":") )
{
	int start = 0;
	//fixme, unsigned int �������ѭ�� , why?  
	//unsigned int end = source.find_first_of(separator);
	int end = source.find_first_of(separator);
	while(end != string::npos)
	{
		stringlist.push_back(source.substr(start,end-start));
		start = end +1;
		end = source.find(separator,start);
	}
	//���һ���ǿ��� ��Ҫ����.
	//stringlist.push_back(source.substr(start,source.length()-start));
}


//���� for_each vector<string> �� print string ��hook.   
template <typename T> class print {
		public:
			//========================================================================
			//ok û�д����.
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

//���� for_each vector<string> �� ͨ��: �ָ�  string ��hook.   
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


//words vec_vec_str ����. ��vector<vector<string> > �� vector<string> �Ĵ�ӡ.  
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
// �� ���� �ָ�� ����. 
void split_lines_to_words(vector<string> lines, vector<vector<string> > &out )
{	
	//for ��ʽ��ѭ�� ����ֱ��. 
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

	//�ļ��ŵ� vector<string> ��.
	split<vector<string> > (g_lines,  file_str, "\n");
	
	print<string> echo;
	//for_each (g_lines.begin(), g_lines.end(), echo  );  //��ӡÿ��. 
	//------------------------------------------------------------------------


	split_to_word<string>  split_words;
	
	for_each (g_lines.begin(), g_lines.end(), split_words );  
	//Ҳ����������ķ�ʽ. 
	//split_lines_to_words(vector<string> lines, vector<vector<string> > &out )

	
	//========================================================================
	//foreach   ��ʽ����. 
		//split_line_and_save test;
	echo_vec_str< vector<string > >  echo_vec;
	for_each(g_words.begin(),  g_words.end(),	echo_vec);
}


