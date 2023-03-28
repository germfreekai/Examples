#include <stdio.h>
#include <stdlib.h>

int **setMatrix(int row, int col);
void printMatrix(int row, int col, int **m); 
int **sumMatrix(int row, int col, int **m1, int **m2);
void freeMatrix(int row, int col, int **m); 

int main(void)
{

	int row; 
	printf("> Rows size: "); 
	scanf("%d", &row); 
	int col; 
	printf("> Columns size: "); 
	scanf("%d", &col); 

	printf("=== Matrix 1 ===\n");
	int **m1 = setMatrix(row, col); 
	printf("================\n");

	printf("=== Matrix 2 ===\n");
	int **m2 = setMatrix(row, col); 
	printf("================\n"); 

	int **res = sumMatrix(row, col, m1, m2); 
	
	printf("=== Matrix 1 ===\n");
	printMatrix(row, col, m1);
	printf("================\n"); 
	printf("=== Matrix 2 ===\n");
	printMatrix(row, col, m2);
	printf("================\n"); 
	printf("===  Result  ===\n");
	printMatrix(row, col, res);
	printf("================\n"); 

	freeMatrix(row, col, m1); 
	freeMatrix(row, col, m2); 
	freeMatrix(row, col, res); 

	return EXIT_SUCCESS; 

}
int **setMatrix(int row, int col)
{
	int **m = (int**)calloc(row, sizeof(int*)); 

	for (size_t i = 0; i < row; i++)
		m[i] = (int*)calloc(col, sizeof(int)); 

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			printf("m[%zu]]%zu] > ", i, j);
			scanf("%d", &m[i][j]); 
		}
	}

	return m; 
}
void printMatrix(int row, int col, int **m)
{

	printf(" __%*c__\n", (col*4)-1, 32);

	int lsize; 
	lsize = ((col*4) + 4) - 6;

	for (size_t i = 0; i < row; i++)
	{
		if (i + 1 == row)
		{
			printf("|__");
		}
		else
		{
			printf("|%*c",2,32);
		}

		for (size_t j = 0; j < col; j++)
		{
			printf("%d", m[i][j]);
			if (j + 1 != col)
			{
				if (m[i][j] > 9)
				{
					printf("%*c",(lsize/col),32);
				}
				else
				{
					printf("%*c",(lsize/col)+2,32);
					
				}
			}
		}
		
		if (i + 1 == row)
		{
			printf("__|\n");
		}
		else
		{
			printf("%*c|\n",2,32);
		}
	}
	
}

int **sumMatrix(int row, int col, int **m1, int **m2)
{
	int **res = (int**)calloc(row, sizeof(int*));
	for (size_t i = 0; i < row; i++)
		res[i] = (int*)calloc(col, sizeof(int)); 

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
			res[i][j] = m1[i][j] + m2[i][j];
	}

	return res;
}
void freeMatrix(int row, int col, int **m)
{
	for (size_t i = 0; i < row; i++)
		free(m[i]);

	free(m); 
}
