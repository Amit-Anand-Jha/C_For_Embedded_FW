#include<stdio.h>
#include "../inc/threads.h"


int main()
{
	TRACE_HIGH("Creating Threads");

	// Assigning the values for argument of API that thread1 calls
	thread_args[0].priority  = 1;
	thread_args[0].thread_id = 1;
	
	// Creating thread 1
	thread_status[0] = pthread_create(&thread[0], NULL, (void *)&thread1_start, (void *)&thread_args[0]);
	TRACE_HIGH("Thread %d status is = %d", thread_args[0].thread_id, thread_status[thread_args[0].thread_id]);

	count_num_threads();
	
	// Assigning values to the structure for thread2 input 
	// thread2 is  API called from the thread_create function
	thread_args[1].priority  = 2;
	thread_args[1].thread_id = 2;

	// Creatinng thread 2
	thread_status[1] = pthread_create(&thread[1], NULL, (void *)&thread2_start, (void *)&thread_args[1]);
	TRACE_HIGH("Thread %d status is = %d", thread_args[0].thread_id, thread_status[thread_args[0].thread_id]);

	count_num_threads();

	// Joining back of all threads
	for(int i = 0; i < TOTAL_NUM_THREADS; i++)
	{
		pthread_join(thread[i], NULL);
		TRACE_HIGH("Thread %d joins back in main function", thread_args[i].thread_id);
	}
	
	return 0;
}




int thread1_start(new_thread_input_args_s *thread1_args)
{ 
	int i = 0;
	TRACE_HIGH("Inside Thread %d Flow", thread1_args->thread_id);
	for(i = 0; i < 100000; i++)
	{
		if(i == 10000)
		{
			TRACE_HIGH("Thread %d still running", thread1_args->thread_id);
		}
	}

	return 0;
}




int thread2_start(new_thread_input_args_s *thread2_args)
{
	int j = 0;
	TRACE_HIGH("Inside Thread %d flow", thread2_args->thread_id);

	for(j = 0; j <= 1000; j++)
	{
		if(j == 1000)
		{
			TRACE_HIGH("Thread %d still running", thread2_args->thread_id);
		}
	}

	return 0;
}
