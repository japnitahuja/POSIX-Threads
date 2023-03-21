/*
This program will build on stocksimulator1 to add a stock exchange
thread. Stock brokers will only buy the stock if it is below a certain
price. We will be using condition variables to let the brokers know.


Author: japnitahuja
Date: 20th March 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //library for pthreads
#include <time.h>

// declaring stock data
struct stock_data
{
    float price;
    int count;
};

struct stock_data stock = {200.00, 100};
pthread_mutex_t stock_mutex;
pthread_cond_t price_cond;

// struct to store broker data
struct thread_data
{
    int broker_id;
};

// defines the stock exchange behavior
void *stock_exchange(void *arg)
{

    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&stock_mutex);
        int variation = rand() % 20 + 1;
        stock.price -= variation;
        pthread_cond_broadcast(&price_cond);
        printf("New stock price: %f\n", stock.price);
        pthread_mutex_unlock(&stock_mutex);
        sleep(1);
    }

    pthread_exit(NULL);
}

// defines behavior of stock broker
void *stock_broker(void *arg)
{
    srand(time(NULL));
    struct thread_data *broker_data;
    broker_data = (struct thread_data *)arg;
    int total_stocks_bought = 0;

    while (stock.count > 0)
    {
        // random buying number bet 1 to 20
        int num_stocks = rand() % 10 + 1;
        pthread_mutex_lock(&stock_mutex);

        while (stock.price > 150)
        {
            printf("Broker %d: Waiting... \n", broker_data->broker_id);
            pthread_cond_wait(&price_cond, &stock_mutex);
        }
        // checking if enough stocks are available
        if (stock.count >= num_stocks)
        {
            stock.count -= num_stocks;
            pthread_mutex_unlock(&stock_mutex);
            total_stocks_bought += num_stocks;
            printf("Broker %d: %d stocks bought \n", broker_data->broker_id, num_stocks);
            sleep(1);
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
    pthread_t threads[6];
    struct thread_data thread_data_array[5];

    // initialisation of mutex and cond
    pthread_mutex_init(&stock_mutex, NULL);
    pthread_cond_init(&price_cond, NULL);

    // create stock exchange thread
    pthread_create(&threads[5], NULL, &stock_exchange, NULL);

    // thread creation for brokers
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

    // destroying mutex and cond
    pthread_mutex_destroy(&stock_mutex);
    pthread_cond_destroy(&price_cond);

    return 0;
}