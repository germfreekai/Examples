#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
	int a;
	int b;
}Number;

void swapArgs(int* a,int* b);

int main(int argc, char* argv[argc+1])
{

	assert(argc > 2);

	Number* n = (Number*)malloc(sizeof(Number));

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	n->a = a;
	n->b = b;

	printf("En struct: A -> %d / B -> %d\n",n->a,n->b);

	printf("A: %d\nB: %d\n", a, b);

	swapArgs(&a,&b);

	printf("A: %d\nB: %d\n", a, b);
	
	free(n);

	return EXIT_SUCCESS;

}

void swapArgs(int* a,int* b)
{

	printf("--> %p\n", &a);
	printf("--> %p\n", a);

	int temp = *a;
	*a = *b;
	*b = temp;

}

