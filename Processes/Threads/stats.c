#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

void* average(void* vargs); 
void* maximum(void* vargs); 
void* minimum(void* vargs); 

double avg;
int max;
int min;

typedef struct
{

	size_t len;
	int* data;

}intArr;

int main(int argc, char* argv[argc+1])
{

	assert(argc >= 3);

	pthread_t avg_t;
	pthread_t max_t;
	pthread_t min_t;

	// Inicializamos struct
	intArr* nargs = (intArr*)malloc(sizeof(intArr));
	nargs->data = (int*)calloc(argc-1,sizeof(int));
	nargs->len = argc-1;

	for(size_t i = 1; i < argc; i++)
	{

		nargs->data[i-1] = 0;
		nargs->data[i-1] = atoi(argv[i]);
	
	}

	// Creamos threads
	pthread_create(&avg_t, NULL, average, (void*)nargs);
	pthread_join(avg_t, NULL);
	printf("The avg is: %.3lf\n", avg);

	pthread_create(&max_t, NULL, maximum, (void*)nargs);
	pthread_join(max_t, NULL);
	printf("The max is: %d\n", max);

	pthread_create(&min_t, NULL, minimum, (void*)nargs);
	pthread_join(min_t, NULL);
	printf("The min is: %d\n", min); 

	free(nargs->data);
	free(nargs);

	return EXIT_SUCCESS;

}

void* average(void* vargs)
{

	intArr* nargs = (intArr*)vargs;

	avg = 0.0; 

	for(size_t i = 0; i < nargs->len; i++)
	{

		avg += (double)nargs->data[i];
	
	}
	
	avg /= nargs->len;

	return NULL; 

}

void* maximum(void* vargs)
{

	intArr* nargs = (intArr*)vargs;

	max = nargs->data[0];

	for(size_t i = 1; i < nargs->len; i++)
	{

		if(nargs->data[i] > max)
		{

			max = nargs->data[i];

		}

	}

	return NULL;

}

void* minimum(void* vargs)
{

	intArr* nargs = (intArr*)vargs;

	min = nargs->data[0];

	for(size_t i = 1; i < nargs->len; i++)
	{

		if(nargs->data[i] < min)
		{

			min = nargs->data[i];

		}

	}

	return NULL;

}
