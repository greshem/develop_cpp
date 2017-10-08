#include <algorithm>
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
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>

#include <termios.h>
#include <sys/ioctl.h>

#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif





int get_terminal_width_height(const int fd, int *width, int *height)
{
        struct winsize win = { 0, 0, 0, 0 };
        int ret = ioctl(fd, TIOCGWINSZ, &win);

        if (height) {
                if (!win.ws_row) {
                        char *s = getenv("LINES");
                        if (s) win.ws_row = atoi(s);
                }
                if (win.ws_row <= 1 || win.ws_row >= 30000)
                        win.ws_row = 24;
                *height = (int) win.ws_row;
        }

        if (width) {
                if (!win.ws_col) {
                        char *s = getenv("COLUMNS");
                        if (s) win.ws_col = atoi(s);
                }
                if (win.ws_col <= 1 || win.ws_col >= 30000)
                        win.ws_col = 80;
                *width = (int) win.ws_col;
        }

        return ret;
}

using namespace std;
int main(int argc, char *argv[])
{
	int width;
	int height;
	int fd= get_terminal_width_height (0, 	 &width, &height);
	
	cout<< "width "<<width<< "height "<<height<<endl;
	return 0;
}
