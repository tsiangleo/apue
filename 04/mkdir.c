#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>

int
main(int argc,char *argv[])
{
	int s;

	if(argc != 2)
	{
		fprintf(stderr,"usage: %s <pathName>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	s = mkdir(argv[1],S_IRWXU);
	if(s < 0)
	{
		perror("mkdir");
	}
	else
	{
		printf("mkdir ok!\n");
	}
	return 0;
}
