#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc+1])
{

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	printf("%d", a + b);

	return EXIT_SUCCESS; 	

}
