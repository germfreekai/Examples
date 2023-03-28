#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myThread(void *vargp); 

int main(void)
{

	pthread_t thread_id;

	printf("Before thread\n");

	pthread_create(&thread_id, NULL, myThread, NULL);
	pthread_join(thread_id, NULL);

	printf("After thread\n");

	return EXIT_SUCCESS;

}

void* myThread(void* vargp)
{

	sleep(1);

	printf("Hello from Thread\n"); 

	return NULL;

}


