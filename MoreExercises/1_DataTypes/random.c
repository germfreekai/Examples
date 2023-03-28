#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	int n;
	int input;

	srand( time(NULL) ); 

	n = rand() % 10 + 1; 

	while(input != n)
	{
		printf("\rGive me a number:\n> ");
		scanf("%d", &input); 

		printf("%s\n", input == n ? "Corret! Congrats!" : "Wrong, you dumb bitch");

	}

	return EXIT_SUCCESS;

}
