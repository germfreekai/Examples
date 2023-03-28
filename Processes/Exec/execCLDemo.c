#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	// Syntax almost the same
	// execlp -> reveives de file to execute, arr with arguments, Null terminated
	// execl -> PATH, argumentes, null terminated
	char* arg1[] = {"5", "4",NULL};
	char* arg2[] = {"3", NULL};

	execl("../Forks/addtwo", "4","5", NULL); 
	perror("EXEC failed\n"); 

	return EXIT_SUCCESS;

}
