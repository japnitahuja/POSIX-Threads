/*
This program illustrates how to use mutex to avoid race conditions.

Exepected Output:
The total should be 2000000
The total sum is 2000000

Author: japnitahuja
Date: 19th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

int sum = 0;
pthread_mutex_t mutex;

// increases value of variable sum
void *increase_sum()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        sum++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    // variable to store the threads
    pthread_t t1, t2;

    // initialisation of mutex
    pthread_mutex_init(&mutex, NULL);

    // thread creation
    pthread_create(&t1, NULL, &increase_sum, NULL);
    pthread_create(&t2, NULL, &increase_sum, NULL);

    // wait for the child thread to join main thread
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // destroying mutex
    pthread_mutex_destroy(&mutex);

    // print sum after both threads join
    printf("The total should be 2000000\n");
    printf("The total sum is %d \n", sum);
    return 0;
}