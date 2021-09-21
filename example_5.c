/*
 * Conditions and locks
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <string.h>


//get a lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;


void* say_something(void *prt);


int main()
{
	pthread_t thread_1, thread_2;

	char *msg1 = "Hello ";
	char *msg2 = "World!";

	//create the lock -> error checking?
	pthread_mutex_init(&lock, NULL);

	pthread_create( &thread_1, NULL, say_something, msg1);
	pthread_create( &thread_2, NULL, say_something, msg2);

	//while this happily waits, there is no control over who finishes first!
	//How can we sync this so that it works properly??
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	printf("Done!");
	fflush(stdout);

    pthread_mutex_destroy(&lock);
	exit(0);
}

void* say_something(void *ptr)
{
	pthread_mutex_lock(&lock);		//this now becomes critical section!

	//check on some condition - if it is hello, wait for world....
	if (strcmp("Hello ",(char*)ptr) == 0)
	{
        printf("Waiting on condition variable cond1\n");
		pthread_cond_wait(&cond1, &lock);
	}
	else
	{
		 printf("Signaling condition variable cond1\n");
		 pthread_cond_signal(&cond1);
	}
    printf("%s ", (char*)ptr);
	pthread_mutex_unlock(&lock);
	pthread_exit(0);
}



