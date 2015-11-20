#include<stdio.h>
#include<unistd.h>
int
main()
{
	long keys = sysconf(_SC_THREAD_KEYS_MAX);
	long stack = sysconf(_SC_THREAD_STACK_MIN);
	long threads = sysconf(_SC_THREAD_THREADS_MAX);

	printf("_SC_THREAD_KEYS_MAX = %ld\n",keys);
	printf("_SC_THREAD_STACK_MIN = %ld\n",stack);
	printf("_SC_THREAD_THREADS_MAX = %ld\n",threads);
	
	return 0;
}
