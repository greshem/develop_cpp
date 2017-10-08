#ifndef __INI_FILE_HEADER__
#define  __INI_FILE_HEADER__
//#include "template_tools.h"
// 2014_08_07_10:40:58   星期四   add by greshem
// from /root/netware_emulator/trunk/data_engine/IniFile.hpp

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

/****************************************************************************
* Description: trim 去除左右空格. 	
* @param 	
* @return 	
* *************************************************************************/
inline string ltrim(string const &str) 
{
	for (unsigned i = 0; i < str.size(); i++)
	{
		if (!isspace(str[i]))
		{
			return str.substr(i);
		}
	}
	return "";
}
/****************************************************************************
* Description	
* @param 	
* @return 	
* *************************************************************************/
inline string rtrim(string const &str) 
{
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (!isspace(str[i]))
		{	
			return str.substr(0, i + 1);
		}
	}
	return "";
}
/****************************************************************************
* Description	
* @param 	
* @return 	
* *************************************************************************/
inline string trim(string const &str) 
{
	return rtrim(ltrim(str));
}


using namespace std;
//20100625 qzj mdf . 
//2010_08_23_11:32:02 add by qzj
//代码整理。 

  class IniFile 
{
public:
	typedef std::map<std::string, std::string> KeyValueMap;
	typedef std::map<std::string, KeyValueMap> SectionMap;
	IniFile() {}
	//默认只读取文件
	IniFile(const std::string& filename, bool append = false);
	~IniFile();

public:
	template <typename G> G   get(const std::string& section, const std::string& key) const;
	template <typename G> G   get(const std::string& section, const std::string& key, G defaultValue) const;

	template <typename G> void set(const std::string& section, const std::string& key, G value);

public:
	void save() const;
	void save(const std::string& filename) const;

	void save(const std::string& filename, int append=1) const;
	void save(std::ostream& out) const;

	void load(const std::string& filename, bool createFile =0);
	int  getSectionCount() const;
	int  getSections(vector<string> &out) const;

	bool hasSection(const std::string& section) const;
	bool hasKey(const std::string& section, const std::string& key) const;
	//const SectionMap& getSectionMap() const;
	int  getSectionMap() const;
	void removeSection(const std::string& section);
	void Dump();
private:
	
protected:
	void load_istream(std::istream& in);
	SectionMap m_dic;
	std::string m_filename;
};


//###############################################################################
 class IniFileError: public std::exception
{
public:
  IniFileError(): m_msg("Unspecified IniFile Error"){}

  IniFileError(const char* msg): m_msg(msg){}

  const char* what() const throw()
  {
    return m_msg;
  }

private:
  const char* m_msg;
};
//###############################################################################



/***************************************************
* Description	
* @param 	section:
* 			key:
* 			defaultValue: 默认值
* @return 	
* *************************************************/
template <typename G > G  IniFile::get(const std::string& section, const std::string& key, G defaultValue) const
{
	if (!hasKey(section, key)) 
	{
    	return defaultValue;
	} 
	else 
	{
		std::istringstream stream(m_dic.find(section)->second.find(key)->second);
		G t = G();
		stream >> t;
		if (!stream)
		{
			//throw IniFileError<char>("Invalid value when getting key");
			 printf("key is null");
		}
		return t;
	}
}


/***************************************************
* Description: 获取对应的值 
* @param 	
* 		section:
* 		key:
* @return 	
* *************************************************/
template <typename G> G IniFile::get(const std::string& section, const std::string& key) const
{
  return this->get(section, key, G());
}


/***************************************************
* Description: 内存中设置 ini 中的值	
* @param :
* 		section
* 		key	
* @return 	
* *************************************************/
 template< typename G> void IniFile::set(const std::string& section, const std::string& key, G value)
{
	std::ostringstream stream;
	stream << value;
	if (!stream)
	{
		printf("Invalid value when setting key");
	}
	
	if (m_dic.find(section) == m_dic.end()) 
	{
		m_dic[section] = KeyValueMap();
	}
	m_dic[section][key] = stream.str();
}

