#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#define MAXLINE 1024

static void 
sig_alrm(int signo)
{

}

int
main(void)
{
	int n;
	char line[MAXLINE];

	if(signal(SIGALRM,sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");

	alarm(10);
	if((n = read(STDIN_FILENO,line,MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO,line,n);
	exit(0);
}

