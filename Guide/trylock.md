# Try Lock

`pthread_mutex_trylock()` is a function in pthreads that tries to lock a mutex,
but returns immediately if the mutex is already locked by another thread. It does not block 
the calling thread, but instead returns an error code indicating whether or not the lock was acquired.

This function can be useful in situations where a thread needs to
acquire a lock, but also needs to perform other work if the lock is not immediately available. 
By using `pthread_mutex_trylock()`, the thread can avoid blocking and instead perform other work until the lock becomes available.

#### Source Code: 
`pthread_trylock.c` This file demonstrates how only one thread gets access to the lock.
