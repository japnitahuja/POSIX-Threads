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

    // we use the same arg as a return argument
    *(int *)arg = sum;
    return arg;
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t threads[NUM_THREADS];

    // thread creation
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *x = malloc(sizeof(int));
        *x = i * 5; // start index
        // fourth argument is the void pointer argument
        pthread_create(&threads[i], NULL, &print_value, x);
    }

    // thread joining
    int total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *half_sum; // to store returned value
        pthread_join(threads[i], (void **)&half_sum);
        printf("Thread ID %d has finished with %d\n", i, *half_sum);
        // summing up the total
        total_sum += *half_sum;
        // free the dynamically allocated memory
        // during thread creation
        free(half_sum);
    }

    printf("Total sum of array is %d", total_sum);
    return 0;
}