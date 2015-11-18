#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


static void 
sig_int(int signo)
{
	pr_mask("\nin sig_int: ");
}

int 
main(void)
{
	int i = 0;

	double j = 1;

	sigset_t newmask,oldmask,waitmask,pendmask;
	pr_mask("program start: ");
	
	if(signal(SIGINT,sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");

	/* just waste some time */
	while(i < 900000000)
	{
		i++;
		j += (j / 37.0) + i;
	}

	sigemptyset(&waitmask);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGINT);
	

	//进入临界区前，屏蔽SIGINT信号。
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0)
		err_sys("SIG_BLOCK error");
	
	pr_mask("pending before enter critical region: ");
	
	//查看进入临界区前有没有未决SIGINT信号
	if(sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if(sigismember(&pendmask,SIGINT))
		printf("before enter, found SIGINT pending\n");


	pr_mask("about to go critical region: ");
	i = 0;
	while(i < 10)
	{
		printf("%5d  ",i);
		pr_mask("in critical region: ");
		i++;
		sleep(1);
	}


	pr_mask("exit critical region and before reset: ");

	//查看退出临界区后有没有未决SIGINT信号
	if(sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if(sigismember(&pendmask,SIGINT))
		printf("after outside, found SIGINT pending\n");


/*	
	// 解除屏蔽SIGINT信号的不正确方案。
	if(sigprocmask(SIG_SETMASK,&waitmask,NULL) < 0)
		err_sys("SIG_SETMASK error");

	pr_mask("after reset: ");
	
	pause();

	printf("never goes here\n");

*/
	// 解除屏蔽SIGINT信号的正确方案。
	if(sigsuspend(&waitmask) != -1)
		err_sys("sigsuspend error");
	
	pr_mask("after return from sigsuspend: ");
	
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0)
		err_sys("SIG_SETMASK error");
	
	pr_mask("program exit: ");

}
