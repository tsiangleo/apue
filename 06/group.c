#include<grp.h>
#include<stdio.h>

int
main(void)
{
	struct group *ptr;

	setgrent();

	while((ptr = getgrent()) != NULL)
	{
		printf("name:%s , passwd:%s , gid:%d\n",
				ptr->gr_name,ptr->gr_passwd,ptr->gr_gid);
	}

	endgrent();
	return 0;
}
