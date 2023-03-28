#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int n;
	n = 5;

	int *p;
	p = &n;

	printf("We have variable < N > and pointer < *p > \n"); 

	printf("=== For N === \n"); 
	printf("N value: %d\n", n); 
	printf("N memory address: %p\n", &n); 

	printf("=== For P === \n");
	printf("P points tu value: %d\n", *p); 
	printf("P points tu adress: %p\n", p);
	printf("P memory address: %p\n", &p); 

	return EXIT_SUCCESS; 

}
