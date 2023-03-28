#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	srand( time(NULL) ); 

	int *arr = (int*)calloc(5, sizeof(int)); 

	for(size_t i = 0; i < 5; i++)
		arr[i] = rand() % 10 + 1; 

	for(size_t i = 0; i < 5; i++)
		printf("arr[%zu] value: %d || memory address: %p\n", i, arr[i], &arr[i]);  

	free(arr); 

	return EXIT_SUCCESS;
}
