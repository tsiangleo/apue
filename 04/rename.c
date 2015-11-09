#include<stdio.h>
#include<stdlib.h>

int
main(int argc,char * argv[])
{
	int s;

	if(argc != 3)
	{
		fprintf(stderr,"usage: %s <oldName> <newName>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	s = rename(argv[1],argv[2]);

	if(s < 0)
	{
	
		printf("%d\n",s);
		perror("rename");
	}
	else
		printf("ok\n");
	
	return 0;
}
