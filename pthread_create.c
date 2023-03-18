/*
The program creates two new thread by calling pthread_create() function,
and then the new threads executes the function print_message_function().
The parent thread waits for the new threads to complete its
execution by calling pthread_join() function.
Author: japnitahuja
Date: 18th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

// just a function which prints statements
void *routine()
{
    printf("Test from threads\n");
    sleep(3);
    printf("Ending Thread\n");
}

int main(int argc, char *argv[])
{
    // variables to store the thread
    pthread_t t1;
    pthread_t t2;
    // thread creation
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    // waiting for threads to finish execution
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}