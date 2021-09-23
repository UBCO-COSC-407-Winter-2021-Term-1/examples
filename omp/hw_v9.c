#include <stdio.h>
#include <omp.h>

int list[6] = {0,1,2,3,4,5};

int main()
{
	printf("Hello sequential!\n");

#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num();
		int my_a = id * 3;
		int my_b = id * 3 + 3;
		printf("T%d will process indexes %d to %d\n",id,my_a,my_b-1);
		for (int i = my_a; i < my_b; i++)
			printf("T%d:processing list[%d]\n",id,i);

	}
	printf("End");
	return 0;
}
