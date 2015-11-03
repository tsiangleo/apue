#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFSIZE 4096

int
main(int argc,char *argv[])
{
	char buf[BUFFSIZE];
	int n;
	
	while((n = read(STDIN_FILENO,buf,sizeof(buf))) > 0)
	{
		if(write(STDOUT_FILENO,buf,n) != n)
		{
			perror("write error");
			exit(EXIT_FAILURE);
		}
	}
	if(n == -1)
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}
	return 0;
}
