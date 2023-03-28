#include <stdio.h>
#include <stdlib.h>

int *get_array(int size); 
void print_array(int size, int *arr, char *str); 
void sort_array(int size, int *arr); 
void swap_args(int *a, int *b); 

int main(void)
{
	int size; 
	printf("> size: "); 
	scanf("%d", &size); 

	int *arr = get_array(size); 

	print_array(size, arr, "Unsorted"); 

	sort_array(size, arr); 
	
	print_array(size, arr, "Sorted"); 
	free(arr); 

	return EXIT_SUCCESS; 
}

int *get_array(int size)
{
	int *arr = (int*)calloc(size, sizeof(int)); 

	for (size_t i = 0; i < size; i++)
	{
		printf("> arr[%zu]: ", i); 
		scanf("%d", &arr[i]); 
	}

	return arr; 
}

void print_array(int size, int *arr, char *str)
{
	printf("%s array\n", str); 
	for (size_t i = 0; i < size; i++)
		printf("arr[%zu] > %d\n", i, arr[i]);
}

void sort_array(int size, int *arr)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap_args(&arr[i], &arr[j]);
		}
	}
}

void swap_args(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}
