#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int 
main(int argc,char* argv[])
{
	if(argc != 2)
	{
		printf("usage:a.out <pathname>\n");
		exit(EXIT_FAILURE);
	}

	if(access(argv[1],R_OK) < 0)
	{	char buf[1024];
		snprintf(buf,sizeof(buf),"access error for %s",argv[1]);
		perror(buf);
	}
	else
		printf("read access OK\n");

	if(open(argv[1],O_RDONLY) < 0)
	{	char buf[1024];
		snprintf(buf,sizeof(buf),"open error for %s",argv[1]);
		perror(buf);
	}
	else
		printf("open for reading OK\n");

	exit(0);
}
