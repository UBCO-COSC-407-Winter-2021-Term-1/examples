#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//get a lock
pthread_mutex_t lock;

void* say_something(void *ptr)
{
	pthread_mutex_lock(&lock);		//this now becomes critical section! - spinlock....
	printf("%s ", (char*)ptr);
	pthread_mutex_unlock(&lock);
	pthread_exit(0);
}


int main()
{
	pthread_t thread_1, thread_2;

	char *msg1 = "Hello ";
	char *msg2 = "World!";

	//create the lock -> error checking?
	pthread_mutex_init(&lock, NULL);

	pthread_create( &thread_1, NULL, say_something, msg1);
	pthread_create( &thread_2, NULL, say_something, msg2);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	printf("Done!");
	fflush(stdout);

    pthread_mutex_destroy(&lock);
	exit(0);
}




