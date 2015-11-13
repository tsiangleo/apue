#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/**
 * compiled with 8-12.c and 8-3.c
 *
 */
int main(int argc,char *argv[])
{
	int status;

	if(argc < 2)
	{
		err_quit("command-line argument required");
	}

	if((status == system(argv[1])) < 0)
		err_sys("system() error");
	pr_exit(status);
	
	exit(0);
}
