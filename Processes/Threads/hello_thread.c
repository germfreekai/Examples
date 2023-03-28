#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void* hola(void* arg);
void* mundo(void* arg); 

int main(int argc, char* argv[argc+1])
{

	pthread_t th1;
	//pthread_t th2;

	for(size_t i = 1; i < argc; i++)
	{

		pthread_create(&th1, NULL, hola, (void*)argv[i]); 
		pthread_join(th1, NULL); 

		printf(" "); 

	}

	// Creamos los threads
	//pthread_create(&th1, NULL, hola, (void*)argv[1]);
	//pthread_join(th1, NULL);  

	//printf(" "); 

	//pthread_create(&th2, NULL, hola, (void*)argv[2]); 
	//pthread_join(th2, NULL); 

	printf("\nSuccess\n"); 

	return EXIT_SUCCESS; 

}

void* hola(void* arg)
{

	char* msg = (char*)arg;

	for(size_t i = 0; i < strlen(msg); i++)
	{

		printf("%c", msg[i]);
		fflush(stdout);
		usleep(100000); 

	}

	return NULL; 

}
