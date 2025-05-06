// Write a multithreaded program that calculates various statistical values for a list of numbers.This program
// will pass a series of numbers on the command line and will then create three separate worker threads. One
// thread will determine the average of the numbers, the second will determine the maximum value, and the
// third will determine the minimum value. For example, suppose your program is passed the integers. (The
// array of numbers must be passed as parameter to threads, and the thread must return the calculated value to the main thread).
// 90 81 78 95 79 72 85
// The main thread will print:
// The average value is 82.
// The minimum value is 72.
// The maximum value is 95.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

typedef struct{
    int *numbers; //arr of numbers
    int count;
} Thread_data;

void *calc_avg(void *arg) //thread func -> average
{
    Thread_data* data = (Thread_data*)arg;  //store data from parameter arg

    int sum = 0;
    
    for (int i = 0; i < data->count; i++)
    {
        sum += data->numbers[i];
    }

    double* avg = malloc(sizeof(double));
    *avg = (double)sum / data->count;
    return avg;
}

void *calc_max(void *arg)
{
    Thread_data* data = (Thread_data*)arg;
    int* max = malloc(sizeof(int));

    *max = INT_MIN; //initial smallest int val

    for (int i = 0; i < data->count; i++)
    {
        if (data->numbers[i] > *max)
        {
            *max = data->numbers[i]; 
        }
    }
    return max;
}

void *calc_min(void *arg)
{
    Thread_data* data = (Thread_data*)arg;

    int* min = malloc(sizeof(int));

    *min = INT_MAX; //initial largest value

    for (int i = 0; i < data->count; i++)
    {
        if (data->numbers[i] < *min)
        {
            *min = data->numbers[i];
        }
    }
    return min;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("sage: %s <list of numbers>\n", argv[0]);
        return -1;
    }

    //converting cmd-line args to int arr
    int count = argc - 1;   //first arg being exec file name
    int nums[count];

    for (int i = 0; i < count; i++)
    {
        nums[i] = atoi(argv[i+1]);
    }

    //data for threads
    Thread_data data;

    data.numbers = nums;
    data.count = count;

    pthread_t threads[3]; //worker threads array

    //3 worker threads
    pthread_create(&threads[0], NULL, calc_avg, (void*)&data);
    pthread_create(&threads[1], NULL, calc_max, (void*)&data);
    pthread_create(&threads[2], NULL, calc_min, (void*)&data);

    //collect results
    double* avg;
    int* min;
    int* max;

    pthread_join(threads[0], (void**)&avg);
    pthread_join(threads[1], (void**)&max);
    pthread_join(threads[2], (void**)&min);

    printf("The average value is %.2f\n", *avg);
    printf("The minimum value is %d\n", *min);
    printf("The maximum value is %d\n", *max);

    //free allocated memory
    free(avg);
    free(min);
    free(max);

    return 0;
}
