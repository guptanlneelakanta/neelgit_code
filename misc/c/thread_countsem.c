#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t cnt_sem;
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
    int num= (int *) arg;
    while(1)
    {
        sem_wait(&cnt_sem);
        printf("\n thread1 process %d", num);
        sleep(1);
        sem_post(&cnt_sem);
       
    }
    return NULL;
}



int main()
{
    pthread_t th1, th2, th3, th4;
    
    sem_init(&cnt_sem, 0,3);

    
    pthread_create(&th1, NULL, thread1, (void *)1);
    pthread_create(&th2, NULL, thread1, (void *)2);
    pthread_create(&th3, NULL, thread1, (void *)3);
    pthread_create(&th4, NULL, thread1, (void *)4);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    pthread_join(th4, NULL);

    //int pthread_mutex_destroy (pthread_mutex_t *__mutex)
    sem_destroy(&cnt_sem);
}

