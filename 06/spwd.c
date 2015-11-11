#include<shadow.h>
#include<stdio.h>

/*
 * must have root permission to execute.
 */

int
main(void)
{
	struct spwd *ptr;

	setspent();

	while((ptr = getspent()) != NULL)
	{
		printf("name:%s , passwd:%s , min:%d , max:%d , warn:%d , expire: %d\n",
				ptr->sp_namp,ptr->sp_pwdp,ptr->sp_min,ptr->sp_max,ptr->sp_warn,ptr->sp_expire);
	}
	endspent();
	return 0;
}
