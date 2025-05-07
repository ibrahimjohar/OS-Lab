#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

sem_t mutex;
sem_t empty;
sem_t full;

int buffer[BUFFER_SIZE];

int in = 0, out = 0;

void *producer(void *arg)
{
    int item;
    while(1)
    {
        item = rand() % 100;    //generate a random item to produce

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in];
        printf("produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);

        sleep(rand() % 3);  //simulate some time passing
    }
}

void *consumer(void *arg)
{
    int item; 
    while(1)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        printf("consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(rand() % 3);  //simulate time passing
    }
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    //initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    ///create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    //join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    //destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

//output:
// produced: 83
// consumed: 0
// produced: 15
// consumed: 0
// produced: 86
// consumed: 0
// produced: 21
// consumed: 0
// produced: 90
// consumed: 0
// produced: 26
// produced: 26
// consumed: 0
// consumed: 0
// produced: 68
// produced: 29
// consumed: 0
// produced: 62
// produced: 67
// consumed: 0
// produced: 2
// produced: 58
// consumed: 0
// consumed: 0
// produced: 56
// consumed: 0
// produced: 29
// produced: 21
// consumed: 0
// produced: 37
// consumed: 0
// produced: 15
// produced: 13
// consumed: 0