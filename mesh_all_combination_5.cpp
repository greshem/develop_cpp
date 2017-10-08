#include <algorithm>
#include <dirent.h>
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
//########################################################################
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
using namespace std; 


int MeshAllString(vector<vector<string> > In, string right, string PathPattern );

int  MeshAll( vector<vector<string> > In, string PathPattern )
{
    int size=In.size();
	//vector<vector<string> >  	vec_vec_str2(In.begin(), In.begin()+size-1);
	vector<string> right2(In[size-1]);
	
	vector<vector<string> > In2(In.begin(), In.begin()+size-1);
	vector<string>::iterator it;

	for(it=right2.begin(); it!=right2.end(); it++)
	{
		cout<<"Deal with "<<(*it).c_str()<<endl;
		MeshAllString(In2, *it, PathPattern);
	}
	return 1;
}

/*##############################################################################
# A(n)=sting+A(n-1);采用这样的递归的方式。 
#
#返回的vector<string> 长度为  size(In[0]) * size(In[1]) *  ..... * size(In[n]); 
##############################################################################*/
int MeshAllString(vector<vector<string> > In, string right, string PathPattern )
{

	string temp(right);
	int size=In.size();
	vector<vector<string> > vec_vec_str_temp(In.begin(), In.begin()+size-1);
	vector<string> vec_str_temp(In[0]);
	vector<string>::iterator it;

	
	if(size== 1)
	{
			//历遍， 并全部放入全局 vec<MString> m_vecRulerFormatString 中。 
			for(it=vec_str_temp.begin(); it!=vec_str_temp.end() ; it++)
			{
				//temp=right 这里一定要赋值为当前递归函数的 right 的参数 保持 字符串长度的一致。
				//cout<<"FFFFFFFFFFFFF"<<(*it)<<endl;
				temp=right;
				temp+=*it;
				cout<<temp.c_str()<<endl;
				string path_pattern=PathPattern;
	//			cout<<path_pattern<<endl;
				//StringReplace(path_pattern, "__REPLACE_PATTERN__", temp);
				//m_vecRulerFormatString.push_back(path_pattern);
			}
			return 1;
	}
	else
	{
		vec_str_temp = In[size-1];
		for(it=vec_str_temp.begin(); it!=vec_str_temp.end() ; it++)
		{
			temp=right;
			temp+=*it;
			MeshAllString(vec_vec_str_temp, temp, PathPattern);

		}
			
	}	

	return 1;
}

using namespace std;
int main(int argc, char *argv[])
{
	vector<vector<string> >  vec_vec_str;
	
	vector<string> vecStr0, vecStr1, vecStr2;
	
	MString <char> tmp;
	for(int i=0; i<=10; i++)
	{
		tmp.FormatString("wenwen_%d", i);
		vecStr0.push_back(tmp.c_str());	
		tmp.FormatString("qianqian_%d", i);
		vecStr1.push_back(tmp.c_str());	
		tmp.FormatString("fangfang_%d", i);
		vecStr2.push_back(tmp.c_str());	
	}

	vec_vec_str.push_back(vecStr0);
	vec_vec_str.push_back(vecStr1);
	vec_vec_str.push_back(vecStr2);


 	MeshAll( vec_vec_str, "111111111111" );

	return 0;
}
