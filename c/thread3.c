#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int data=0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * task1(void * n1)
{
    int num = *(int *)n1;
    printf("\n this is task1 = %d \n", num);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        data++;
        printf("\n this is task1 data = %d \n", data);
          
        pthread_mutex_unlock(&mutex);
      sleep(2);
    }
}

void * task2(void * n1)
{
    int num = *(int *)n1;
    printf("\n this is task2 = %d \n", num);
    while(1)
    {
       pthread_mutex_lock(&mutex);
        data++;
        printf("\n this is task2 data = %d \n", data);   
        
       pthread_mutex_unlock(&mutex);
        sleep(3); 
    }
}


int main()
{

    pthread_t th1, th2;
    int n1=5, n2=8;

    pthread_create(&th1, NULL, task1, &n1);
    pthread_create(&th2, NULL, task2, &n2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
}
