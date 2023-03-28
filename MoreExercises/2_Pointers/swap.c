#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b); 

int main(void)
{

	int x;
	int y;
	int *a;
	int *b;

	x = 5; 
	y = 10; 
	a = &x;
	b = &y; 

	printf("A: %d || B: %d\n", *a, *b);
	Swap(a,b);
	printf("A: %d || B: %d\n", *a, *b);

	return EXIT_SUCCESS; 
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
