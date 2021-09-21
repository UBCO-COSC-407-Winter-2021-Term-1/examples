#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* say_something(void *prt);

int main()
{
	pthread_t thread_1, thread_2;

	char *msg1 = "Hello ";
	char *msg2 = "World!";

	pthread_create( &thread_1, NULL, say_something, msg1);
	pthread_create( &thread_2, NULL, say_something, msg2);
	printf("Done!");
	fflush(stdout);
	exit(0);
}

void* say_something(void *ptr)
{
	printf("%s ", (char*)ptr);
	return NULL;
}
