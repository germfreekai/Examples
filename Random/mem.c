#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[argc+1])
{
	assert(argc > 1); 

	int num = atoi(argv[1]); 
	// El puntero apunto a una direccion de memoria
	int* pnum = &num; 

	printf("Var num = %d\n", num); 
	printf("Puntero a num -> pnum = %d\n", *pnum); 

	printf("Dirección de memoria de num: %p\n", &num); 
	printf("Dirección de memoria a la que apunta pnum: %p\n", pnum); 

	printf("Dirección de memoria del puntero pnum: %p\n", &pnum); 

	return EXIT_SUCCESS;

}	
