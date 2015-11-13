#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/**
 * compiled with 8-12.c and 8-3.c
 *
 */
int main()
{
	int status;
	
	if((status == system("date")) < 0)
		err_sys("system() error");
	pr_exit(status);
	
	if((status = system("nosuchcommand")) < 0)
		err_sys("system() error");
	pr_exit(status);
	
	if((status = system("who; exit 44")) < 0)
		err_sys("system() error");
	pr_exit(status);
	
	exit(0);
}
