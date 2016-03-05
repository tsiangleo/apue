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

	printf("blocks:%d\ninode-number:%d\nhard-links:%d\nbytes:%d\n",(int)buf.st_blocks,(int)buf.st_ino,(int)buf.st_nlink,(int)buf.st_size);

	return 0;
}
