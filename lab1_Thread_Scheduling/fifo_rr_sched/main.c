#include "os_definitions.h"

int main()
{
	pthread_t threads_table[THREADS_NUMBER];
	int result;
	long t_id;
	
	/** Creating threads */
	for(t_id = 0; t_id < THREADS_NUMBER; t_id++)
	{
		printf("Creating thread number : %ld \n", t_id);
		result = pthread_create(&threads_table[t_id], NULL, thread_function, (void *)t_id);
		
		if(result)
		{
			printf("ERROR: return code from pthread_create() is %d\n", result);
         	exit(-1);
		}
	}
	
	/** Waiting for threads to complete (from the main function) */
	for(t_id = 0; t_id < THREADS_NUMBER; t_id++)
	{
		result = pthread_join(threads_table[t_id], NULL);
		
		if(result)
		{
			printf("ERROR: return code from pthread_join() is %d\n", result);
         	exit(-1);
		}
		printf("Thread number : %ld termination \n", t_id); 	                                              	
	}
	
	
	return 0;
}
