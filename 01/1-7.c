#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int
main(int argc,char *argv[])
{
	printf("uid = %d, gid = %d\n",getuid(),getgid());
	return 0;
}
