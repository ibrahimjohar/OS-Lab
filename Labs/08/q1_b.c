#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 10000000  //10 million
#define NUM_THREADS 10 //num of worker threads

float A[N], B[N], C[N];

typedef struct {
    int start;
    int end;
} thread_data;

void initalise() 
{
    for(int i = 0; i < N; i++)
    {
        //random values btw 0 to 100
        A[i] = (float)(rand() % 100);
        B[i] = (float)(rand() % 100);
    }
}

void* parallel_addition(void* arg)
{
    thread_data* data = (thread_data*)arg;

    for(int i = data->start; i < data->end; i++)
    {
        C[i] = A[i] + B[i];
    }
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    thread_data th_data[NUM_THREADS];

    clock_t start, end;
    double time_taken;

    initalise();

    start = clock();

    //creating threads
    int chunk_size = N / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        th_data[i].start = i * chunk_size;
        th_data[i].end = (i+1) * chunk_size;
        pthread_create(&threads[i], NULL, parallel_addition, &th_data[i]);
    }


    //joining threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    end = clock();


    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("time taken (parallel w/ %d threads): %.5f seconds\n", NUM_THREADS, time_taken);

    return 0;
}