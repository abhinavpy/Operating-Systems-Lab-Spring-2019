#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* PrintHello(void* data)
{
    pthread_t tid = (pthread_t) data;   //data received by thread
    pthread_join(tid, NULL);            //wait for thread id
    printf("Hello from new thread %u - got %u\n", pthread_self(), data);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) 
{
    int rc;                 //return value
    pthread_t thread_id;    //thread's id (just an integer)
    int tid;

    tid = pthread_self();

    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)tid);
    if(rc) 
    {
        printf("\nError: return code from pthread_create is %d\n", rc);
        exit(1);
    }
    sleep(1);
    printf("Created a new thread (%u) ... \n", thread_id);
    pthread_exit(NULL);
    return 0;
}