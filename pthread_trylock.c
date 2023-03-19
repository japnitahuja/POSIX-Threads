/*
This program illustrates how to use try lock.

Exepected Output:
Thread 8 did not get the lock!
Thread 7 did not get the lock!
Thread 2 did not get the lock!
Thread 0 did not get the lock!
Thread 9 did not get the lock!
Thread 3 did not get the lock!
Thread 6 did not get the lock!
Thread 5 did not get the lock!
Thread 4 got the lock!
Thread 1 did not get the lock!

Author: japnitahuja
Date: 19th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads
#include <time.h>
#define NUM_THREADS 10

pthread_mutex_t mutex; // creation of mutex

void *try_lock(void *arg)
{
    int threadID = *(int *)arg;

    // making thread sleep for random time between
    //  0 to 3
    srand(time(NULL));
    int sleeptime = rand() % 3;
    sleep(sleeptime);

    // if thred gets the lock
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Thread %d got the lock!\n", threadID);
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    // if thread does not get the lock
    else
    {
        printf("Thread %d did not get the lock!\n", threadID);
    }

    free(arg)
}

int main(int argc, char *argv[])
{
    // variable to store the threads
    pthread_t threads[NUM_THREADS];

    // initialisation of mutex
    pthread_mutex_init(&mutex, NULL);

    // thread creation
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *x = malloc(sizeof(int));
        *x = i; // sending arg as thread ID
        // fourth argument is the void pointer argument
        pthread_create(&threads[i], NULL, &try_lock, x);
    }

    // thread joining
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // destroying mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}