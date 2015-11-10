#include<stdio.h>
#include<stdlib.h>

int 
main(int argc,char* argv[])
{
	int c;
	
	while( (c = getc(stdin)) != EOF)
	{
		if(putc(c,stdout) == EOF)
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
