#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<utime.h>

int 
main(int argc,char* argv[])
{
	int i,fd;
 
	struct stat statbuf;
	struct utimbuf timebuf;
 
	for(i = 1;i < argc;i++)
	{
		if(stat(argv[i],&statbuf) < 0)
		{
			printf("%s: stat error\n",argv[i]);
			continue;
		}
  
		if((fd = open(argv[i],O_RDWR|O_TRUNC)) < 0)
		{
			printf("%s: open error\n",argv[i]);
  			continue;
  		}
  		close(fd);
  
		timebuf.actime = statbuf.st_atime;
  		timebuf.modtime = statbuf.st_mtime;
  
		if(utime(argv[i],&timebuf) < 0)
		{
			printf("%s: utime error\n",argv[i]);
			continue;
		}
	}
	exit(0);
}

