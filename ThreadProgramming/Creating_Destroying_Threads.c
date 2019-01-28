/*pthread_create() gets 4 arguments the first is a pointer to thread 
1. In main() we declare a variable called thread_id, which is of type pthread_t. This is basically an integer used to identify the thread in the system. After declaring thread_id, we call the pthread_create function to create a real, living thread. 
2. pthread_create() gets 4 arguments The first argument is a pointer to thread_id, used by pthread_create() to supply the program with the thread's identifier. The second argument is used to set some attributes for the new thread. In our case we supplied a NULL pointer to tell pthread_create() to use the default values. Notice that PrintHello() accepts a void * as an argument and also returns a void * as a return value. This shows us that it is possible to use a void * to pass an arbitrary piece of data to our new thread, and that our new thread can return an arbitrary piece of data when it finishes. How do we pass our thread an arbitrary argument? Easy. We use the fourth argument to the pthread_create() call. If we do not want to pass any data to the new thread, we set the fourth argument to NULL. pthread_create() returns zero on success and a non-zero value on failure.
3. After pthread_create() successfully returns, the program will consist of two threads. This is because the main program is also a thread and it executes the code in the main() function in parallel to the thread it creates. Think of it this way: if you write a program that does not use POSIX threads at all, the program will be single-threaded (this single thread is called the "main" thread).
4. The call to pthread_exit causes the current thread to exit and free any thread-specific resources it is taking.

In order to compile a multi-threaded program using gcc, we need to link it with the pthreads library. Assuming you have this library already installed on your system, here is how to compile our first program: 

gcc hello.c -o hello -lpthread
*/


#include<stdio.h>   
#include<pthread.h> /*pthread functions and data structures*/

/* function to be executed by the new thread */
void* PrintHello(void* data)
{
    int my_data = (int)data;    //Data received by thread
    
    pthread_detach(pthread_self());
    printf("Hello from new thread - got %d\n", my_data);
    pthread_exit(NULL);         //Terminate the thread.
}


int main(int argc, char* argv) {
    int rc; //return value
    pthread_t threadid; //thread's id just an integer
    int t = 11; //data passed into the new thread

    //Create a new thread that will execute print "helloworld"
    rc = pthread_create(&threadid, NULL, PrintHello, (void*)t);

    if(rc) {
        printf("\n ERROR: return code from pthread_create is %d\n", rc);
        exit(1);
    }

    printf("\n Create new thread (%u) ... \n", thread_id);

    pthread_exit(NULL);     //Terminate the thread.

    return 0;
}

