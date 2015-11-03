#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int
main(int argc,char *argv[])
{
	struct stat buf;

	if(argc != 2)
	{
		fprintf(stderr,"usage: %s <directory name>\n",argv[0]);
		exit(EXIT_FAILURE);
	}


	if( lstat(argv[1],&buf) == -1)
	{
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	printf("dev:%d\nino:%d\nnlink:%d\n",buf.st_dev,buf.st_ino,buf.st_nlink);

	return 0;
}
