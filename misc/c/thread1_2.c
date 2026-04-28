#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

void t1_init()
{
    printf("\n t1 init");
}

void t2_init()
{
    printf("\n t2 init");
}

void t1_process()
{
    while(1)
    {
    printf("\n t1 process\n");
    sleep(1);
    //break;
    }
}

void t2_process()
{
    while(1)
    {
    printf("\n t2 process\n\n");
     sleep(1);
  //  break;
    }
}

pthread_barrier_t barrier;

void* thread1(void *arg)
{
t1_init();
    pthread_barrier_wait(&barrier);
    t1_process();
}

void* thread2(void *arg)
{
    t2_init();
    pthread_barrier_wait(&barrier);
    t2_process();
}



int main()
{
    pthread_t th1, th2;
    pthread_barrier_init(&barrier, NULL, 2);
    
    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    pthread_barrier_destroy(&barrier);
    
}
