#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 1024

void 
err_sys(char * buffer)
{
	perror(buffer);
	exit(EXIT_FAILURE);
}

int 
main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("usage: a.out <directory> <prefix>\n");
		exit(1);
 	}

	printf("%s\n",tempnam(argv[1][0] != ' ' ? argv[1] : NULL,argv[2][0] != ' '? argv[2] : NULL));
	exit(0);
}
