#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#define MAXLINE 1024

static void sig_int(int signo)
{
	printf("interrupt\n%% ");
	fflush(stdout);
}

int
main(int argc,char *argv[])
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if(signal(SIGINT,sig_int) == SIG_ERR)
	{
		perror("signal error");
		exit(EXIT_FAILURE);
	}

	printf("%% ");
	while(fgets(buf,sizeof(buf),stdin) != NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;	/* replace newline with null */
		
		if((pid = fork()) < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		} 
		else if(pid == 0)
		{
			execlp(buf,buf,(char *)0);
			fprintf(stderr,"couldn't execute: %s\n",buf);
			exit(127);
		}

		/* parent */
		if((pid = waitpid(pid,&status,0)) < 0)
		{
			perror("waitpid error");
			exit(EXIT_FAILURE);
		}

		if(ferror(stdin))
		{
			perror("read error");
			exit(EXIT_FAILURE);
		}
		printf("%% ");
	}
	return 0;
}
