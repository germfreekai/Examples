#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void forkExample();

int main(void)
{

	forkExample();

	return EXIT_SUCCESS;

}

void forkExample()
{

	if(fork() == 0)
	{

		printf("Hello from Child\n"); 
	
	}
	else
	{

		printf("Hello from Parent\n"); 

	}

}
