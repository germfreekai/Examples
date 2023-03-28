#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* printMessage(void* ptr); 

int main(void)
{

	pthread_t tid1;
	pthread_t tid2;

	char* msg1 = "Thread 1";
	char* msg2 = "Thread 2"; 

	int tret1; 
	int tret2;

	// Threas &-> envs, function, arguments
	tret1 = pthread_create(&tid1, NULL, printMessage, (void*)msg1);
	tret2 = pthread_create(&tid2, NULL, printMessage, (void*)msg2);

	// Now wait for them to finish before keep going with main
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL); 

	printf("Thread 1 returns: %d\n", tret1);
	printf("Thread 2 returns: %d\n", tret2);

	return EXIT_SUCCESS;

}

void* printMessage(void* ptr)
{

	char* msg = (char*)ptr;

	printf("From: %s\n", msg);

}
