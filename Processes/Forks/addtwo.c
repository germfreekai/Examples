#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[argc + 1])
{

	if(argc < 3)
	{
		perror("Wrong number of arguments\n"); 
		
		exit(EXIT_FAILURE); 
	}
	else
	{

		printf("%d || %d\n", atoi(argv[1]), atoi(argv[2]));
		printf("Sum: %d\n", atoi(argv[1]) + atoi(argv[2]));

		return EXIT_SUCCESS;

	}

}
