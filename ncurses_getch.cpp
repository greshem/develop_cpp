#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <dirent.h>
//2010_09_02 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{

	void *p;
	p=initscr();
	if(p==NULL)
	{
		printf(" initialize screen fail curses");
		exit(-1);
	}
	keypad(stdscr, TRUE);
	scrollok(stdscr,  FALSE);
	cbreak();
	noecho();
	refresh();


	//int key;
	// while((key=getch()) )
	// {
	// 	cout<<key<<endl;
	// }
	return 0;
}
