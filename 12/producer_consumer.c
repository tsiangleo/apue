#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

#define STACK_MAX_SIZE 10

#define PRO_PER_SLEEP 1
#define CON_PER_SLEEP 2

/*
 an example of producer and consumer.
*/

struct apple
{
 int id;
};

struct apple *stack[STACK_MAX_SIZE];
int top = 0;

pthread_mutex_t stk_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_notfull = PTHREAD_COND_INITIALIZER; //waiting the condition(not full) to be true
pthread_cond_t cond_notempty = PTHREAD_COND_INITIALIZER; 

void
push(struct apple * e)
{

 pthread_mutex_lock(&stk_lock);
 if(top == STACK_MAX_SIZE)
 {
  printf("stack full\n");
  pthread_cond_wait(&cond_notfull,&stk_lock);
 }
 stack[top++] = e;
 pthread_cond_signal(&cond_notempty);
 pthread_mutex_unlock(&stk_lock);
 
}

struct apple *
pop()
{
 struct apple *e;
 pthread_mutex_lock(&stk_lock);
 if(top == 0)
 {
   printf("stack empty\n");
   pthread_cond_wait(&cond_notempty,&stk_lock);
 }
 e = stack[--top];
 pthread_cond_signal(&cond_notfull);
 pthread_mutex_unlock(&stk_lock);
 return e;
}

void
traverse()
{
 pthread_mutex_lock(&stk_lock);
 int index = top;
 int length = 0;
 printf("the data are: ");
 while(--index >= 0){
  printf("%4d",stack[index]->id);
  length++;
 }
 printf("  ,total: %d \n",length);
 pthread_mutex_unlock(&stk_lock);
}

void *
producer(void *arg)
{
 int counter = 0;
 struct apple *e;
 
 while(1){
   sleep(PRO_PER_SLEEP);
   e = malloc(sizeof(struct apple));
   e->id = ++counter; 
   push(e);
   printf("producer push: %d\n",e->id);
 }

 return (void *)0;
}

void *
consumer(void *arg)
{
 struct apple *e;
  while(1){
    sleep(CON_PER_SLEEP);
    e = pop();
    printf("consumer pop: %d\n",e->id);
    free(e);
  }
}

int 
main(void)
{
 pthread_t pro_tid,con_tid;
 int err;
 
 err = pthread_create(&pro_tid,NULL,producer,NULL);
 if(err != 0)
 {
   printf("can't create producer thread: %s\n",strerror(err));
   exit(1);
 }

 err = pthread_create(&con_tid,NULL,consumer,NULL);
 if(err != 0)
 {
   printf("can't create consumer thread: %s\n",strerror(err));
   exit(1);
 }

 sleep(5);
 //pthread_join(pro_tid,NULL);
 //pthread_join(con_tid,NULL);
 while(1){
  sleep(5);
  printf("=========== main thread print the stack:===========\n");
  traverse();
  printf("===================================================\n");
 }
 exit(0);

}
