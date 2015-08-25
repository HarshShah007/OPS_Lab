#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) 
{
	int x = 0;
	fork();
	fork();
	printf("Value is %d, address is %p\n", x, &x);
	return 0;
}
