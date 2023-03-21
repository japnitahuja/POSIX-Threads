/*
This program simulates a very simple stock market where we have
a stock amount and the stock brokers (i.e. the threads) try to
buy the stock till its available.


Author: japnitahuja
Date: 20th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads
#include <time.h>

// declaring stock data
int stock_available = 100;
pthread_mutex_t stock_mutex;

// struct to store broker data
struct thread_data
{
    int broker_id;
};

// defines behavior of stock broker
void *stock_broker(void *arg)
{
    srand(time(NULL));
    struct thread_data *broker_data;
    broker_data = (struct thread_data *)arg;
    int total_stocks_bought = 0;

    while (stock_available > 0)
    {
        // random buying number bet 1 to 20
        int num_stocks = rand() % 50 + 1;
        pthread_mutex_lock(&stock_mutex);
        // checking if enough stocks are available
        if (stock_available >= num_stocks)
        {
            stock_available -= num_stocks;
            pthread_mutex_unlock(&stock_mutex);
            total_stocks_bought += num_stocks;
            printf("Broker %d: %d stocks bought \n", broker_data->broker_id, num_stocks);
        }
        else
        {
            pthread_mutex_unlock(&stock_mutex);
        }
    }
    // returning total tickets sold by thread
    *(int *)arg = total_stocks_bought;
    return arg;
}

int main(int argc, char *argv[])
{
    // variable to store the thread and thread data
    pthread_t threads[5];
    struct thread_data thread_data_array[5];

    // initialisation of mutex
    pthread_mutex_init(&stock_mutex, NULL);

    // thread creation
    for (int i = 0; i < 5; i++)
    {
        // Initialize data for current thread
        thread_data_array[i].broker_id = i;
        int error = pthread_create(&threads[i], NULL,
                                   &stock_broker, (void *)&thread_data_array[i]);
        if (error)
        {
            printf("ERROR: pthread_create() in thread %d\n", i);
            exit(-1);
        }
    }

    // thread joining
    for (int i = 0; i < 5; i++)
    {
        int *r; // to store returned value

        int error = pthread_join(threads[i], (void **)&r);
        if (error)
        {
            printf("ERROR: pthread_join() in thread %d\n", i);
            exit(-1);
        }
        if (i == 0)
        {
            printf("\n");
            printf("\n");
            printf("*********************\n");
            printf("SUMMARY DATA\n");
        }
        printf("Broker %d bought %d stocks.\n", i, *r);
    }

    // destroying mutex
    pthread_mutex_destroy(&stock_mutex);

    return 0;
}