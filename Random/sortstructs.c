#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char *name; 
}User;

User **get_array(int size); 
void sort_array(int size, User **users); 
void print_users(int size, User **users, char *str); 
void get_user(int size, User **users); 
void free_arr(int size, User **users); 
void swap_structs(User *a, User *b); 

int main(void)
{
	int size; 
	printf("> Number of users > "); 
	scanf("%d", &size); 

	User **users = get_array(size); 

	print_users(size, users, "Unsorted"); 

	sort_array(size, users);
	
	print_users(size, users, "Sorted"); 
	
	get_user(size, users); 

	free_arr(size, users); 

	return EXIT_SUCCESS;
}

User **get_array(int size)
{
	User **users = (User**)calloc(size, sizeof(User*)); 

	for (size_t i = 0; i < size; i++)
	{
		users[i] = (User*)malloc(sizeof(User)); 
		users[i]->name = (char*)calloc(30,sizeof(char)); 
		
		printf("> User id: "); 
		scanf("%d", &users[i]->id); 
		getchar();
		printf("> User name: "); 
		scanf("%[^\n]", users[i]->name); 
	}

	return users; 
}

void sort_array(int size, User **users)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size; j++)
		{
			if (users[i]->id > users[j]->id)
				swap_structs(users[i], users[j]); 
		}
	}
}

void print_users(int size, User **users, char *str)
{
	printf("Print %s struct array\n", str); 
	for (size_t i = 0; i < size; i++)
		printf("> User ID: %d || User name: %s\n", users[i]->id, users[i]->name); 
}

void get_user(int size, User **users)
{
	int id; 
	int c; 
	c = 0; 

	printf("Search for user...\n"); 
	printf("> User ID: "); 
	scanf("%d", &id); 

	for (size_t i = 0; i < size; i++)
	{
		if (users[i]->id == id)
		{
			printf("> USER FOUND!\nUser ID: %d || User name: %s\n", users[i]->id, users[i]->name); 
			c++;
		}
	}

	if (!c)
	{
		printf("No users where found with ID: %d\n", id); 
	}
}

void free_arr(int size, User **users)
{
	for (size_t i = 0; i < size; i++)
	{
		free(users[i]->name); 
		free(users[i]);
	}
	
	free(users); 
}

void swap_structs(User *a, User *b)
{
	User *temp = (User*)malloc(sizeof(User)); 
	*temp = *a; 
	*a = *b;
	*b = *temp; 

	free(temp); 
}

