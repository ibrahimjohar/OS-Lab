#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread(void *arg)
{
    printf("%s: begin:\n", (char*)arg);

    int i;
    //int counter=0;
    for(i = 0; i < 10; i++)
    {
        counter = counter + 1;
    }
    printf("%s: done. counter = %d\n", (char *)arg,counter);

    return NULL;
    //or
    //pthread_exit(0);
}

int main(int argc, char argv[])
{
    pthread_t p1, p2;

    printf("main: begin (counter = %d)\n", counter);

    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");

    //join waits for the thread to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("main: done with both (counter = %d)\n", counter);

    return 0;
}

//since both threads access the same shared variable 'counter', they face race
//condition, as one has to pick up from the value the last one left at,
//essentially, there is a lack of synchronization in this program
//to ensure that synchronization takes place and both threads read from the same
//shared variable:

// To make this safe, you’d need a mutex or atomic operations. For example:

// pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
// // inside the loop:
// pthread_mutex_lock(&m);
// counter++;
// pthread_mutex_unlock(&m);