#include<netdb.h>
#include<stdio.h>

int
main(void)
{
	struct hostent *ptr;
	char **p;

	sethostent(0);

	while((ptr = gethostent()) != NULL)
	{
		printf("name:%s , addrtype:%d , length:%d ,addr_list: ",
				ptr->h_name,ptr->h_addrtype,ptr->h_length);
		
		p = ptr->h_addr_list;

		while(*p)
		{
			printf("[%s] ",*p);
			p++;
		}
		printf("\n");
	}

	endhostent();
	return 0;
}
