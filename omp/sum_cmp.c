#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 	16

int *arr;
int n = 10000000;				//number of enteries in array

int serial_sum(int * arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

void parallel_sum(int* arr, int*  global_sum)
{
 	int my_id = omp_get_thread_num();	//0, 1, 2, or ...
 	int my_n = n / NUM_THREADS;		//# of elements by this thread
 	int start = my_id * my_n;		//first element processed
 	int end = start + my_n - 1;		//last element processed
 	int my_sum = 0;
 	
#ifdef DEBUG
	printf("Thread #%d is starting at %d, ending at %d, processing %d\n",my_id, start, end, my_n);
#endif

	for(int i = start;i<=end; i++) 
	{
		my_sum += arr[i];
	}
 	
	#pragma omp critical
    		*global_sum += my_sum;
}


int main(int argc, char *argv[])
{

	if (argc > 1){n = atoi(argv[1]);}	//no error checking here!!!	
    
	int sum = 0;
        int *arr = malloc(n * sizeof(int));
	//generate random data
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	// start the timer!
	double start_time = omp_get_wtime();
    	sum = serial_sum(arr, n);
	double end_time = omp_get_wtime();
	
	printf("Sum of the array = %d in %f ms!\n",sum, (end_time-start_time)*1000);
	
	int global_sum = 0;
	start_time = omp_get_wtime();
#pragma omp parallel num_threads(NUM_THREADS)
	parallel_sum(arr, &global_sum);

	end_time = omp_get_wtime();
	printf("Paralllel sum of the array = %d in %f ms!\n",global_sum, (end_time-start_time)*1000);

	free(arr);				//housekeeping!
    
   	return 0;
}




