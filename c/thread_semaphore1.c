#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>


sem_t sem_binary;

int data=0;
void * task1(void * n1)
{
    int num = *(int *)n1;
    printf("\n this is task1 = %d \n", num);
    while(1)
    {
    sem_wait(&sem_binary);
    data++;
    printf("\n this is task1 data1= %d \n", data);
    
    sleep(3.3);    
    sem_post(&sem_binary);
    }
}

void * task2(void * n1)
{
    int num = *(int *)n1;
    printf("\n this is task2 = %d \n", num);
    
    while(1)
    {
    sem_wait(&sem_binary);
        data++;
    printf("\n this is task2 data1= %d \n", data);

    sleep(1.5);
    sem_post(&sem_binary);
    }
}


int main()
{

    pthread_t th1, th2;
    int n1=5, n2=8;

    // Initialize semaphore to 1 (Binary semaphore)
    sem_init(&sem_binary, 0, 1);
    //sem_post(&sem_binary);

    pthread_create(&th1, NULL, task1, &n1);
    pthread_create(&th2, NULL, task2, &n2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
     sem_destroy(&sem_binary);
}