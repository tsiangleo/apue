#include<stdio.h>

int
main()
{
	FILE *fp;
	long p;
	char buf[10];

	fp = fopen("tt","r+");
	if(fp == NULL)
	{
		fprintf(stderr,"open error!\n");
	}

	p = ftell(fp);
	if(p == -1)
	{
		fprintf(stderr,"ftell error!\n");
	}
	printf("%ld\n",p);
	
	fread(buf,sizeof(char),7,fp);
	printf("%s\n",buf);
	
	if(fseek(fp,2,SEEK_SET) != 0)
	{
		fprintf(stderr,"fseek error!\n");
	}

	if((p = ftell(fp)) == -1)
		fprintf(stderr,"ftell error!\n");
	
	printf("%ld\n",p);

	fread(buf,sizeof(char),7,fp);
	printf("%s\n",buf);
}
