#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 1024

void pr_stdio(const char *,FILE *);

void 
err_sys(char * buffer)
{
	perror(buffer);
	exit(EXIT_FAILURE);
}

int 
main(int argc,char* argv[])
{
	FILE *fp;
	
	fputs("enter any character\n",stdout);
	
	if(getchar() == EOF)
		err_sys("getchar error");
	
	fputs("one line to standard error\n",stderr);
	
	pr_stdio("stdin",stdin);
	pr_stdio("stdout",stdout);
	pr_stdio("stderr",stderr);
 
	if((fp = fopen("/etc/passwd","r")) == NULL)
		err_sys("fopen error");
	if(getc(fp) == EOF)
		err_sys("getc error");
	pr_stdio("/etc/passwd",fp); 
	
	exit(0);
}

void pr_stdio(const char *name,FILE *fp)
{
	printf("stream = %s, ",name);
	
	if(fp->_IO_file_flags & _IO_UNBUFFERED)
		printf("unbuffered");
	else if(fp->_IO_file_flags & _IO_LINE_BUF)
		printf("line buffered");
	else
		printf("fully buffered");
	printf(", buffer size = %ld\n",fp->_IO_buf_end - fp->_IO_buf_base);
}