/****************************************************************************
* Description	把所有的keyvalue 都dump 出来. 
* @param 	
* @return 	
****************************************************************************/
 void IniFile::Dump()
{
	//m_dic;_
	map<string, map<string, string> >::iterator it1;
	map<string, string>::iterator it2;

	for(it1=m_dic.begin(); it1 != m_dic.end(); it1++)
	{
		cout<<"["<<(*it1).first<<"]"<<endl;
		for(it2=(*it1).second.begin(); it2!=(*it1).second.end(); it2++)
		{
			cout<<"\t"<<(*it2).first<<"= "<<(*it2).second<<endl;
		}
	}
}


/****************************************************************************
* Description	
* @param 	
* @return 	
* *************************************************************************/
 void IniFile::save() const
{
  save(m_filename,0);
}

/****************************************************************************
* Description	
* @param 	
* @return 	
* *************************************************************************/
 void IniFile::save(const std::string& filename, int append) const
{
  std::ofstream out(filename.c_str(), (append==0)?(ios::out|ios::trunc):(ios::out|ios::app));
  save(out);
}

/****************************************************************************
* Description: 		获取ini文件的section 的总数 	
* *************************************************************************/
 int IniFile::getSectionCount() const
{
  return int(m_dic.size());
}

/****************************************************************************
* Description	 获取所有的 [sections]， 便于之后的历遍. 
* @param 	
* @return 	
* @notice 	
****************************************************************************/
 int IniFile::getSections(vector<string> &out) const
{
		
	//typedef std::map<std::string, std::string> KeyValueMap;
	//typedef std::map<std::string, KeyValueMap> SectionMap;
	//
	//SectionMap m_dic;
	map<std::string, map<string, string> >::const_iterator it;

	//it= m_dic.begin();
	for(it = m_dic.begin(); it!= m_dic.end(); it++)
	{
		out.push_back((*it).first);		
	}
	return 1;
}



/****************************************************************************
* Description: 有没有这个字段 	
* @param 	
* @return 	
* *************************************************************************/
 bool IniFile::hasSection(const std::string& section) const
{
  return m_dic.find(section) != m_dic.end();
}


/****************************************************************************
* Description: 在section 下有没有这个值 	
* @param 	
* @return 	
* *************************************************************************/
 bool IniFile::hasKey(const std::string& section, const std::string& key) const
{
  return hasSection(section) && m_dic.find(section)->second.find(key) != m_dic.find(section)->second.end();
}


//typedef  typename IniFile::SectionMap  MAP;
//   IniFile::SectionMap   IniFile::getSectionMap() const
//{
// return m_dic;
//}

//typedef  typename (  IniFile::SectionMap ) MAP;
// IniFile::SectionMap test;
   int  IniFile::getSectionMap() const
{
  //return m_dic;
  return 1;
}


/****************************************************************************
* Description: 删除一个 section	
* @param 	
* @return 	
* *************************************************************************/
 void IniFile::removeSection(const std::string& section)
{
  m_dic.erase(section);
}



/****************************************************************************
* Description: 初始化文件，  并载入文件到内存  
* @param 	
* @return 	
* *************************************************************************/
 IniFile ::IniFile(const std::string& filename, bool createFile): m_filename(filename)
{
  load(m_filename, createFile);
}



/****************************************************************************
* Description: 
* @param :
* 		filename
* 		createFile: 0. 重新创建新的文件。
* 					1. append 的方式添加文件。 
* 					默认是创建新文件。 
* @return 	
* *************************************************************************/
 void IniFile::load(const std::string& filename, bool append)
{
	m_filename = filename;
	if (append) 
	{
		std::fstream(m_filename.c_str(), std::ios::app);
	}
	std::ifstream in(m_filename.c_str());
	load_istream(in);
}

