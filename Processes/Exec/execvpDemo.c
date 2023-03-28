#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	// Null terminated array of chars
	char* args[] = {"./exec",NULL};

	// Llmamaos el proceso a invocar y el arreglo
	execvp(args[0],args);

	// Everything is ignonred after EXECVP()
	// as this process is replaced by another one
	
	printf("ending--------\n");

	return EXIT_SUCCESS;

}
