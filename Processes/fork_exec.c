#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{

	// Para guardar el pid
	pid_t pid;

	int ret = 1; 
	int status; 

	// Creamos el fork y almacenamos el PID
	// El fork hace una copia del proceso actual
	pid = fork();

	// If pid < 0, thre was a mistake
	if(pid == -1)
	{

		printf("Error when forking, quitting...\n"); 
		exit(EXIT_FAILURE); 

	}
	// Si regresa 0, es el pid del Hijo
	else if(pid == 0)
	{
		
		printf("Child process, pid = %u\n", getpid());

		printf("Parent of child process, pid = %u\n", getppid());

		char* args[] = {"./hello", "Rene", NULL}; 

		execv(args[0],args);

		exit(0);

	}
	// If pid is positive, it is parent's process
	else
	{

		printf("Parent process, pid = %u\n", getpid());

		printf("Parent's parent process, pid = %u\n", getppid());

		if(waitpid(pid, &status, 0) > 0)
		{

			printf("Successful run\n"); 

		}
		else
		{

			printf("Smth went wrong\n"); 
			exit(EXIT_FAILURE);

		}

	}

	return EXIT_SUCCESS;

}

