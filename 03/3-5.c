#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void 
set_fl(int fd,int flags)
{
	int val;

	if((val = fcntl(fd,F_GETFL,0)) < 0)
	{
		perror("fcntl F_GETFL error");
		exit(EXIT_FAILURE);
	}

	val |= flags;


	if(fcntl(fd,F_SETFL,val) < 0)
	{
		perror("fcntl F_SETFL error");
		exit(EXIT_FAILURE);
	}
}

