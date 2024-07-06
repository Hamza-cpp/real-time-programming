#include "os_definitions.h"

/** This function describes what a thread does when activated */
void *thread_function(void *thread_id)
{
    pthread_t this_thread = pthread_self();
    struct sched_param params;

    params.sched_priority = sched_get_priority_max(SCHED_RR);
    int ret = pthread_setschedparam(this_thread, SCHED_RR, &params);
    if (ret != 0)
    {
        printf("Unsuccessful in setting thread realtime prio\n");
        return NULL;
    }

    int policy = SCHED_RR;

    ret = pthread_getschedparam(this_thread, &policy, &params);
    if (ret != 0)
    {
        printf("Couldn't retrieve real-time scheduling parameters\n");
        return NULL;
    }

    if (policy != SCHED_RR)
    {
        printf("Scheduling is NOT SCHED_RR!\n");
    }
    else
    {
        printf("SCHED_RR OK\n");
    }
    printf("This is the program of thread number %ld\n", (long)thread_id);
    /* Thread termination */
    pthread_exit(NULL);
}