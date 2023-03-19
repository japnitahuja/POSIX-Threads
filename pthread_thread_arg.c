/*
This program illustrates passing values in the thread functions
as arguments.

Exepected Output:
Value is 0
Value is 1
Value is 5
Thread ID 0 has finished
Value is 9
Value is 6
Value is 2
Value is 7
Value is 8
Value is 4
Thread ID 1 has finished
Value is 3
Thread ID 2 has finished
Thread ID 3 has finished
Thread ID 4 has finished
Thread ID 5 has finished
Thread ID 6 has finished
Thread ID 7 has finished
Thread ID 8 has finished
Thread ID 9 has finished

Author: japnitahuja
Date: 19th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads
#define NUM_THREADS 10

void *print_value(void *arg) // pass in void pointer argument
{
    // first cast arg to int
    // then take out the value of arg
    int value = *(int *)arg;
    printf("Value is %d \n", value);
    free(arg);
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t threads[NUM_THREADS];

    // thread creation
    for (int i = 0; i < NUM_THREADS; i++)
    {

        int *x = malloc(sizeof(int)); // freed in the function
        *x = i;
        // fourth argument is the void pointer argument
        pthread_create(&threads[i], NULL, &print_value, x);
    }

    // thread joining
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread ID %d has finished\n", i);
    }
    return 0;
}