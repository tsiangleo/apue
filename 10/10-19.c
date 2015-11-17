#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void
sig_int(int signo)
{
	printf("caught SIGINT\n");
}

static void
sig_chld(int signo)
{
	printf("caught SIGCHLD\n");
}

int
main(void)
{
	if(signal(SIGINT,sig_int) == SIG_ERR)
	{	
		perror("signal(SIGINT) error");
		return -1;
	}
	if(signal(SIGCHLD,sig_chld) == SIG_ERR)
	{
		perror("signal(SIGCHLD) error");
		return -1;
	}

	if(my_system("/bin/ed") < 0)
	{
		perror("sytem() error");
		return -1;
	}
	
	exit(0);
}
