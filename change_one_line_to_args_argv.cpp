//change one line to  char **argv 
char*  g_my_argv[1024];
int   g_my_argc=0;
void fill_argv(char *tmp_argv)
{
	char *foo = tmp_argv;
	int index = 0;
	char ret[100];
	bzero(ret, 100);
	while(*foo != '\0') {
		if(index == 1024)
		{
			logger("ERROR: only  support  1024  argc \n");
			break;
		}

		if(*foo == ' ') {
			if(g_my_argv[index] == NULL)
				g_my_argv[index] = (char *)malloc(sizeof(char) * strlen(ret) + 1);
			else {
				bzero(g_my_argv[index], strlen(g_my_argv[index]));
			}
			strncpy(g_my_argv[index], ret, strlen(ret));
			//strncat(g_my_argv[index], "\0", 1);
			g_my_argv[index][strlen(ret)]='\0';
			bzero(ret, 100);
			index++;
		} else {
			strncat(ret, foo, 1);
		}
		foo++;
		/*logger("foo is %c\n", *foo);*/
	}
	g_my_argv[index] = (char *)malloc(sizeof(char) * strlen(ret) + 1);
	strncpy(g_my_argv[index], ret, strlen(ret));
	//strncat(g_my_argv[index], "\0", 1);
	g_my_argv[index][strlen(ret)]='\0';
	g_my_argc=index;
}

int main()
{
	
}
