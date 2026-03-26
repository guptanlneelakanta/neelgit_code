#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* myThread(void* arg) {
    int thread_num = *(int*)arg;

    printf("Thread %d is running\n", thread_num);
    printf("Thread %d ID: %lu\n", thread_num, pthread_self());

    //while(1)
    //{
    sleep(1);  // simulate some work
    //printf("Thread %d running \n", thread_num);
   // }
    printf("Thread %d finished\n", thread_num);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int n1 = 1, n2 = 2, n3 = 3;
    
    int *ptr = (int *)malloc(sizeof(int));
    *ptr=344;
    int arr1[5] = {2,3,4,5,6};
//free(ptr);
    // Create 3 threads
    pthread_create(&t1, NULL, myThread, &n1);
    pthread_create(&t2, NULL, myThread, &n2);
    pthread_create(&t3, NULL, myThread, &n3);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Main thread finished\n");

    return 0;
}

