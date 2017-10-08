#include <list>
#include <stdlib.h>
#include <fstream> 
#include <iostream> 
#include <Baselib.hpp>

#include <boost/regex.hpp>


unsigned tokenise(std::list<std::string>& l, std::string& s)
{
   return boost::regex_split(std::back_inserter(l), s);
}

template< class T> int  dump(T &in)
{
	//typedef T::iterator it;
	typedef typename   T::iterator IT;
	IT it;
	
	for(it=in.begin(); it!= in.end(); it++)
	{
		cout<<*it<<endl;
	}
	return 1;
}


#include <iostream>
using namespace std;


#if defined(BOOST_MSVC) || (defined(__BORLANDC__) && (__BORLANDC__ == 0x550))
//
// problem with std::getline under MSVC6sp3
istream& getline(istream& is, std::string& s)
{
   s.erase();
   char c = is.get();
   while(c != '\n')
   {
      s.append(1, c);
      c = is.get();
   }
   return is;
}
#endif


using namespace std;
int main(int argc, const char*[])
{
	string s;
	list<string> l;
	vector<string> arr;
	fstream file("./passwd.txt", ios::in);
	while(getline(file, s, '\n'))
	{
		cout<<"###############################################################################"<<endl;
		arr.erase(arr.begin(), arr.end());
		cout<<s<<endl;;
		boost::regex_split(std::back_inserter(arr), s);
		
		//dump<vector<string>  >(arr);

		
	}
//    do{
//       if(argc == 1)
//       {
//          cout << "Enter text to split (or \"quit\" to exit): ";
//          getline(cin, s);
//          if(s == "quit") break;
//       }
//       else
//          s = "This is a string of tokens";
//       unsigned result = tokenise(l, s);
//       cout << result << " tokens found" << endl;
//       cout << "The remaining text is: \"" << s << "\"" << endl;
//       while(l.size())
//       {
//          s = *(l.begin());
//          l.pop_front();
//          cout << s << endl;
//       }
//    }while(argc == 1);
   return 0;
}

