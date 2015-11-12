#include<stdio.h>
#include<stdlib.h>


/**
 *
 * this sample shows the difference between return and exit in a sub-function.
 *
 */
void f(int a)
{
	printf("in f()\n");
	if(a < 10)
	{
		return;
	//	exit(1);
	}
}

int
main()
{
	
	printf("in main()\n");
	f(2);
	printf("return from f()\n");
}
