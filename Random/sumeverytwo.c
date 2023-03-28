#include <stdio.h>
#include <stdlib.h>

int *SetArr(int len); 
void PrintArr(int len, int *arr); 
int *ResArr(int len, int *arr); 

int main(void)
{
	int len; 
	printf("> Len: "); 
	scanf("%d", &len); 

	if (len % 2 != 0)
	{
		printf("Not an even number\n"); 
		exit(1); 
	}

	int *arr = SetArr(len); 

	int *res = ResArr(len, arr); 
	PrintArr(len/2, res); 

	free(arr); 
	free(res); 

	return EXIT_SUCCESS;
}

int *SetArr(int len)
{
	int *arr = (int*)calloc(len,sizeof(int)); 

	for (size_t i = 0; i < len; i++)
	{
		printf("> arr[%zu] : ", i); 
		scanf("%d", &arr[i]);
	}

	return arr; 
}

void PrintArr(int len, int *arr)
{
	for (size_t i = 0; i < len; i++)
	{
		printf("arr[%zu] -> %d\n", i, arr[i]); 
	}
}	

int *ResArr(int len, int *arr)
{
	int *res = (int*)calloc(len/2,sizeof(int)); 

	int index = 0; 

	for (size_t i = 0; i < len; i = i + 2)
	{
		res[index] = arr[i] + arr[i+1];
		index++; 
	}

	return res; 
}
