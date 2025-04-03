#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

typedef struct {
    int *numbers;
    int count;
} thread_data;

void* calc_avg(void* arg) //thread func -> average
{
    thread_data* data = (thread_data*)arg;

    int sum = 0;

    for (int i = 0; i < data->count; i++)
    {
        sum += data->numbers[i];
    }

    double* avg = malloc(sizeof(double));
    *avg = (double)sum / data->count;
    return avg;


}

void* calc_min(void* arg) //thread func -> minimum
{
    thread_data* data = (thread_data*)arg;
    int* min = malloc(sizeof(int));
    *min = INT_MAX; //initial large val

    for (int i = 0; i < data->count; i++)
    {
        if (data->numbers[i] < *min)
        {
            *min = data->numbers[i];
        }
    }
    return min;
}

void* calc_max(void* arg) //thread func -> maximum
{
    thread_data* data = (thread_data*)arg;
    int* max = malloc(sizeof(int));
    *max = INT_MIN; //initial small val

    for (int i = 0; i < data->count; i++)
    {
        if (data->numbers[i] > *max)
        {
            *max = data->numbers[i];
        }
    }
    return max;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <list of numbers>\n", argv[0]);
        return 1;
    }

    //converting cmd-line args to an int array
    int count = argc - 1;
    int nums[count];

    for (int i = 0; i < count; i++)
    {
        nums[i] = atoi(argv[i+1]);
    }

    //data for threading
    thread_data data;
    data.numbers = nums;
    data.count = count;

    pthread_t threads[3];

    //3 worker threads
    pthread_create(&threads[0], NULL, calc_avg, &data);
    pthread_create(&threads[1], NULL, calc_min, &data);
    pthread_create(&threads[2], NULL, calc_max, &data);


    //collect results
    double* avg;
    int* min;
    int* max;

    pthread_join(threads[0], (void**)&avg);
    pthread_join(threads[1], (void**)&min);
    pthread_join(threads[2], (void**)&max);


    printf("The average value is %.2f\n", *avg);
    printf("The minimum value is %d\n", *min);
    printf("The maximum value is %d\n", *max);

    //free allocated memory
    free(avg);
    free(min);
    free(max);

    return 0;
}