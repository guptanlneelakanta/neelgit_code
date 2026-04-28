#include<iostream>
#include<cstdlib>
#include<cstring>
#include<pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
    int threadid;
    char *msg;
};

void *printhello(void *threadarg)
{
    struct thread_data *my_data;

    my_data = (struct thread_data *) threadarg;

    cout<<"\n thread_id = "<<my_data->threadid<<endl;
    cout<<"\n thread msg = "<<my_data->msg<<endl;
    pthread_exit(NULL);
}


int main()
{
    pthread_t threads[NUM_THREADS];
    struct thread_data tds[NUM_THREADS];
    int rc;
    int i;
    for(i=0; i<NUM_THREADS; i++)
    {
        cout<<"\n main() creating thread "<<i <<endl;
        tds[i].threadid=i;
        tds[i].msg = "this is thread message";
        rc = pthread_create(&threads[i], NULL,  printhello, (void *)&tds[i]);
        if(rc)
        {
            cout<<"\n unable to createthread"<<rc<<endl;
            exit(-1);
        }
    }
      pthread_exit(NULL);
}