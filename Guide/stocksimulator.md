# Stock Market Simulation

This program simulates a very simple stock market where we have a stock amount and the stock brokers 
(i.e. the threads) try to buy the stock till it's available.

The program first declares an integer variable `stock_available` to represent the total stock available 
for purchase, and a `pthread_mutex_t` variable `stock_mutex` to provide mutual exclusion for accessing and updating stock_available.

The program then declares a struct `thread_data` to store data for each broker, which includes a broker ID.

The `stock_broker()` function defines the behavior of each broker. Each broker continuously tries to
buy stocks until all stocks are sold. Each time a broker tries to buy stocks, it generates a random
number between 1 and 50 (inclusive) and checks if there are enough stocks available to buy that 
number of stocks. If so, it buys the stocks and updates the total stocks bought. The function then prints out the number of stocks bought by the broker.

The `main()` function creates 5 threads, each corresponding to a broker, and initializes the broker
data for each thread. It then creates each thread using `pthread_create()` and passes the corresponding broker data as the thread's argument.

The main function then joins all 5 threads using `pthread_join()`. For each thread, it extracts the 
number of stocks bought by the broker from the returned value of `stock_broker()` and prints out the broker 
ID and the number of stocks bought by that broker.

#### Source Code: 
`stocksimulator1.c`

## Using condition variables
The second program, named `stocksimulator2.c`, builds upon the first program `stocksimulator1.c` by adding a stock exchange 
thread. The stock exchange thread updates the stock price randomly while the 
brokers buy stocks based on a condition - they only buy if the stock price is below a certain threshold.

The program starts by declaring the necessary data structures and initializing the mutex and 
condition variable. Then, the stock exchange thread and the broker threads are created using `pthread_create`.

In the stock exchange thread, the price of the stock is randomly updated and the `price_cond` variable is broadcasted to inform the brokers.

In the broker threads, the thread waits for the stock price to be below a certain threshold
before buying stocks. If the stock price is below the threshold and there are enough stocks available, 
the broker buys a random number of stocks. This process repeats until all the stocks are sold.

Overall, this program demonstrates the use of threads and condition variables in a real-world scenario.

#### Source Code: 
`stocksimulator2.c`

