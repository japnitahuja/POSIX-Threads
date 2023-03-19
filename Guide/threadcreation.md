# Thread Creation

To create a new thread using pthreads, you need to call the `pthread_create()` function. This function takes four arguments:

* `thread`: A pointer to a pthread_t variable that will hold the thread ID of the newly created thread.
* `attr`: A pointer to a pthread_attr_t variable that specifies the attributes of the thread. You can pass NULL to use the default thread attributes.
* `start_routine`: A pointer to the function that the new thread will execute. The function should have the following signature: void *(*start_routine)(void *). The arg parameter is a pointer to any data that needs to be passed to the thread function.
* `arg`: A pointer to any data that needs to be passed to the thread function

#### Source Code: 
`pthread_create.c` This file demonstrates how to create a new thread using the pthread_create() function.

## Joining threads to main thread

The `pthread_join()` function is used to wait for a thread to terminate before the main thread continues execution. 
This function blocks the calling thread until the specified thread terminates. It takes the following arguments:

* `thread`: The thread ID of the thread to wait for.
* `value_ptr`: A pointer to a location where the exit status of the terminated thread can be stored. If this parameter is NULL, the exit status is discarded.

### Why use pthread_join?

`pthread_join()` is used when you need to wait for a thread to complete before the rest of the program can continue executing. 
When you create a thread using `pthread_create()`, the new thread runs independently of the main thread, and it may take some time to complete its execution.

If you don't use `pthread_join()` to wait for the thread to complete, the main thread may terminate before the new thread finishes executing. 
This can cause problems if the new thread is still doing some work that the main thread depends on. In addition, if the new thread dynamically 
allocates memory or other resources, those resources may not be cleaned up properly if the thread is not joined.

Overall, `pthread_join()` is an important function to use when working with threads to ensure proper synchronization and resource management in multithreaded programs.

#### Source Code: 
`pthread_join.c` This file demonstrates how to wait for a thread to complete its execution using the pthread_join() function.

## Generating multiple threads

Spawning multiple threads and joining multiple threads using a for loop is a common technique used in multithreaded programming to perform a
large number of tasks concurrently.

#### Source Code: 
`pthread_multiple_threads.c` This file demonstrates how to create and join multiple threads using a for loop.


