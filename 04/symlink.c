#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/**
 * create s symbolic file.
 *
 * the fucntion is same as " ln -s <actualPath> <symPath>" in SHELL.
 *
 */
int
main(int argc,char *argv[])
{
	int s;
	if(argc != 3)
	{
		fprintf(stderr,"usage: %s <actualPath> <symPath>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	s = symlink(argv[1],argv[2]);
	if(s < 0)
	{
		perror("symlink");
	}
	else
		printf("symlink ok!\n");
	return 0;
}
