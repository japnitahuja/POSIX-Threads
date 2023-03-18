/*
This program illustrates that threads have shared memory.
Thread 1 updates the variable x but when thread 2 prints it, the
value is updated.

Exepected Output:
Value of x: 8
Value of x: 8

Author: japnitahuja
Date: 18th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

int x = 3;

// just a function which prints statements
void *routine1()
{
    x += 5;
    printf("Value of x: %d \n", x);
}

void *routine2()
{
    sleep(3);
    printf("Value of x: %d \n", x);
}

int main(int argc, char *argv[])
{
    // variable to store the threads
    pthread_t t1, t2;
    // thread creation
    pthread_create(&t1, NULL, &routine1, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);
    // wait for the child thread to join main thread
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}