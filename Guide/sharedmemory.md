# Memory in pthreads

In pthreads, shared global variables are accessible by all threads within a process. 

#### Source Code: 
`pthread_shared_vars.c` This file demonstrates how global variables are shared between threads.

## Race conditions
A race condition is a software defect that occurs when two or more threads or processes access a shared resource, such as a variable or a file, 
and attempt to modify it at the same time. The outcome of the program becomes dependent on the relative timing of the thread or 
process execution, leading to unpredictable or erroneous behavior.

For example, consider two threads, A and B, accessing a shared variable X. 
If thread A reads the current value of X, performs some operation on it, and then writes the result back to X, 
and at the same time thread B reads the current value of X, performs a different operation on it, and then writes 
the result back to X, the final value of X will depend on the order in which the threads execute. If thread B writes 
to X before thread A, the result of thread A's operation will be lost.

#### Source Code: 
`pthread_race_condition.c` This file demonstrates how the share memory may result in race conditions.The program creates two threads that both run the 
function increase_sum(). This function increments the global variable sum by 1,000,000 times in a loop. Since both threads are 
accessing the same global variable sum, they can get into a race condition where one thread overwrites the update made by the other thread. 
This leads to incorrect results.The expected output is 2000000, which is the sum of the increments made by both threads.
However, due to race conditions, the actual sum can be less than 2000000.

### Mutexes

To fix this, the program needs to use synchronization mechanisms such as mutexes to ensure that only one thread accesses the 
global variable sum at a time. By using a mutex, one thread will wait for the other thread to finish before updating the sum 
variable, which avoids race conditions. When using mutexes, it's important to initialize them before using them and destroy them after they are no longer needed.
The `pthread_mutex_init` function initializes the mutex variable mutex. The `pthread_mutex_destroy` function destroys the mutex after both 
threads have finished executing. This ensures that the mutex is properly cleaned up and avoids potential issues with memory leaks.

#### Source Code: 
`pthread_mutex.c` In this modified version, the mutex is locked before updating the sum variable and unlocked after 
the update is complete. This ensures that only one thread can access the sum variable at a time, preventing race conditions. 
The output of the program should now be the expected sum of 2000000.


