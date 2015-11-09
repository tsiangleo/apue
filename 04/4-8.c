#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int
main(int argc,char *argv[])
{
	int s;
	char buf[1024];

	if(argc != 2)
	{
		fprintf(stderr,"usage: %s <pathName>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	s = chdir(argv[1]);
	if(s < 0)
	{
		perror("chdir");
	}
	else
	{
		getcwd(buf,sizeof(buf));
		printf("chdir ok! current woring directory is: %s\n ",buf);
	}
	return 0;
}
