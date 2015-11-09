#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int 
main(int argc,char* argv[])
{	
	struct stat statbuf;

	if(stat("foo",&statbuf) < 0)
	{
  		perror("stat error for foo");
  		exit(EXIT_FAILURE);
	}

	if(chmod("foo",(statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		perror("chmod error for foo");

 	if(chmod("bar",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) < 0 )
 		perror("chmod error for bar");
 
	if(creat("foo",RWRWRW) < 0)
		perror("create error for foo");
 
	exit(0);
}
