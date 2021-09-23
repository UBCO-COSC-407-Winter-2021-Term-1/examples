#include <stdio.h>
#include <omp.h>

int main()
{
	printf("Hello sequential!\n");
#pragma omp parallel
	{
		int my_id = omp_get_thread_num();
		int tot = omp_get_num_threads();
		printf("Hello World from thread %d/%d\n", my_id, tot);
	}
	return 0;
}
