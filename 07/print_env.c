#include<stdio.h>
#include<stdlib.h>

int 
main(int argc,char* argv[])
{
	extern char **environ;
	
	char **p = environ;
	
	while(*p)
	{
		printf("%s\n",*p);
		p++;
	}

	return 0;
}
