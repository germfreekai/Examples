#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char *path;

	path = getenv("PATH"); 

	if(!!path)
		printf("PATH: %s\n", path); 

	return EXIT_SUCCESS; 

}
