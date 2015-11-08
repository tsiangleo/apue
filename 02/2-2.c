#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int
main(void)
{
	long val;

	val = sysconf(_SC_ARG_MAX);
	printf("%ld\n",val);
	val = pathconf("/",_PC_PATH_MAX);
	printf("%ld\n",val);
	return 0;
}
