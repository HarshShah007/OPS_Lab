#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) 
{
	pid_t pid = fork();
	if (pid == 0) {
		printf("I am a child\n");
	} else {
		printf("I am parent\n");
	}
	return 0;
}
