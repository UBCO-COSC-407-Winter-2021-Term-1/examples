#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* say_something(void *ptr)
{
	printf("%s ", (char*)ptr);
	return NULL;
};

int main()
{
	pthread_t thread_1, thread_2;

	char *msg1 = "Hello ";
	char *msg2 = "World!";

	pthread_create( &thread_1, NULL, say_something, msg1);
	pthread_create( &thread_2, NULL, say_something, msg2);

	pthread_join(thread_2, NULL);
	pthread_join(thread_1, NULL);

	printf("Done!");
	fflush(stdout);
	exit(0);
}

