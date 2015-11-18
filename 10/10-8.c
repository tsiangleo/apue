#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<unistd.h>
#include<signal.h>

#define MAXLINE 1024

static jmp_buf env_alrm;

static void 
sig_alrm(int signo)
{
	longjmp(env_alrm,1);
}

int
main(void)
{
	int n;
	char line[MAXLINE];

	if(signal(SIGALRM,sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");

	if(setjmp(env_alrm) != 0)
		err_quit("read timeout");

	alarm(10);
	if((n = read(STDIN_FILENO,line,MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO,line,n);
	exit(0);
}

