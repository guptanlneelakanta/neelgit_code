#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
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
        pthread_mutex_lock(&lock);
        printf("\n thread1 process");
        pthread_mutex_unlock(&lock);
        break;
    }
}


void * thread2(void *arg)
{
    while(1)
    {

        pthread_mutex_lock(&lock);
        printf("\n thread2 process");
        pthread_mutex_unlock(&lock);
        break;
    }
}


int main()
{
    pthread_t th1, th2;
    
    pthread_mutex_init(&lock, NULL);

    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    //int pthread_mutex_destroy (pthread_mutex_t *__mutex)
    pthread_mutex_destroy(&lock);
}