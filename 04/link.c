#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int
main(int argc,char * argv[])
{
	int s;

	if(argc != 3)
	{
		fprintf(stderr,"usage: %s <oldPath> <newPath>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	s = link(argv[1],argv[2]);

	if(s < 0)
	{
	
		printf("%d\n",s);
		perror("link");
	}
	else
		printf("ok\n");
	
	return 0;
}
