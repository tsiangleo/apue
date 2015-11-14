#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


int 
main(int argc,char *argv[])
{
	int var;
	pid_t pid;
	
	int fd;

	fd = open("tt",O_RDWR);
	if(fd == -1)
	{
		err_sys("open error");
	}

	if(lseek(fd,5,SEEK_CUR) == -1)
		err_sys("lseek error");

	printf("parent current seek:%ld\n",lseek(fd,0,SEEK_CUR));


	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0 )
	{
		char *buf = "iamchild";
		printf("child current seek:%ld\n",lseek(fd,0,SEEK_CUR));
		write(fd,buf,strlen(buf));
		printf("child current seek:%ld\n",lseek(fd,0,SEEK_CUR));
	}
	else
	{
		char b[1024];
		sleep(2); 
		printf("parent current seek:%ld\n",lseek(fd,0,SEEK_CUR));
		lseek(fd,0,SEEK_SET);
		read(fd,b,sizeof(b));
		printf("parent read:%s\n",b);

	}
	
	exit(0);
}
