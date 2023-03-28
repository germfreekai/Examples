#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void setArr(char** array_str); 
void fillArr(char** array_str); 
void printArr(char** array_str); 

int main(void)
{

	char** array_str = (char**)calloc(4,sizeof(char*));

	//setArr(array_str);

	fillArr(array_str); 

	printArr(array_str); 

	free(array_str); 
	return EXIT_SUCCESS; 

}

void setArr(char** array_str)
{

	for(size_t i = 0; i < 4; i++)
	{

		array_str[i] = (char*)calloc(4, sizeof(char));

	}

}

void fillArr(char** array_str)
{

	array_str[0] = "Rene";
	array_str[1] = "rEne";
	array_str[2] = "reNe";
	array_str[3] = "renE";

}

void printArr(char** array_str)
{

	for(size_t i = 0; i < 4; i++)
	{

		printf("\r%s", array_str[i]);
		fflush(stdout); 
		usleep(100000); 

	}

	printf("\n"); 

}