/****************************************************************************
* Description: ini文件的载入，  
* @param 	
* @return 	
* @notice: 主要通过 string  的一些操作. 对文件进行解析的 
* *************************************************************************/
 void IniFile::load_istream(std::istream& in)
{
	if (!in)
	{
		cout<<"IniFile"<<m_filename<<"  file not exists\n"<<endl;
		exit(-1);
	}
	//throw IniFileError<char>("Could not load ini");

	std::string section;
	while (!in.eof()) 
	{
		std::string line;
		std::getline(in, line);
		if (in.bad())
		{
		 	//throw IniFileError<char>();
			cout<<"file stat error \n"<<endl;
		}

		if (line.length() == 0)
		  continue;

		if (line.at(0) == ';' || line.at(0) == '#')
		  continue;
		if (line.at(0) == '[') 
		{
			std::string::size_type pos = line.find_first_of("]");
			section = trim(line.substr(1, pos - 1));
			if (m_dic.find(section) == m_dic.end()) 
			{
				m_dic[section] = KeyValueMap();
			}
		} 
		else if (section.length() > 0) 
		{
			
			std::string::size_type pos = line.find_first_of("=");
			if (pos != std::string::npos) 
			{
				std::string key = trim(line.substr(0, pos));
				if (key.length() > 0) 
				{
					 if(std::string::npos != line.find_first_of(";"))
        			{   
            			std::string::size_type pos_end = line.find_first_of(";");
           				std::string value = trim(line.substr(pos+1, pos_end-pos-1));
						m_dic[section][key] = value;
        			}
					else
					{   
						std::string value = trim(line.substr(pos + 1));
						m_dic[section][key] = value;
					}
				}
			}
		}
	}
}



/****************************************************************************
* Description: 保存到文件， 
* @param out:  std::ostream 需要经过初始化。 	
* @return 	
* *************************************************************************/
 void IniFile::save(std::ostream& out) const
{
	if (!out)
	{
		throw printf("Could not save ini");
	}

	SectionMap::const_iterator iter;
	for (iter = m_dic.begin(); iter != m_dic.end(); ++iter) 
	{
		std::string sectionName = iter->first;
		const KeyValueMap& section = iter->second;

		out << "[" << sectionName << "]\n";

		KeyValueMap::const_iterator sIter;
		for (sIter = section.begin(); sIter != section.end(); sIter++) 
		{
		  out <<"\t"<< sIter->first << "=" << sIter->second << '\n';
		}
		out << '\n';
	}

	if (!out)
	printf("Error saving ini");
}



 IniFile::~IniFile()
{
}



#endif

// #ifdef WINDOWSCODE
// #else
// #endif
// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <iterator>  
// #include <map>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <string> 
// #include <vector> 
// //#include "../../trunk/Baselib/IniFile.hpp"
// //#include "../data_engine/IniFile.hpp"
// //#include "../data_engine/tools.cpp"
// //#include "../data_engine/log.cpp"
// using namespace std;

int file_write(string filename, string file_str)
{
	ofstream file(filename.c_str());
	file <<file_str;
	file.close();
	return 1;
}



char mbr[512];
TEST(endian , size)
{
	EXPECT_EQ( sizeof(mbr), 512 );
	EXPECT_EQ( sizeof(int), 4 );
	EXPECT_EQ( sizeof(long long ), 8 );
}

TEST(fat, info)
{
	EXPECT_EQ((1-1) ,0);
	
}

//单纯的解析文件, 看是否正确. 
TEST(gen_ini_reload, inifile)
{
	unlink("output.ini");
	string ini;
	ini+="[sect1]\n";
	ini+="	key=44\n";
	ini+="	key2=44\n";
	ini+="	key3=44\n";

	ini+="[sect2]\n";
	ini+="	key=44\n";
	ini+="	key2=44\n";
	ini+="	key3=44\n";

	ini+="[sect3]\n";
	ini+="	key=44\n";
	ini+="	key2=44\n";
	ini+="	key3=44\n";

	ini+="[sect4]\n";
	ini+="	key=44\n";
	ini+="	key2=44\n";
	ini+="	key3=44\n";

	file_write("output.ini", ini);

	struct stat st;
	EXPECT_EQ(stat("output.ini", &st)	 ,0);
	EXPECT_LT(stat("not_exists.conf", &st)	 ,0);
	EXPECT_GT(st.st_size, 0);
	EXPECT_EQ(st.st_size, ini.size());
	ASSERT_EQ(st.st_size, ini.size());
	


	IniFile IniFile("output.ini", 1);
	EXPECT_EQ(IniFile.get<int>("sect1", "key"), 44);
	EXPECT_EQ(IniFile.get<int>("sect2", "key"), 44);
	EXPECT_EQ(IniFile.get<int>("sect3", "key"), 44);

	EXPECT_EQ(IniFile.get<string>("sect1", "key"), "44");
	EXPECT_EQ(IniFile.get<string>("sect2", "key"), "44");
	EXPECT_EQ(IniFile.get<string>("sect3", "key"), "44");

	EXPECT_EQ(IniFile.get<int>("sect1", "key2"), 44);
	EXPECT_EQ(IniFile.get<int>("sect2", "key2"), 44);
	EXPECT_EQ(IniFile.get<int>("sect3", "key2"), 44);

	EXPECT_EQ(IniFile.get<int>("sect1", "key3"), 44);
	EXPECT_EQ(IniFile.get<int>("sect2", "key3"), 44);
	EXPECT_EQ(IniFile.get<int>("sect3", "key3"), 44);
}

