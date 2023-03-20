# Finding the sum of the array parallely

This program creates two threads to compute the sum of half of the elements of an array in parallel. 
The array contains integers from 1 to 10. Each thread computes the sum of 5 consecutive elements of the 
array, and the main thread adds up the results of the two threads to get the total sum of the array.

The print_value() function is used as the thread function, and it takes a void pointer argument that is 
cast to an integer to get the starting index of the elements that the thread will sum up. The thread function
then computes the sum of 5 consecutive elements of the array and returns the result in a dynamically allocated 
integer memory block, which is freed by the main thread after joining the threads.

In the main function, an array of 10 integers is declared, and two threads are created to compute the 
sum of the first half and the second half of the array, respectively. The pthread_create() function is 
used to create the threads, and the fourth argument is a void pointer to the starting index of the elements that the thread will sum up.

After the threads are created, the main thread joins them and adds up the results to get the total sum of the 
array. The pthread_join() function is used to join the threads, and the returned value is cast to a pointer to an 
integer, which is dereferenced to get the sum computed by the thread. The dynamically allocated memory block returned by 
the thread is freed by the main thread.

Finally, the total sum of the array is printed to the console.

#### Source Code: 
`pthread_sum_array.c`

## Using mutex
This program uses pthreads to sum an array parallely. 
It uses a mutex lock to ensure that the global variable total_sum is updated correctly by only one thread at a time.

The add_array_sum function takes in a void pointer argument arg, which is
first cast to an integer pointer to get the starting index of the thread. 
It then sums up the values of the array from the starting index to the starting 
index + 5. To update the global total_sum variable, it first locks the mutex, adds 
the sum to total_sum, and then unlocks the mutex. Finally, it frees the dynamically allocated memory for arg.

In main, the mutex is initialised using pthread_mutex_init. The thread creation is
similar to the previous program, except that add_array_sum is used instead of print_value. 
The mutex is locked and unlocked around the code that updates the total_sum variable.

After the threads have finished executing, the mutex is destroyed using pthread_mutex_destroy. Finally, the total sum is printed.

#### Source Code: 
`pthread_sum_array_mutex.c`

