#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int
main(int argc,char *argv[])
{
	printf("hello world from process ID %d\n",getpid());
	return 0;
}
