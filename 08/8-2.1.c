#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int glob = 6;

int 
main(int argc,char *argv[])
{
	int var;
	pid_t pid;
	
	var = 88;
	printf("before vfork\n");
	
	if((pid = fork()) < 0) /* 这里换成fork. */
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		glob++;
		var++;
		printf("i am child,pid = %d, ppid= %d, glob = %d, var = %d\n",getpid(),getppid(),glob,var);
		fclose(stdout); /* 这里关闭流的话，对于以后父进程执行printf没有影响。原因在于这里用的是fork，缓冲区被复制了两份，这里fclose()函数不会改变父进程中的缓冲区 */
		exit(0);
	}

	sleep(2);
	printf("i am parent, pid = %d, glob = %d, var = %d\n",getpid(),glob,var);
	exit(0);
}
