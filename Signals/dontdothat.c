#include "stdio.h"
#include "stdlib.h"
#include "signal.h"

void my_handler(int s){
	printf("Don't do that"); 

}


int main(int argc, char** argv){
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;

	sigaction(SIGINT, &sigIntHandler, NULL);

	pause();

	return 0;


}
