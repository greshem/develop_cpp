
// wxCHECK_VERSION
// bool wxCHECK_VERSION(major, minor, release)
// 
// This is a macro which evaluates to true if the current wxWidgets version is at least major.minor.release.
// 
// For example, to test if the program is compiled with wxWidgets 2.2 or higher, the following can be done:

#include <wx/string.h>
#include <wx/wx.h> 
int main()
{

    wxString s;
#if   wxCHECK_VERSION(2, 8, 12)
	printf("this is version 2.8.12 \n");
#elif wxCHECK_VERSION(2, 8, 11)
	printf("this is version 2.8.11 \n");
#elif wxCHECK_VERSION(2, 8, 10)
	printf("this is version 2.8.10 \n");
#elif wxCHECK_VERSION(2, 8, 9)
	printf("this is version 2.8.9 \n");
#elif wxCHECK_VERSION(2, 8, 8)
	printf("this is version 2.8.8 \n");
#elif wxCHECK_VERSION(2, 8,7)
	printf("this is version 2.8.7 \n");
#elif wxCHECK_VERSION(2, 8,6)
	printf("this is version 2.8.6 \n");
#else 
	printf("this is version other  \n");
#endif


}
