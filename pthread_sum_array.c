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

void *print_value(void *arg) // pass in void pointer argument
{
    // first cast arg to int
    // then take out the value of arg
    int start = *(int *)arg;
    int sum = 0;

    for (int i = start; i < start + 5; i++)
    {
        sum += array[i];
    }

    free(arg);

    int *result = malloc(sizeof(int));
    *result = sum;

    return (void *)result;
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t threads[NUM_THREADS];
    int *half_sum[NUM_THREADS];

    // thread creation
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *x = malloc(sizeof(int)); // freed in the function
        *x = i * 5;                   // start index
        // fourth argument is the void pointer argument
        pthread_create(&threads[i], NULL, &print_value, x);
    }

    // thread joining
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], (void **)&half_sum[i]);
        printf("Thread ID %d has finished with %d\n", i, *half_sum[i]);
    }

    // summing all half sums
    int total_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        total_sum += *half_sum[i];
    }

    printf("Total sum of array is %d", total_sum);
    return 0;
}