#include <string>
#include <map>
#include <iostream>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>


//20100625 qzj mdf . 
using namespace std;
namespace inifile {

class IniFile {
public:
  typedef std::map<std::string, std::string> KeyValueMap;
  typedef std::map<std::string, KeyValueMap> SectionMap;

  IniFile()
  {}

  IniFile(const std::string& filename, bool createFile = true);

  ~IniFile();

  void save() const;

  void save(const std::string& filename) const;

  void load(const std::string& filename, bool createFile = true);

  int getSectionCount() const;

  template <class T>
  T get(const std::string& section, const std::string& key) const;

  template <class T>
  T get(const std::string& section, const std::string& key, T defaultValue) const;

  /*
  template <>
  std::string get(const std::string& section, const std::string& key, std::string defaultValue);
  */

  template < class T >
  std::list<std::string> get(const std::string& section, const std::string& key, std::list<std::string> defaultValue) const;

  template <class T>
  void set(const std::string& section, const std::string& key, T value);

  template < class T >
  void set(const std::string& section, const std::string& key, std::list<std::string> value);

  bool hasSection(const std::string& section) const;

  bool hasKey(const std::string& section, const std::string& key) const;

  const SectionMap& getMap() const;

  void removeSection(const std::string& section);

  	void save(std::ostream& out) const;
	void Dump();
protected:

  void load(std::istream& in);


  SectionMap m_dic;
  std::string m_filename;
};


class IniFileError: public std::exception
{
public:
  IniFileError()
    : m_msg("Unspecified IniFile Error")
  {}

  IniFileError(const char* msg)
    : m_msg(msg)
  {}

  const char* what() const throw()
  {
    return m_msg;
  }

private:
  const char* m_msg;
};




template <class T>
T
IniFile::get(const std::string& section, const std::string& key, T defaultValue) const
{
  if (!hasKey(section, key)) {
    return defaultValue;
  } else {
    std::istringstream stream(m_dic.find(section)->second.find(key)->second);
    T t;
    stream >> t;
    if (!stream)
      throw IniFileError("Invalid value when getting key");
    return t;
  }
}



template <class T>
T
IniFile::get(const std::string& section, const std::string& key) const
{
  return this->get(section, key, T());
}

//把所有的keyvalue 都dump 出来. 
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
			cout<<(*it2).first<<"= "<<(*it2).second<<endl;
		}
	
	}
}
template <>
std::list<std::string>
IniFile::get(const std::string& section, const std::string& key, std::list<std::string> defaultValue) const
{
  if (!hasSection(section))
    return defaultValue;
  std::list<std::string> vec;
  KeyValueMap::const_iterator iter;
  const KeyValueMap& sec = m_dic.find(section)->second;
  for (iter = sec.begin(); iter != sec.end(); ++iter) {
    std::string skey = iter->first;
    if (skey.find(key + "_") == 0) {
      int i;
      std::istringstream stream(skey.substr(key.length() + 1));
      stream >> i;
      if (!stream) {
        stream.clear();
      } else {
        vec.push_back(iter->second);
      }
    }
  }
  return vec;
}



template <class T>
void
IniFile::set(const std::string& section, const std::string& key, T value)
{
  std::ostringstream stream;
  stream << value;
  if (!stream)
    throw IniFileError("Invalid value when setting key");
  if (m_dic.find(section) == m_dic.end()) {
    m_dic[section] = KeyValueMap();
  }
  m_dic[section][key] = stream.str();
}



template <>
void
IniFile::set(const std::string& section, const std::string& key, std::list<std::string> value)
{
  if (m_dic.find(section) == m_dic.end()) {
    m_dic[section] = KeyValueMap();
  }
  std::list<std::string>::iterator iter;
  int i = 0;
  for (iter = value.begin(); iter != value.end(); ++iter, ++i) {
    std::ostringstream stream;
    stream << i;
    set(section, key + "_" + stream.str(), *iter);
  }
}


};





namespace inifile {



IniFile::IniFile(const std::string& filename, bool createFile)
: m_filename(filename)
{
  load(m_filename, createFile);
}



IniFile::~IniFile()
{

}



void
IniFile::save() const
{
  save(m_filename);
}



void
IniFile::save(const std::string& filename) const
{
  std::ofstream out(filename.c_str());
  save(out);
}



void
IniFile::load(const std::string& filename, bool createFile)
{
  m_filename = filename;
  if (createFile) {
    std::fstream(m_filename.c_str(), std::ios::app);
  }
  std::ifstream in(m_filename.c_str());
  load(in);
}



int
IniFile::getSectionCount() const
{
  return int(m_dic.size());
}



bool
IniFile::hasSection(const std::string& section) const
{
  return m_dic.find(section) != m_dic.end();
}



bool
IniFile::hasKey(const std::string& section, const std::string& key) const
{
  return hasSection(section) && m_dic.find(section)->second.find(key) != m_dic.find(section)->second.end();
}



const IniFile::SectionMap&
IniFile::getMap() const
{
  return m_dic;
}



void
IniFile::removeSection(const std::string& section)
{
  m_dic.erase(section);
}



void
IniFile::load(std::istream& in)
{
  if (!in)
    throw IniFileError("Could not load ini");

  std::string section;

  while (!in.eof()) {
    std::string line;
    std::getline(in, line);

    if (in.bad())
      throw IniFileError();

    if (line.length() == 0)
      continue;

    if (line.at(0) == ';' || line.at(0) == '#')
      continue;

    if (line.at(0) == '[') {
      std::string::size_type pos = line.find_first_of("]");
      section = line.substr(1, pos - 1);
      if (m_dic.find(section) == m_dic.end()) {
        m_dic[section] = KeyValueMap();
      }
    } else if (section.length() > 0) {
      std::string::size_type pos = line.find_first_of("=");
      if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        if (key.length() > 0) {
          std::string value = line.substr(pos + 1);
          m_dic[section][key] = value;
        }
      }
    }
  }
}



void
IniFile::save(std::ostream& out) const
{
  if (!out)
    throw IniFileError("Could not save ini");

  SectionMap::const_iterator iter;
  for (iter = m_dic.begin(); iter != m_dic.end(); ++iter) {
    std::string sectionName = iter->first;
    const KeyValueMap& section = iter->second;

    out << "[" << sectionName << "]\n";

    KeyValueMap::const_iterator sIter;
    for (sIter = section.begin(); sIter != section.end(); sIter++) {
      out << sIter->first << "=" << sIter->second << '\n';
    }
    out << '\n';
  }

  if (!out)
    throw IniFileError("Error saving ini");
}


};


int main(int argc, char *argv[])
{
	if( !argv[1])
	{
		cout<<argv[0]<<" file.ini"<<endl;
		return 0;
	}
    inifile::IniFile  ini(string(argv[1]), false);

    //fstream  file("
    ini.set<int>("aaaa", "bbb", 33);
//    ini.save(cout);
	ini.Dump();
//    getchar();
    return 0;
}
