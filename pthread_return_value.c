/*
The program creates a new thread which calls the function return_value()
and stores the return value in main

Exepected Output:
Returned Value: 100

Author: japnitahuja
Date: 18th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

// just a function which prints statements
void *return_value()
{
    int *result = malloc(sizeof(int));
    *result = 100;
    return (void *)result;
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t t1;
    int *result;
    // thread creation
    pthread_create(&t1, NULL, &return_value, NULL);
    // wait for the child thread to join main thread
    pthread_join(t1, (void **)&result);

    printf("Returned Value: %d", *result);
    return 0;
}