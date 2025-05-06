//serial code - not with threads
#include <stdio.h>
#include <stdlib.h>

#define N 10

float arrA[N], arrB[N], arrC[N];

int main(int argc, char argv[])
{
    //initialize A & B 
    for (int i = 0; i < N; i++)
    {
        arrA[i] = (float)i;       // example: A[i] = i
        arrB[i] = (float)i*2.0; // example: B[i] = i * 2.0
    }

    //compute C = A + B
    for (int i = 0; i < N; i++)
    {
        arrC[i] = arrA[i] + arrB[i];
    }

    //print
    for(int i = 0; i < N; i++)
    {
        printf("arrC[%d] = %f\n", i, arrC[i]);
    }

    return 0;
}