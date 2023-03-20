/*
The program creates shows how to use condition variables by stimulating
a program where 15 candies are to be bought. 1 thread produces 5 candies
each second and another waits for there to be enough candies to then
buy 15 candies.

Author: japnitahuja
Date: 20th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads

#define NUM_THREADS 2 // number of threads

int num_candies = 0;           // number of candies
pthread_cond_t buying_cond;    // condition variable for buying
pthread_mutex_t candies_mutex; // mutex for num_candies

// produces candies every second
void *produce_candies()
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&candies_mutex);
        num_candies += 5;
        printf("Produced more candies. Now candies = %d\n", num_candies);
        pthread_cond_signal(&buying_cond); // signals when num_candies changes
        pthread_mutex_unlock(&candies_mutex);
        sleep(1);
    }
}

// buying candies
void *buying_candies()
{
    pthread_mutex_lock(&candies_mutex);
    while (num_candies < 15)
    {
        // checks for the num candies to be
        // greater than 15
        printf("Not enough candies to buy.\n");
        sleep(1);
        pthread_cond_wait(&buying_cond, &candies_mutex);
    }
    // if num candies > 15 then buys 15
    num_candies -= 15;
    printf("Bought 15 candies. Now candies = %d\n", num_candies);
    pthread_mutex_unlock(&candies_mutex);
}

int main(int argc, char *argv[])
{
    // variable to store the thread
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&candies_mutex, NULL);
    pthread_cond_init(&buying_cond, NULL);

    // creating production thread
    pthread_create(&threads[0], NULL, &produce_candies, NULL);

    // creating buying thread
    pthread_create(&threads[1], NULL, &buying_candies, NULL);

    // thread joining
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&candies_mutex);
    pthread_cond_destroy(&buying_cond);
    return 0;
}