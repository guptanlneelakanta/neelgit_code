#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// ---------------- Global Synchronization Primitive ----------------
pthread_barrier_t init_barrier;

// ---------------- Function Declarations ----------------
void t1_init();
void t2_init();
void t1_process_loop();
void t2_process_loop();
void* t1(void *arg);
void* t2(void *arg);

// ---------------- main ----------------
int main()
{
    pthread_t th1, th2;

    // Initialize barrier for 2 threads
    if (pthread_barrier_init(&init_barrier, NULL, 2) != 0) {
        perror("Barrier init failed");
        return -1;
    }

    // Create threads
    pthread_create(&th1, NULL, t1, NULL);
    pthread_create(&th2, NULL, t2, NULL);

    // Wait for threads to finish (in this example they run infinite loops)
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    pthread_barrier_destroy(&init_barrier);

    return 0;
}

// ---------------- Thread 1 ----------------
void* t1(void *arg)
{
    t1_init();

    // Wait until both threads finish init
    pthread_barrier_wait(&init_barrier);

    t1_process_loop();

    return NULL;
}

// ---------------- Thread 2 ----------------
void* t2(void *arg)
{
    t2_init();

    // Wait until both threads finish init
    pthread_barrier_wait(&init_barrier);

    t2_process_loop();

    return NULL;
}

// ---------------- Init Functions ----------------
void t1_init()
{
    printf("T1: Initialization started\n");
    sleep(2);   // Simulate work
    printf("T1: Initialization complete\n");
}

void t2_init()
{
    printf("T2: Initialization started\n");
    sleep(4);   // Simulate longer work
    printf("T2: Initialization complete\n");
}

// ---------------- Processing Loops ----------------
void t1_process_loop()
{
    while (1) {
        printf("T1: Processing...\n");
        sleep(1);
    }
}

void t2_process_loop()
{
    while (1) {
        printf("T2: Processing...\n");
        sleep(1);
    }
}

