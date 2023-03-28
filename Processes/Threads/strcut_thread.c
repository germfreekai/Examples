#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

typedef struct
{

	int id;  
	char* name; 

}Person; 

void* printPerson(void* arg); 

int main(int argc, char* argv[argc+1])
{

	Person* person = (Person*)malloc(sizeof(Person)); 

	person->name = (char*)calloc(20,sizeof(char));
	person->id = 0; 

	printf("Give me the name: "); 
	scanf("%[^\n]", person->name); 

	getchar(); 

	printf("Give me the id: "); 
	scanf("%d", &person->id); 

	//person->name = argv[1];
	//person->id = atoi(argv[2]); 

	pthread_t pt1; 

	pthread_create(&pt1, NULL, printPerson, (void*)person); 
	pthread_join(pt1, NULL); 

	//printPerson((void*)person); 

	free(person->name); 
	free(person); 

	return EXIT_SUCCESS;

}

void* printPerson(void* arg)
{

	Person* person = (Person*)arg; 

	printf("Name: %s || ID: %d\n", person->name, person->id);

	return NULL; 

}


