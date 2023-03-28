#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char** strArr = (char**)calloc(4, sizeof(char*));

	for(size_t i = 0 ; i < 4 ; i++)
	{

		strArr[i] = (char*)calloc(10,sizeof(char));
		printf("Give me a str: "); 
		scanf("%[^\n]", strArr[i]);
		getchar(); 
	}

	printf("Let me give them back: \n"); 

	printf("Memory address form strArr: %p\n", &strArr); 

	for(size_t i = 0 ; i < 4 ; i++)
	{

		printf("%zu : %s || MemoryAdrr: %p\n", 
				i, 
				strArr[i], 
				&strArr[i]);

	}

	for(size_t i = 0; i < 4 ; i++)
	{

		free(strArr[i]); 

	}

	free(strArr); 

	return EXIT_SUCCESS; 

}
