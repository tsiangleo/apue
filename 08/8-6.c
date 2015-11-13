#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

static void 
charatatime(char *str)
{
	char *ptr;
	int c;
	
	setbuf(stdout,NULL);
	for(ptr = str; (c = *ptr++)!= 0;)
		putc(c,stdout);
}

int 
main(int argc,char *argv[])
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		charatatime("output from child\n");
	}
	else
	{
		charatatime("output from parent\n");
	}
	
	exit(0);
}
