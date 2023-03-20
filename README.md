# Basic POSIX Threads (pthread) Programming

This GitHub repository contains examples and explanations of basic POSIX Threads programming using C programming language.

## Introduction

POSIX Threads (also known as Pthreads) is a POSIX standard for threads programming. It defines a set of C programming language constructs that can be used to create and manipulate threads. Threads are lightweight processes that can run concurrently within a single process. By using threads, we can divide a complex task into smaller parts, which can be executed in parallel, thereby improving the overall performance of the application.

## Table of Contents

1. [Overview](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/overview.md)
2. [Thread Creation](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/threadcreation.md)
   - `pthread_create.c` This file demonstrates how to create a new thread using the pthread_create() function.
   - `pthread_join.c` This file demonstrates how to wait for a thread to complete its execution using the pthread_join() function.
   - `pthread_multiple_threads.c` This file demonstrates how to create and join multiple threads using a for loop.
3. [Memory in Pthreads](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/sharedmemory.md)
   - `pthread_shared_vars.c` This file demonstrates how threads share memory.
   - `pthread_race_condition.c` This file demonstrates how the share memory may result in race conditions.
   - `pthread_mutex.c` This file demonstrates how to use a mutex to protect a critical section of code from concurrent access by multiple threads.
4. [Arguments and Return Values in thread functions](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/argumentandreturn.md)
   - `pthread_return_value.c` This file demonstrates how to return values from the thread functions. <br />
   - `pthread_exit.c` This file demonstrates how to use pthread_exit to return values. <br />
   - `pthread_thread_arg.c` This file demonstrates how to send arguments in thread functions. <br />
5. [Finding array sum parallely](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/sumarray.md)
   - `pthread_sum_array.c` This file demonstrates how to sum an array parallely using two threads. <br />
   - `pthread_sum_array_mutex.c` This file demonstrates how to sum an array parallely using mutex. <br />
6. [Try Lock](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/trylock.md)
   - `pthread_trylock.c` This file demonstrates how mutex lock is different from try lock. <br />
7. [Condition Variables](https://github.com/japnitahuja/POSIX-Threads/blob/main/Guide/conditionvar.md)
   - `pthread_cond_var.c` This file demonstrates how condition variables can be used. <br />
   - `pthread_cond_broadcast.c` This file demonstrates how brodcast signal can be used. <br />

## Prerequisites

To compile and run the code in this repository, you will need:

A C compiler (such as gcc)
A POSIX Threads library (such as pthreads)

## Usage

Go through each topic and run the code using:

On Windows:

```
gcc file_name.c -fopenmp
```

On Unix/Linux:

```
gcc file_name.c
```

## Conclusion

This repository provides a starting point for learning about basic POSIX Threads programming. The examples provided here can be used as a reference for implementing multithreaded applications in C. If you have any questions or suggestions, feel free to open an issue or submit a pull request.

## License

[MIT](https://choosealicense.com/licenses/mit/)
