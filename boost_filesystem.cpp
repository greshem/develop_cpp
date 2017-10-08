#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream> 
using namespace std;
namespace fs = boost::filesystem;
int PrintAllFile(fs::path & full_path);

int main( int argc, char * argv[] )
{
	fs::path full_path( " D:\\ " ,fs::native);
	PrintAllFile(full_path);
} 

int PrintAllFile(fs::path & full_path)
{
	if (fs::exists(full_path))
	{
		fs::directory_iterator item_begin(full_path);
		fs::directory_iterator item_end;
		for ( ;item_begin   != item_end; item_begin ++ )
		{
			if (fs::is_directory( * item_begin))
			{
				//cout << item_begin->native_file_string() << " \t[dir] " << endl;
				PrintAllFile( *item_begin);
			} 
			else 
			{
				//cout << item_begin -> native_file_string() << endl;
			} 
		} 
	} 
}
