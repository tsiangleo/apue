#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#ifndef ARG_MAX
#define ARG_MAX 1024
#endif


static pthread_key_t key;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex = PTHREAD_MUTEX_INITIALIZER;

extern char **environ;

static void
thread_init(void)
{
	pthread_key_create(&key,free);
}


char *
getenv_r(const char *name)
{
	int i,len;
	char *envbuf;

	pthread_once(&init_done,thread_init);
	pthread_mutex_lock(&env_mutex);
	envbuf = (char *)pthread_getspecific(key);
	if(envbuf == NULL)
	{
		envbuf = malloc(ARG_MAX);
		if(envbuf == NULL)
		{
			pthread_mutex_unlock(&env_mutex);
			return NULL;
		}
		pthread_setspecific(key,envbuf);
	}
	len = strlen(name);
	for(i = 0;environ[i] != NULL;i++)
	{
		if((strncmp(name,environ[i],len) == 0) && (environ[i][len] == '='))
		{
			strcpy(envbuf,&environ[i][len + 1]);
			pthread_mutex_unlock(&env_mutex);
			return envbuf;
		}
	}

	pthread_mutex_unlock(&env_mutex);
	return NULL;
}