//值set 之后 get 再进行比较 必然是一样的. 
TEST(set_in_memory , inifile)
{
	string file_str="[sect1]\n";
	file_str+="key=444\n";	
	file_write("output.ini", file_str);

	//IniFile  ini("petty.ini", 1);
	IniFile  ini("output.ini", 1);

    //fstream  file("
    //设定相同的值.
    for(int i=0; i<=1024*10; i++)
	{
		ini.set<int>("sect1", "key", 44);
		ini.set<short>("sect2", "key", 44);
		ini.set<float>("sect3", "key", 44);
		ini.set<string>("sect4", "key", "44");
		EXPECT_EQ(	ini.get<int>("sect1", "key") , 44);
		EXPECT_EQ(	ini.get<string>("sect4", "key") , "44");
		EXPECT_EQ(	ini.get<short>("sect2", "key") , 44);
	}



	char buf[256]={0};
    //设定不同的值.
	for(int i=0; i<=1024*10; i++)
	{
		ini.set<int>("sect1", "key", i);
		ini.set<short>("sect2", "key", i);
		ini.set<float>("sect3", "key", i);
		#ifdef WINDOWSCODE
		_snprintf(buf, sizeof(buf), "%d", i);	
		#else
		snprintf(buf, sizeof(buf), "%d", i);
		#endif
		ini.set<string>("sect4", "key", string(buf));

		EXPECT_EQ(	ini.get<int>("sect1", "key") , i);
		EXPECT_EQ(	ini.get<short>("sect2", "key") , i);
		EXPECT_FLOAT_EQ (	ini.get<float>("sect2", "key") , i);
		EXPECT_EQ(	ini.get<string>("sect4", "key") ,  string(buf) );
	}

	//ini.Dump();
	const string filename("test2.ini");	
	ini.save(filename, 0);
}

//配置文件很简单 , [sect_%d]
//					key_%d=value_%d
//					冒烟测试. 
TEST(inifile , large_loop)
{
	char buff[1024]={0};

	string sect;
	string key;
	string value;

	unlink("output.ini");
	for (int i=0; i<=1024; i++) //1024*1024 时间太长了 
	//for (int i=0; i<=1024*1024; i++) //1024*1024 时间太长了 
	{
		#ifdef WINDOWSCODE
		_snprintf(buff,sizeof(buff), "[sect_%d]\n  key_%d= value_%d\n", i, i, i);
		#else
		snprintf(buff,sizeof(buff), "[sect_%d]\n  key_%d= value_%d\n", i, i, i);
		#endif
		string file_str(buff);
		file_write("output.ini",  file_str);
		IniFile ini("output.ini");

		#ifdef WINDOWSCODE
		_snprintf(buff,sizeof(buff),  "sect_%d", i);
		#else
		snprintf(buff,sizeof(buff),  "sect_%d", i);
		#endif
		sect=string(buff);
		#ifdef WINDOWSCODE
		_snprintf(buff, sizeof(buff), "key_%d", i);
		#else
		snprintf(buff, sizeof(buff), "key_%d", i);	
		#endif
		key=string(buff);
		#ifdef WINDOWSCODE
		_snprintf(buff, sizeof(buff), "value_%d", i);
		#else
		snprintf(buff, sizeof(buff), "value_%d", i);	
		#endif
		value=string(buff);

		EXPECT_EQ(ini.get<string>(sect, key), value);
	}
}

//section 含有空格 也是正确的. 
TEST(inifile , section_have_space)
{

	string file_str="[	sect1	]\n";
	file_str+="key=444\n";	
	file_write("output.ini", file_str);
	
	IniFile  ini("output.ini", 1);
	EXPECT_EQ(ini.get<string>("sect1", "key"), "444");
	EXPECT_EQ(ini.get<int>("sect1", "key"), 	444);
	EXPECT_EQ(ini.get<short>("sect1", "key"), 	444);
}

