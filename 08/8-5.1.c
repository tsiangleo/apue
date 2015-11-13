#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

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
		sleep(2); /* 让父进程先退出，让第一个子进程变为孤儿进程 */
		
		if((pid = fork()) < 0)
			err_sys("fork error");
		else if(pid > 0)
		{
			printf("i am the first child, my pid = %d,the second child's pid = %d,my ppid = %d\n",getpid(),pid,getppid());
			exit(0);
		}

		sleep(2); /* 让第一个子进程先退出，使得第二个子进程变为孤儿进程 */
		printf("i am the second child, my pid = %d,my parent's pid = %d\n",getpid(),getppid());
		exit(0);
	}
	
	printf("i am original parent, my pid = %d,the first child's pid = %d,my ppid = %d\n",getpid(),pid,getppid());
	exit(0);
}
