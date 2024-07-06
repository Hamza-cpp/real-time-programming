# Real-Time Programming Lab 1: Thread Scheduling and Synchronization

## overview

This firs lab explores thread scheduling and synchronization mechanisms using POSIX threads (pthreads) in C. It includes implementations of FIFO and Round-Robin scheduling algorithms, as well as examples of thread creation and synchronization.

## Generalities

### Introduction

Threads are a fundamental concept in computer programming that allows for parallel execution of different parts of a program. In real-time programming, threads are especially important because they allow a program to perform multiple tasks simultaneously.

A thread is essentially a separate sequence of instructions that can be executed independently of the main program. In real-time programming, a thread can handle tasks that require immediate attention or need to be executed quickly.

### POSIX Threads

In C language, POSIX threads are manipulated using the Pthreads library. Here are some common functions used to manipulate threads:

* `pthread_create():` Creates a new thread and assigns a unique thread ID to it.
* `pthread_join():` Waits for a thread (passed in argument) to terminate and returns the exit status of the thread.
* `pthread_exit():` Terminates the calling thread and returns a value to the parent thread.

For more details about the functions that manipulate threads in the Pthreads library, refer to the [documentation](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html) or type `man pthreads` in the terminal if you're a Linux user.

## Compilation and Execution

To compile and run the examples, use the following commands (for Linux users):

#### FIFO and Round-Robin Scheduling

Navigate to the `lab1_Thread_Scheduling/fifo_rr_sched` directory and use the provided Makefile:

```bash
cd lab1_Thread_Scheduling/fifo_rr_sched
make
./main
```

This will compile the scheduling simulations and execute them.

#### Thread Synchronization Example

To compile and run the thread synchronization example:

```bash
cd lab1_Thread_Scheduling/thread
gcc -o thread thread_ex.c -lpthread
./thread
```

### Concepts Covered

* Thread creation and termination.
* Mutexes for thread synchronization.
* FIFO and Round-Robin scheduling algorithms.
* Use of pthreads library for thread management.

### References

* [Pthreads Library Documentation](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html)
* [Sched Library Documentation](https://pubs.opengroup.org/onlinepubs/7908799/xsh/sched.h.html)
