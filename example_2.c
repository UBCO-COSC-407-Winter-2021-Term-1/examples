#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 #include <unistd.h>

void* say_something(void *ptr)
{
	printf("%s ", (char*)ptr);
	return NULL;
}

int main()
{
	pthread_t thread_1, thread_2;

	char *msg1 = "Hello ";
	char *msg2 = "World!";

	pthread_create( &thread_1, NULL, say_something, msg1);
	sleep(1);

	pthread_create( &thread_2, NULL, say_something, msg2);
	sleep(1);

	printf("Done!");
	fflush(stdout);
	exit(0);

}

