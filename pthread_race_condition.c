/*
The program creates two threads that both run the function
increase_sum(). This function increments the global variable
sum by 1,000,000 times in a loop. Since both threads are accessing
the same global variable sum, they can get into a race condition
where one thread overwrites the update made by the other thread.
This leads to incorrect results.

The expected output is 2000000, which is the sum of the increments
made by both threads. However, due to race conditions,
the actual sum can be less than 2000000.

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