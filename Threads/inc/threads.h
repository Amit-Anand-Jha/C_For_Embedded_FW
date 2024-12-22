#include<stdio.h>
#include "../../Common_Defs/inc/common_defs.h"
#include<pthread.h>


/*-----------------------------------------------------------------------------------------
 *                     Definitions of MACROS Globals Structures and Enums
 *-----------------------------------------------------------------------------------------*/


#define TOTAL_NUM_THREADS 2


// The global variable to keep the count of the total number of threads created
int total_num_threads;



//ENUM to indicate if the thread creation was successful - return value of API called
// from the pthread_create function
typedef enum thread_status
{
	thread_creation_successful  = 0,
	thread_creation_failed      = 1,
}thread_status_e;



// Definition of the input type arguement for each of the threads that will be created
// This will be a common input type to all the threads
typedef struct new_thread_input_args
{
	int priority;
	int thread_id;
}new_thread_input_args_s;



// Creating a general global variable of type pthread_t for all threads 
pthread_t thread[TOTAL_NUM_THREADS];



// Creating the global status variable for each thread
int thread_status[TOTAL_NUM_THREADS] = {(int)NULL};



// Initializing the global variable which is an argument to pthread_create for all threads
// This variable is basically the input to the API each thread calls
new_thread_input_args_s thread_args[TOTAL_NUM_THREADS] = {(int)NULL};





/*------------------------------------------------------------------------------------------
 * The pthread_t  structure :
 *
 * pthread_t is an opaque structure and hence its fields can not be accessed directly
 * 
 * This is an internal structure used by the pthread library for various thread functions
 *
 *-----------------------------------------------------------------------------------------*/






/*-----------------------------------------------------------------------------------------
 *                                  Declaration of APIs
 *-----------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------
 * The pthread_create API :
 *
 * pthread_create(pthread_t &thread_str_ptr, const pthread_attr_t thread_attr, void * thread_func(void *) , void * thread_func_arg_struct)
 *
 * @BRIEF : This API is internally called from the pthread header and access the pthread_t
 *          structure to create a new thread
 * 
 * @INPUT : 
 *           (i)    pointer to pthread_t type variable that holds thread related parameters
 *           (ii)   pointer to a structure specifying attirbutes of the thread. If its NULL
 *                  default attributes are used
 *           (iii)  pointer to the API to be executed by the new thread. This API should
 *                  return void *  and take a single void *  as argument
 *           (iv)   arguments passed to the API which the thread executes - API in (iii)
 *                  The arg can be typecaseted to any type as needed
 *
 * @RETURN : 
 *           0 - if the thread creation is successful
 *           Non-Zero error code - if thread creation fails
 *
 *-----------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------
 * Declaration of API count_num_threads()
 *
 * @BRIEF : This API counts the total number of threads created till the point of time this
 *          API is called
 *
 * @INPUT :
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/
void count_num_threads();




/*------------------------------------------------------------------------------------------
 * Declaration of API thread1_start()
 *
 * @BRIEF : This API is called from the First thread created
 *
 * @INPUT :
 *           (i)   head pointer of the LL where the new node has to be inserted
 *           (ii)  the data to be appended in the new node
 *           (iii) the position (index) at which the new node has to be inserted in the LL
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/
int thread1_start(new_thread_input_args_s *thread1_arg);



/*------------------------------------------------------------------------------------------
 * Declaration of API thread2_start()
 *
 * @BRIEF : This API is called from the second thread created
 *
 * @INPUT :
 *           (i)   head pointer of the LL where the new node has to be inserted
 *           (ii)  the data to be appended in the new node
 *           (iii) the position (index) at which the new node has to be inserted in the LL
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/
int thread2_start(new_thread_input_args_s *thread2_arg);







/*-----------------------------------------------------------------------------------------
 *                                  Definition of APIs
 *-----------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------
 * Declaration of API count_num_threads()
 *
 * @BRIEF : This API counts the total number of threads created till the point of time this
 *          API is called
 *
 * @INPUT :
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/
void count_num_threads()
{
	int thread_num, total_threads = 0;
	while(thread_args[thread_num].thread_id != (int)NULL)
	{
		total_threads = total_threads + 1;
		thread_num = thread_num + 1;
	}
	total_num_threads = total_threads;
	TRACE_HIGH("Total number of threads created till now = %d", total_threads);
}
