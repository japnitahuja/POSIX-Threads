/*
This program illustrates how due to the shared memory in threads they
might get into race conditions. The thread sum should be 2000000 but
due to race conditions the value of sum would be less than 2000000

Exepected Output:
The total should be 2000000
The total sum is 1149022

*the sum in the second line may differ

Author: japnitahuja
Date: 18th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

int sum = 0;

// increases value of variable sum
void *increase_sum()
{
    for (int i = 0; i < 1000000; i++)
    {
        sum++;
    }
}

int main(int argc, char *argv[])
{
    // variable to store the threads
    pthread_t t1, t2;
    // thread creation
    pthread_create(&t1, NULL, &increase_sum, NULL);
    pthread_create(&t2, NULL, &increase_sum, NULL);
    // wait for the child thread to join main thread
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // print sum after both threads join
    printf("The total should be 2000000\n");
    printf("The total sum is %d \n", sum);
    return 0;
}