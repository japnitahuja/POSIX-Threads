# Condition Variables

Condition variables in Pthreads (POSIX threads) provide a way for threads to block on a 
specific condition or set of conditions, and then be woken up by other threads when the condition 
becomes true. They are usually used in conjunction with mutexes to provide synchronization between threads.

Condition variables are defined as pthread_cond_t variables and are created and destroyed 
using `pthread_cond_init()` and `pthread_cond_destroy()` functions, respectively. They are used in 
conjunction with mutexes to avoid race conditions when waiting and signaling conditions.

`pthread_cond_wait()` is used to block a thread until a specific condition is met. 
It releases the associated mutex, allowing other threads to access the shared resource protected by the mutex. 
When the condition becomes true, `pthread_cond_signal()` or `pthread_cond_broadcast()` is used to wake up the blocked thread.

`pthread_cond_signal()` is used to wake up one of the threads waiting on a condition variable.
It is typically used when only one thread needs to be woken up.

`pthread_cond_broadcast()` is used to wake up all threads waiting on a condition variable. 
It is typically used when multiple threads may be waiting on the same condition, and all of them need to be woken up when the condition becomes true.

It is important to note that `pthread_cond_wait()` should always be called inside a while loop,
as it is possible for a thread to wake up without the condition being true. This is known as a 
"spurious wakeup" and can happen due to factors outside of the program's control, such as operating 
system scheduling or signal delivery. Therefore, the while loop checks the condition again after the 
thread is woken up to ensure that it is actually true before proceeding.

#### Source Code: 
`pthread_cond_var.c` This file demonstrates signal can be used to wake up one thread

`pthread_cond_broadcast.c` This file demonstrates broadcast can be used to wake up multiple thread
