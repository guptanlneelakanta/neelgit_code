#include <pthread.h>
#include <stdio.h>

pthread_barrier_t init_barrier;

void t1_init()
{
    printf("t1 init done\n");
}

void t2_init()
{
    printf("t2 init done\n");
}

void t1_process_loop()
{
    while(1)
    {
        printf("t1 processing\n");
        break;
    }
}

void t2_process_loop()
{
    while(1)
    {
        printf("t2 processing\n");
        break;
    }
}

void* t1(void *arg)
{
    t1_init();

    // synchronization point
    pthread_barrier_wait(&init_barrier);

    t1_process_loop();
    return NULL;
}

void* t2(void *arg)
{
    t2_init();

    // synchronization point
    pthread_barrier_wait(&init_barrier);

    t2_process_loop();
    return NULL;
}

int main()
{
    pthread_t th1, th2;

    /* synchronization primitive initialization */
    pthread_barrier_init(&init_barrier, NULL, 2);

    pthread_create(&th1, NULL, t1, NULL);
    pthread_create(&th2, NULL, t2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    pthread_barrier_destroy(&init_barrier);

    return 0;
}