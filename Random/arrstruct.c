#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
	int id;
	char* name;
}Student;

void setArrStruct(Student** studentArr);
void setStruct(Student* student);
void freeStruct(Student** studentArr); 

int main(void)
{

	// Arreglo de students
	Student** studentArr = (Student**)calloc(5,sizeof(Student*));

	setArrStruct(studentArr);

	for(size_t i = 0; i < 5; i++)
	{

		printf("Student name: %s || Student id: %d\n", studentArr[i]->name, studentArr[i]->id); 

	}

	freeStruct(studentArr); 

	return EXIT_SUCCESS;

}

void freeStruct(Student** studentArr)
{

	for(size_t i = 0; i < 5; i++)
	{

		free(studentArr[i]->name);
		free(studentArr[i]); 

	}

	free(studentArr); 

}

void setArrStruct(Student** studentArr)
{

	for(size_t i = 0; i < 5; i++)
	{

		studentArr[i] = (Student*)malloc(sizeof(Student));
		studentArr[i]->name = (char*)calloc(30,sizeof(char));

		setStruct(studentArr[i]); 
	
	}

}

void setStruct(Student* student)
{

	student->id = 0; 

	printf("Give me student's name: "); 
	scanf("%[^\n]", student->name); 
	
	printf("Give me student's id: "); 
	scanf("%d", &student->id); 

	getchar();

}
