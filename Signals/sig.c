#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int sig);

int main(void)
{
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);
	signal(SIGKILL, signalHandler);

	while(1)
	{
		pause();
	}

	return EXIT_SUCCESS;
}

void signalHandler(int sig)
{
	printf("%s", sig == 2 ? "Keyboard interruption\n" : sig == 15 ? "Termination Signal\n" : "Kill me?");

	printf("You wont't leave me\n");

}

