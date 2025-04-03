#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000 //10 million

float A[N], B[N], C[N];

void initalise() 
{
    for(int i = 0; i < N; i++)
    {
        //random values btw 0 to 100
        A[i] = (float)(rand() % 100);
        B[i] = (float)(rand() % 100);
    }
}

void serial_addition()
{
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }
}

int main()
{
    clock_t start, end;
    double time_taken;

    initalise(); //A & B initialised

    start = clock(); //start time

    serial_addition(); //computation performed here

    end = clock(); //end time

    time_taken = ((double)(end-start)) / CLOCKS_PER_SEC;

    printf("time taken (serial): %.6f secs\n", time_taken);

    return 0;
}