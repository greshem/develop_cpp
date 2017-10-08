#include <stdlib.h>
#include <list>

//########################################################################
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
#include <stringprep.h>
typedef struct {
        int age;
        int time;
        char name[32];
        } info;
using namespace std;
main()
{
      list<info> users;
      list<info> *ptr;
      info temp;
      
      temp.age=100;
      temp.time=1000;
      strcpy(temp.name, "qiznzhongjei");
      users.push_front(temp);
      
      
      temp.age=111;
      temp.time=111;
      strcpy(temp.name, "qianlong");
      users.push_front(temp);
      
      ptr=&users;
      
      list<info>::iterator it;
      
      for(it=(ptr->begin()); it!=(ptr->end()); it++)
      {
          printf("%d %d %s\n", (*it).age, (*it).time, (*it).name);
      }
      //getchar();
      return 0;
}
