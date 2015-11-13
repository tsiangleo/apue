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
	
	if((pid = vfork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		glob++;
		var++;
	//	fclose(stdout); /* 关闭流的话，以后父进程执行printf的时候，没有输出：原因在于父子进程共享标准IO缓冲区。（比较8-2.1.c） */
	//	fflush(stdout); /* 子进程执行到这儿的时候，缓冲区中的内容被冲洗（此时缓存区中并没有内容）。所以以后父进程执行printf的时候，照样输出内容。  */
		_exit(0);
	}

	printf("pid = %d, glob = %d, var = %d\n",getpid(),glob,var);
	exit(0);
}
