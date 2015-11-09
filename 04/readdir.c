#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

int
main(int argc,char *argv[])
{
	struct dirent *d;
	DIR *dirp;
	char buf[1024];
	int s;

	char pathname[4096];

	if(argc != 2)
	{
		fprintf(stderr,"usage: %s <pathName>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	strcpy(pathname,argv[1]);

	dirp = opendir(pathname);
	if(dirp == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	while((d = readdir(dirp)) != NULL)
	{
		printf("%s\n",d->d_name);
	}

	return 0;
}
