#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int
main(int argc,char *argv[])
{
	char buf[1024];
	int s;

	if(argc != 2)
	{
		fprintf(stderr,"usage: %s <pathName>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	s = readlink(argv[1],buf,sizeof(buf));
	if(s < 0)
	{
		perror("readlink");
	}
	else
	{
		printf("readlink ok : ");
		buf[s] = 0;
		printf("%s\n",buf);
	}
	return 0;
}
