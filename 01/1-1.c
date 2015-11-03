#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int
main(int argc,char *argv[])
{
	struct dirent *ent;
	DIR *dir;

	if(argc != 2)
	{
		fprintf(stderr,"usage: %s <directory name>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	if((dir = opendir(argv[1])) == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	while((ent = readdir(dir)) != NULL)
	{
		printf("%s\n",ent->d_name);
	}

 	closedir(dir);
	return 0;
}