//key value 含有空格 也是正确的. 
TEST(inifile , key_value_have_space)
{

	string file_str="[	sect1	]\n";
	file_str+="          key               =                   444\n";	
	file_write("output.ini", file_str);
	
	IniFile  ini("output.ini", 1);
	EXPECT_EQ(ini.get<string>("sect1", "key"), "444");
	EXPECT_EQ(ini.get<int>("sect1", "key"), 	444);
	EXPECT_EQ(ini.get<short>("sect1", "key"), 	444);

}

//中文也可以通过  
TEST(inifile , chinese_section)
{
//fixme yj windows 测试会有错误
	#ifdef WINDOWSCODE
	#else
	string file_str="[	中文	]\n";
	file_str+="          key               =                   444\n";	
	file_write("output.ini", file_str);
	
	IniFile  ini("output.ini", 1);
	EXPECT_EQ(ini.get<string>("中文", "key"), "444");
	EXPECT_EQ(ini.get<int>("中文", "key"), 	444);
	EXPECT_EQ(ini.get<short>("中文", "key"), 	444);
	#endif
}


//fixme 没有进行强力测试, 稍微测试了一下. 
TEST(inifile , get_sections)
{

	string file_str="[	sect1	]\n";
	file_str+="          key               =                   444\n";	
	file_write("output.ini", file_str);
	
	IniFile  ini("output.ini", 1);
	vector<string> sections;
	ini.getSections(sections);
	EXPECT_EQ(sections.size(),  1);
	EXPECT_EQ(sections[0],  "sect1");
	ini.Dump();
}


//key = null value 的值为空. 
TEST(inifile , values_is_null)
{
	string file_str="[	sect1	]\n";
	file_str+="          key               =    \t        \t\t    \t\t\t";	
	file_write("output.ini", file_str);
	
	IniFile  ini("output.ini", 1);
	EXPECT_EQ(ini.get<string>("sect1", "key"),  string(""));
	//fixme f8 平台上面有问题, 不是预期的0. 
	//G t = G();在f8上就能正常运行了
	EXPECT_EQ(ini.get<int>("sect1", "key"),  0);
	EXPECT_EQ(ini.get<float>("sect1", "key"),  0);
	EXPECT_EQ(ini.get<short>("sect1", "key"),  0);
	EXPECT_EQ(ini.get<long>("sect1", "key"),  0);
	EXPECT_EQ(ini.get<long long>("sect1", "key"),  0);
	EXPECT_EQ(ini.get<char>("sect1", "key"),  0);
	ini.Dump();
}

// 一个的第一个字母是; 或者 # 就是注释行. 
TEST(inifile , comment_)
{
	string file_str="[	sect1	]\n";
	file_str+="          key               = ;aaaa\n";	
	file_str+="key1 = a;a;";
	file_str+=";[sect2]\n";	
	file_str+="#[sect3]\n";	
	file_str+=";key2=bbbbb\n";	
	file_write("output.ini", file_str);

	IniFile  ini("output.ini", 1);
	//fixme 配置文件里面的注释的问题没有解决掉.
	//修改load-stream函数，问题解决了
	EXPECT_EQ(ini.get<string>("sect1", "key"),  string(""));
	EXPECT_EQ(ini.get<string>("sect1", "key1"),  string("a"));
	EXPECT_EQ(ini.hasSection("sect2"), 0);
	EXPECT_EQ(ini.hasSection("sect3"), 0);
	EXPECT_EQ(ini.hasSection("sect1"), 1);
}


TEST(inifile , comment_null_value_large_loop)
{
	for(int i=1; i<256; i++)
	{
		string file_str = string();
		string str_tmp  = string();
		file_str="[	sect1	]\n";
		file_str+="          key               =";
		str_tmp = str_tmp.assign(i,' ');
		str_tmp += str_tmp.insert(i,i,'\t');
		str_tmp+=";aaaa\n";
		file_str+=str_tmp;
		file_write("output.ini", file_str);
		
		IniFile  ini("output.ini", 1);
		EXPECT_EQ(ini.get<string>("sect1", "key"),  string(""));
	}
}

int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


