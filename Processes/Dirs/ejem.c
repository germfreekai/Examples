#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	char cwd[1000]; 

	getcwd(cwd, sizeof(cwd));

	printf("Current: %s\n", cwd); 

	return EXIT_SUCCESS; 

}
