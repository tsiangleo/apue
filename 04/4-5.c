#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	if(open("tempfile",O_RDWR) < 0)
	{
		perror("open error");
  		exit(EXIT_FAILURE);
	}
	if(unlink("tempfile") < 0)
	{
		perror("unlink error");
  		exit(EXIT_FAILURE);
	}

	printf("file unlinked\n");
 
	sleep(15);
 
	printf("done\n");
 
	exit(0);
}
