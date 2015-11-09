#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(int argc,char *argv[])
{
	int fd;

	if((fd = creat("file.hole",FILE_MODE)) < 0)
	{
		perror("creat");
		exit(EXIT_FAILURE);
	}

	if(write(fd,buf1,10) != 10)
	{
		perror("buf1 write error");
		exit(EXIT_FAILURE);
	}

	if(lseek(fd,16384,SEEK_SET) == -1)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}

	if(write(fd,buf2,10) != 10)
	{
		perror("buf2 write error");
		exit(EXIT_FAILURE);
	}
	return 0;
}
