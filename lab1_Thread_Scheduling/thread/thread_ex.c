// to compile: gcc -l pthread -Wall -o thread <path_to>/thread_ex.c
// to run: ./thread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_NB 10

/** Implementation of a basic thread function */
void *thread_function(void *arg)
{
	int *t_id = (int *)arg;
	pid_t pid = getpid();

	printf("Hello from thread num: %d, with PID=%d\n", *t_id, pid);
	pthread_exit("Thread finished");
}

/** Main process */
int main(void)
{
	pthread_t thread[THREAD_NB];
	int t_id;
	int result;

	for (t_id = 0; t_id < THREAD_NB; t_id++)
	{
		result = pthread_create(&thread[t_id], NULL, thread_function, (void *)&t_id);
		if (result)
		{
			printf("ERROR: return code from pthread_create() is %d\n", result);
			exit(-1);
		}
		sleep(1);
	}

	for (t_id = 0; t_id < THREAD_NB; t_id++)
	{
		char *thread_result;
		result = pthread_join(thread[t_id], (void **)&thread_result);
		if (result)
		{
			printf("ERROR: return code from pthread_join() is %d\n", result);
			exit(-1);
		}
		printf("Thread %d returned: %s\n", t_id, thread_result);
	}

	pid_t pid = getpid();
	printf("Hello from main process with PID=%d\n", pid);
	return 0;
}
