/*
The program creates shows how to create and join multiple threads
using a for loop

Exepected Output:
Hello from threads
Hello from threads
Thread ID 0 has finished
Thread ID 1 has finished
Thread ID 2 has finished
Thread ID 3 has finished
Hello from threads
Hello from threads
Hello from threads
Hello from threads
Hello from threads
Hello from threads
Thread ID 4 has finished
Thread ID 5 has finished
Thread ID 6 has finished
Thread ID 7 has finished

Author: japnitahuja
Date: 18th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

#define NUM_THREADS 8 // number of threads

// just a function which prints statements
void *print_message()
{
    printf("Hello from threads\n");
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t threads[NUM_THREADS];

    // thread creation
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, &print_message, NULL);
    }

    // thread joining
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(&threads[i], NULL);
        printf("Thread ID %d has finished\n", i);
    }
    return 0;
}