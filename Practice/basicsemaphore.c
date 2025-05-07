#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
sem_t empty_slots, full_slots;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    int item = *((int*)arg);

    sleep(1);   //produce item  //sleep to simulate production time

    sem_wait(&empty_slots);     //wait for empty slot in buffer

    pthread_mutex_lock(&mutex); //acquire mutex lock before accessing buffer

    //add item to buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] == -1)
        {
            buffer[i] = item;
            break;
        }
    }

    pthread_mutex_unlock(&mutex);   //release mutex lock

    sem_post(&full_slots);      //signal that buffer has a new item

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    sem_wait(&full_slots);      //wait for buffer to have data

    pthread_mutex_lock(&mutex);     //acquire mutex lock before accessing buffer

    int item = -1;

    //remove item from buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if(buffer[i] != -1)
        {
            item = buffer[i];
            buffer[i] = -1;
            break;
        }
    }

    //release mutex lock
    pthread_mutex_unlock(&mutex);

    //signal that an empty slot is available in buffer
    sem_post(&empty_slots);

    //consume item
    printf("consumed item: %d\n", item);

    pthread_exit(NULL);
}


int main()
{
    pthread_t producer_threads[NUM_PRODUCERS];
    pthread_t consumer_threads[NUM_CONSUMERS];

    int producer_args[NUM_PRODUCERS] = {1,2};

    //initialize mutex & semaphores
    pthread_mutex_init(&mutex, NULL);
    //initialise empty_slots to BUFFER_SIZE
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    //initialise full_slots to 0
    sem_init(&full_slots, 0, 0);

    //create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_create(&producer_threads[i], NULL, producer, &producer_args[i]);
    }

    //create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    }

    //join threads
    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_join(producer_threads[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        pthread_join(consumer_threads[i], NULL);
    }

    //destroy mutex & semaphores
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    return 0;
}
