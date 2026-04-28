#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <mutex>
using namespace std;

int cnt =0;

void *Mythreadfun(void *msg)
{
    char * mstr=(char *)msg;
    std::mutex m;
    cout<<"my thread fun task"<<endl;            
     pthread_exit(NULL);
}
#define NUM_THREADS 5

int main() {
    int return_code;
    void *status;
    int rc;
    pthread_t thread_id[NUM_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for(int i=0; i<NUM_THREADS; i++)
    {
        cout<<"main() creating thread = "<< i << endl;

        return_code = pthread_create(&thread_id[i], NULL, Mythreadfun, (void *)"test1");
        if(return_code)
        {
            cout<<"error in thread creation"<<endl;
            exit(-1);
        }    
    }

   
//sleep(1);
    pthread_attr_destroy(&attr);

    for(int i=0; i<NUM_THREADS; i++)
    {
        rc=pthread_join(thread_id[i], &status);
        if(rc)
        {
            cout<<"error in thread join"<<endl;
            exit(-1);
        }
      cout << "Main: completed thread id :" << i ;
      cout << "  exiting with status :" << status << endl;
    }

    printf("Main thread finished.\n");
    pthread_exit(NULL);
  
    return 0;
}



