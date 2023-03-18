/*
The program creates a new thread by calling pthread_create() function,
and then the new thread executes the function print_message().
The program waits for the thread to finish excution using pthread_join()

Exepected Output:
Hello from threads

Author: japnitahuja
Date: 18th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

// just a function which prints statements
void *print_message()
{
    printf("Hello from threads\n");
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t t1;
    // thread creation
    pthread_create(&t1, NULL, &print_message, NULL);
    // wait for the child thread to join main thread
    pthread_join(t1, NULL);
    return 0;
}