#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg)
{
    printf("thread is executing right now in 'thread_func()'...\n");
    pthread_exit((void*)42); //exiting the thread with the status/value of '42'
}

int main(int argc, char argv[])
{
    pthread_t thread;
    pthread_attr_t attributes; 
    int num = 10;
    void *exit_status;

    pthread_attr_init(&attributes);

    //thread created
    pthread_create(&thread, &attributes, thread_func, (void*)&num); 

    //wait for the thread to finish & then get its exit status
    pthread_join(thread, &exit_status);

    printf("thread exited with status: %ld\n", (long)exit_status);

    return 0;
}