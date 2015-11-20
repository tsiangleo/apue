#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
/*
 this demo shows the effect of different mutex type. PTHREAD_MUTEX_RECURSIVE
*/
pthread_mutex_t mutex;

void
func1(void)
{
 pthread_mutex_lock(&mutex);
 printf("in func1, has got mutex\n");
 pthread_mutex_unlock(&mutex);
}

void *
thr_fn1(void *arg)
{
 pthread_mutex_lock(&mutex);
 printf("thread 1,has got mutex, start calling\n");
 func1();
 printf("thread 1 end calling\n");
 pthread_mutex_unlock(&mutex);
 return (void *)1;
}



int 
main(void)
{
 int err;
 pthread_t tid1;
 void *tret;
 
 pthread_mutexattr_t attr;

 pthread_mutexattr_init(&attr);
 pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
 //pthread_mutex_init(&mutex,NULL);
 pthread_mutex_init(&mutex,&attr);

 err = pthread_create(&tid1,NULL,thr_fn1,(void *)1);
 if(err != 0)
   err_quit("can't create thread1: %s\n",strerror(err));

 err = pthread_join(tid1,&tret);
 if(err != 0)
   err_quit("can't join with thread1: %s\n",strerror(err));
 printf("thread1 exit code %d\n",(int)tret);

 exit(0);
}
