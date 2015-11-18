#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

static void sig_cld(int);

int
main()
{
	pid_t pid;

	if(signal(SIGCLD,sig_cld) == SIG_ERR)
		perror("signal error");
	if((pid = fork()) < 0)
	{	
		perror("fork error");
	}
	else if(pid == 0)
	{
		sleep(2);
		_exit(0);
	}
	pause();
	exit(0);
}

static void
sig_cld(int signo)
{
	pid_t pid;
	int status;

	printf("SIGCLD received\n");
	if(signal(SIGCLD,sig_cld) == SIG_ERR)
		perror("signal error");
	if((pid = wait(&status)) < 0)
		perror("wait error");
	printf("pid = %d\n",pid);
}
