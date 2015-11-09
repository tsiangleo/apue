#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int
main(int argc,char *argv[])
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
		printf("can't seek\n");
	else
		printf("seek OK\n");
	return 0;
}
