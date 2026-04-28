#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t barrier;
void t1_init()
{
    printf("\n t1_init is called");
}

void t2_init()
{
    printf("\n t2_init is called");
}

void * t1_process(void *arg)
{
    t1_init();
    while(1)
    {
        pthread_barrier_wait(&barrier);
        printf("\n t1_process is called \n" );
        break;
    }
}


void * t2_process(void *arg)
{
    t2_init();
    while(1)
    {
        pthread_barrier_wait(&barrier);
        printf("\n t2_process is called\n");
        break;
    }
}

int main()
{
    pthread_t t1, t2;
    pthread_barrier_init(&barrier, NULL, 2);

    pthread_create(&t1, NULL, t1_process, (void *) 1);
    pthread_create(&t2, NULL, t2_process, (void *) 2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_barrier_destroy(&barrier);
}
