#ifndef OS_DEFINITIONS_H
#define OS_DEFINITIONS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>

#define THREADS_NUMBER	5


/** Data structures fot threads (tasks) characteristics
*/
struct THREAD_DATA{
	int id;
	int remaining_time;
	int priority;
};
typedef struct THREAD_DATA thread_data;


/** Function declarations */
void *thread_function(void *thread_id);


#endif // OS_DEFINITIONS_H
