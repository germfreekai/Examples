#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	int num = 10; 

	printf("Before fork num: %d || Mem addr: %p\n", num, &num); 

	if(fork() == 0)
	{

		num += 10; 

		printf("On Child num: %d || Mem addr: %p\n", num, &num); 

	}
	else 
	{

		num -= 5; 

		printf("On Parent num: %d || Mem addr: %p\n", num, &num); 

	}

	return EXIT_SUCCESS; 

}
