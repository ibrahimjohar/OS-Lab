//code_workput_1.c

//design a multithreaded program that performs the summation
//of a non-negative integer in a separate thread using the 
//summation function 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0; //data that is to be shared by the threads - will be global

void *runner(void *parameters)
{
    //thread will begin control in this function
    int i, upper = *((int*)parameters);

    if(upper > 0)
    {
        for (i = 1; i <= upper; i++)
        {
            sum = sum + i;
        }
    }
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t threadID; //thread identifier
    pthread_attr_t attributes; //set attributes for the thread
    int num = 5;

    //get the default attributes
    pthread_attr_init(&attributes); 
    
    //create the thread
    pthread_create(&threadID, &attributes, runner, (void*)&num); 

    //now wait for the thread to exit
    pthread_join(threadID, NULL);

    printf("sum=%d\n", sum);

    exit(0);
}

//to run this in terminal

//  gcc summation_threads.c -o summation_threads -lpthread
