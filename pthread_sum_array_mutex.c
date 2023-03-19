/*
This program illustrates how to sum an array parallely using threads.

Exepected Output:
Thread ID 0 has finished with 15
Thread ID 1 has finished with 40
Total sum of array is 55

Author: japnitahuja
Date: 19th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads
#define NUM_THREADS 2

int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int total_sum = 0;     // creating global sum variable
pthread_mutex_t mutex; // creating mutex lock

void *add_array_sum(void *arg)
{
    // first cast arg to int
    // then take out the value of arg
    int start = *(int *)arg;

    for (int i = start; i < start + 5; i++)
    {
        // updating total sum one thread at a time
        pthread_mutex_lock(&mutex);
        total_sum += array[i];
        pthread_mutex_unlock(&mutex);
    }

    free(arg);
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t threads[NUM_THREADS];

    // initialisation of mutex
    pthread_mutex_init(&mutex, NULL);

    // thread creation
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *x = malloc(sizeof(int));
        *x = i * 5; // start index
        // fourth argument is the void pointer argument
        pthread_create(&threads[i], NULL, &add_array_sum, x);
    }

    // thread joining
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // destroying mutex
    pthread_mutex_destroy(&mutex);

    printf("Total sum of array is %d", total_sum);

    return 0;
}