#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{

	pid_t pid;

	printf("Just before 'execv()'\n");

	pid = fork();

	if(pid == -1)
	{
		perror("Couldn't fork\n"); 
		exit(2); 
	}
	else if(pid == 0)
	{

		char* argv[] = {"./hello", "mnt/d", NULL}; 

		printf("Child pid: %u\n", getpid());	
		printf("Parent pid: %u\n", getppid());

		if(execv(argv[0], argv) == -1)
		{
			printf("Smth went wrong || Error %d\n", errno); 
			exit(EXIT_FAILURE); 
		}
		
		printf("Success on parent\n"); 

		exit(EXIT_SUCCESS);
	}
	else
	{

		wait(NULL); 

		printf("Parent: \n"); 

		printf("Parent pid: %u\n", getpid());	
		printf("Parent parent pid: %u\n", getppid());
		
		printf("Sucess\n"); 
	}

	return EXIT_SUCCESS;

}
