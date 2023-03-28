#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void INThandler(int sig);

int main(void)
{
	signal(SIGINT, INThandler);

	while(1)
	{
		pause();
	}

	return EXIT_SUCCESS;
}

void INThandler(int sig)
{
	char c; 

	signal(sig, SIG_IGN);

	printf("You won´t leave\n");

	signal(SIGINT, INThandler);
}
