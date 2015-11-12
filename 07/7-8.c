#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>

#define FMT "%10ld  "

#define doit(name) pr_limits(#name,name)

static void
pr_limits(char *name,int res)
{
	struct rlimit limit;

	if(getrlimit(res,&limit) < 0)
	{
		fprintf(stderr,"getrlimit error for %s\n",name);
		return;
	}

	printf("%-14s  ",name);
	if(limit.rlim_cur == RLIM_INFINITY)
		printf("(infinite)  ");
	else
		printf(FMT,limit.rlim_cur);
	
	if(limit.rlim_max == RLIM_INFINITY)
		printf("(infinite)");
	else
		printf(FMT,limit.rlim_max);

	putchar((int)'\n');
}

int main()
{
	doit(RLIMIT_AS);
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_FSIZE);
	doit(RLIMIT_LOCKS);
	doit(RLIMIT_MEMLOCK);
	doit(RLIMIT_NOFILE);
	doit(RLIMIT_NPROC);
	doit(RLIMIT_RSS);
	//doit(RLIMIT_SBSIZE);
	doit(RLIMIT_STACK);
	//doit(RLIMIT_VMEM);
	return 0;
}
