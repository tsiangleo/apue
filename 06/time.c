#include<stdio.h>
#include<time.h>
#include<unistd.h>

int 
main()
{
	time_t t;
	char buf[1024];
	
	while(1)
	{
		t  = time(NULL); 
		strftime(buf,sizeof(buf),"%F %T",localtime(&t));
		printf("%s\n",buf); 
		sleep(1);
	}
	
	return 0;
}
