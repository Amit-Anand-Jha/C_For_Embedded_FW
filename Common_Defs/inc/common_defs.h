#include<stdio.h>


// The below MACRO are used to align the columns in the printf API used
#define col0_width  -30
#define col1_width  30
#define col2_width  7 
#define col3_width  5


// The MACRO below holds the string which is the filename containing debug traces
#define FILENAME "dbg_traces.txt"



// The Macro below can be used to print a simple string without any other data type 
#define TRACE(...) do{\
		FILE *file_ptr = fopen(FILENAME, "a+");\
		printf("\n%*s  %*s()  %*d : %s \n", col0_width, __FILE__, col1_width, __func__, col2_width, __LINE__, __VA_ARGS__);\
		fprintf(file_ptr,"\n%*s  %*s()  %*d : %s \n", col0_width, __FILE__, col1_width, __func__, col2_width, __LINE__, __VA_ARGS__);\
	}\
	while(0)


// The MACRO below can be used to print any normal printf format with some extra debug data
// like Filename, Function name and Line Number of the print statement. This Macro can print 
// any number of data types included in the printf and not just limited to simple strings
#define TRACE_HIGH(fmt, ...) do{\
		FILE *file_ptr = fopen(FILENAME, "a");\
		printf("\n%*s %*s() %*d : ", col0_width, __FILE__, col1_width, __func__, col2_width, __LINE__);\
		printf(fmt, ##__VA_ARGS__);\
		fprintf(file_ptr, "\n%*s %*s() %*d : ", col0_width, __FILE__, col1_width, __func__, col2_width, __LINE__);\
		fprintf(file_ptr, fmt, ##__VA_ARGS__);\
	}\
	while(0)
