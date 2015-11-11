#include<pwd.h>
#include<stdio.h>

int
main(void)
{
	struct passwd *ptr;

	setpwent();

	while((ptr = getpwent()) != NULL)
	{
		printf("name:%s , passwd:%s , uid:%d , gid:%d , shell:%s , dir: %s\n",
				ptr->pw_name,ptr->pw_passwd,ptr->pw_uid,ptr->pw_gid,ptr->pw_shell,ptr->pw_dir);
	}

	endpwent();
	return 0;
}
