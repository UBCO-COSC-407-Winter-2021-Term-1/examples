#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int *arr;
int n = 1000000;				//number of enteries in array


int serial_sum(int * arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

int main()
{
    
	int sum = 0;
        int *arr = malloc(n * sizeof(int));
	//generate random data
	for (int i = 0; i < n; i++)
		arr[i] = rand();

	// start the timer!
	double start_time = omp_get_wtime();
    	sum = serial_sum(arr, n);
	double end_time = omp_get_wtime();
	
	printf("Sum of the array = %d in %f ms!\n",sum, (end_time-start_time)*1000);
	
	free(arr);				//housekeeping!
    
   	return 0;
}




