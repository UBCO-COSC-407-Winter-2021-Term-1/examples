#include <stdio.h>
#include <omp.h>

int main()
{
	printf("Hello sequential!\n");

#pragma omp parallel num_threads(4)
	{
		printf("T%d:A \n", omp_get_thread_num());
		printf("T%d:B \n", omp_get_thread_num());

	}

	printf("T%d:Done \n", omp_get_thread_num());

	return 0;
}
