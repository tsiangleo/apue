#include<stdio.h>
#include<stdlib.h>


/**
 * this sample shows the difference between setenv() and putenv(),and getenv().
 */

int
main()
{
	char *val;

	val = getenv("USER");
	printf("USER = %s\n",val);
	*val = 'a';
	printf("USER = %s\n",getenv("USER"));

	char nval[10] = "bar";

	setenv("USER",nval,1);
	printf("USER = %s\n",getenv("USER"));

	nval[2] = 'b';
	printf("USER = %s\n",getenv("USER"));

	char p[10] = "USER=foo";
	putenv(p);
	printf("USER = %s\n",getenv("USER"));

	p[5]='h';
	printf("USER = %s\n",getenv("USER"));
	return 0;
}
