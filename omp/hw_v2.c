#include <stdio.h>
#include <omp.h>

int main()
{
	printf("Hello sequential!\n");
#pragma omp parallel
	printf("Hello parallel!\n");

   return 0;
}
