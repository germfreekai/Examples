#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Sort(int *arr, int size); 
int* GetArr(int size); 
void PrintArr(int *arr, int size); 

int main(int argc, char* argv[argc + 1])
{

	assert(argc == 2); 

	int size = atoi(argv[1]); 

	int* arr = GetArr(size); 

	printf("[-] Before \n"); 
	PrintArr(arr, size); 
	Sort(arr, size); 
	printf("[+] After \n"); 
	PrintArr(arr, size); 

	free(arr); 

	return EXIT_SUCCESS; 

}

int* GetArr(int size)
{

	int *arr = (int*)calloc(size, sizeof(int)); 

	for(size_t i = 0; i < size; i++)
	{
		printf("arr[%zu] = ", i); 
		scanf("%d", &arr[i]); 
	}

	return arr; 
}

void PrintArr(int *arr, int size)
{
	for(size_t i = 0; i < size; i++)
		printf("[+] arr[%zu] = %d\n", i, arr[i]); 
}

void Sort(int *arr, int size) 
{
	int temp; 
	temp = 0; 

	for(size_t i = 0; i < size; i++)
	{
		for(size_t j = i; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp; 
			}
		}
	}
}


