#include <stdio.h>
#include <omp.h>

int main()
{
	printf("Hello sequential!\n");
#pragma omp parallel
	{
		int my_id = omp_get_thread_num();
		printf("Hello World from thread %d\n", my_id);
	}
	return 0;
}
