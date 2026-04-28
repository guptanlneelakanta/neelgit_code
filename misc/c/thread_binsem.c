#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t bin_sem;
void thread1_init()
{
    printf("\n thread1 initialize");
}

void thread2_init()
{
    printf("\n thread2 initialize");
}

void * thread1(void *arg)
{
    while(1)
    {
        sem_wait(&bin_sem);
        printf("\n thread1 process");
        sem_post(&bin_sem);
       sleep(1);
    }
}


void * thread2(void *arg)
{
    while(1)
    {

        sem_wait(&bin_sem);
        printf("\n thread2 process");
        sem_post(&bin_sem);
        sleep(1);
    }
}


int main()
{
    pthread_t th1, th2;
    
    sem_init(&bin_sem, 0,1);

    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    //int pthread_mutex_destroy (pthread_mutex_t *__mutex)
    sem_destroy(&bin_sem);
}