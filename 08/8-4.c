#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

/*
 * this file must be compiled with 8-3.c and errors.c
 */

int 
main(int argc,char *argv[])
{
	int status;
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		exit(7);
	}
	
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		abort();
	}
	
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		status /= 0;
	}
	
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);

	exit(0);
}
