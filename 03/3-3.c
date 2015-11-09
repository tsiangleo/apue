#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFSIZE 4096

int
main(int argc,char *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while((n = read(STDIN_FILENO,buf,sizeof(buf))) > 0)
	{
		if(write(STDOUT_FILENO,buf,n) != n)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	if(n < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	return 0;
}
