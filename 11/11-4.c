#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void
cleanup(void *arg)
{
	printf("cleanup: %s\n",(char *)arg);
}

void *
thr_fn1(void *arg)
{
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup,"thread 1 fist handler");
 	pthread_cleanup_push(cleanup,"thread 1 second handler");
 	printf("thread 1 push complete\n");

	if(arg)
		return (void *)1;
 	pthread_cleanup_pop(0);
 	pthread_cleanup_pop(0);
 	return (void *)1;
}

void *
thr_fn2(void *arg)
{
	printf("thread 2 start\n");
 	pthread_cleanup_push(cleanup,"thread 2 fist handler");
 	pthread_cleanup_push(cleanup,"thread 2 second handler");
 	printf("thread 2 push complete\n");
 
	if(arg)
   		pthread_exit((void *)2);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_exit((void *)2);
}


int 
main(void)
{
	int err;
 	pthread_t tid1,tid2;
 	void *tret;

 	err = pthread_create(&tid1,NULL,thr_fn1,(void *)1);
 	if(err != 0)
   		err_quit("can't create thread1: %s\n",strerror(err));
 	
	err = pthread_create(&tid2,NULL,thr_fn2,(void *)1);
 	if(err != 0)
   		err_quit("can't create thread2: %s\n",strerror(err));
 	
	err = pthread_join(tid1,&tret);
 	if(err != 0)
   		err_quit("can't join with thread1: %s\n",strerror(err));
 	printf("thread1 exit code %d\n",(int)tret);
 	
	err = pthread_join(tid2,&tret);
 	if(err != 0)
   		err_quit("can't join with thread2: %s\n",strerror(err));
 	printf("thread2 exit code %d\n",(int)tret);
 	
	exit(0);
}
