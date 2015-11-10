#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 1024

int 
main(int argc,char* argv[])
{
	char buf[MAXLINE];

	while(fgets(buf,MAXLINE,stdin) != NULL)
	{
		if(fputs(buf,stdout) == EOF)
		{
			fprintf(stderr,"output error");   
			exit(EXIT_FAILURE);
		}
	}
	
	if(ferror(stdin))
	{
		fprintf(stderr,"input error");  
		exit(EXIT_FAILURE);
	}

	exit(0);
}
