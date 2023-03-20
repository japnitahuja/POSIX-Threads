# Thread Functions

## Return Value

In POSIX threads (pthread) programming, the return value of a thread function can be passed to the parent thread using 
the `pthread_join()` function. The `pthread_join()` function blocks the calling thread until the thread specified by the thread 
argument terminates. The exit status of the thread function can be obtained using a pointer argument to `pthread_join()` function.

Another way to do this is using `pthread_exit` which is a function that is used to terminate a thread. 
It is called by a thread to indicate that it is done executing and to pass a return value (if any) to the thread that joined it.

#### Source Code: 
`pthread_return_value.c` This program demonstrates how to use threads to return a value to the main program. The return_value() function returns 
an integer value of 100 using a dynamically allocated integer. 

`pthread_exit.c` This program demonstrates how to use pthread_exit to return a value to the main program.

## Thread Arguments
Thread arguments in Pthreads refer to passing arguments to a thread function when creating a new thread. This is useful when 
we want to perform some task in a thread function and want to pass some data to the thread function for processing. The thread
function can then use the passed arguments to perform its task.

In Pthreads, thread arguments can be passed to a thread function using the fourth argument of the 
pthread_create function, which is of type void \*. This argument can be used to pass any type of data to the thread function, 
but it needs to be cast to the appropriate type inside the thread function.

#### Source Code: 
`pthread_thread_arg.c` This program creates 10 threads using a for loop, and passes the thread ID as an argument to the 
thread function print_value(). The thread function casts the argument from a void pointer to an int pointer, and then 
dereferences the pointer to get the value of the argument.

