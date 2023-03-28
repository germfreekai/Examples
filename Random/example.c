#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
	char str[5];

	printf("Name : "); 
	scanf("%5s", str); 

	printf("Hello %s\n", str); 

	return EXIT_SUCCESS; 

}
