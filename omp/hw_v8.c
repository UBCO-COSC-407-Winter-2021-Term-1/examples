#include <stdio.h>
#include <omp.h>

int main()
{
	printf("Hello sequential!\n");

#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num();

		printf("T%d:A \n", omp_get_thread_num());
		printf("T%d:B \n", omp_get_thread_num());

		if(id == 2)
		   printf("T2:special task\n");
	}
	printf("End");
	return 0;
}
