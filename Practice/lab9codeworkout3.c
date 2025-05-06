// The following multithreaded C code contains a user defined signal SIGUSR1 handler and two ways to call it: i) using
// kill() system call that sends SIGUSR1 signal to a process, and ii) pthread_kill () library call that sends SIGUSR1
// signal to a specific thread.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS]; //global var to store thread IDs

void sigusr1_handler(int signum) //signal handler
{
    int i = gettid();
    int j = getppid();
    int k = getpid();

    fprint(stdout, "thread %u received SIGUSR1 signal (parent=%u)\n[pid=%u] {tid=%u} \n", pthread_self(), j, k, i);
}

void *thread_function(void *arg) //thread function
{
    //signal(SIGUSR1, sigusr1_handler); //register signal handler
    while(1) sleep(1); //keep the thread alive
    return NULL;
}

int main()
{
    signal(SIGUSR1, sigusr1_handler); //register signal handler
    
    for(int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0)
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    int i = gettid();
    int j = getpid();
    int k = getppid();

    fprintf(stdout, "parent process id: %u, process id: %u, main() thread id: %u\n", k, j, i);

    fprintf(stdout, "thread ids: 0=%u, 1=%u, 2=%u & 3=%lu\n", threads[0],threads[1],threads[2],threads[3]);

    //signal sending
    
    kill(j, SIGUSR1); //send signal to process

    pthread_kill(threads[2], SIGUSR1); //send signal to 3rd thread

    for(int i = 0; i < NUM_THREADS; i++)
    {
        if(pthread_join(threads[i], NULL) != 0)
        {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;

}