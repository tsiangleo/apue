#include<stdio.h>
#include<stdlib.h>

int
main(int argc,char *argv[])
{
	int c;
	
	while((c = getc(stdin)) != EOF)
	{
		if(putc(c,stdout) == EOF)
		{
			perror("write error");
			exit(EXIT_FAILURE);
		}
	}
	if(ferror(stdin))
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}
	return 0;
}
