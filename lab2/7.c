#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

pthread_t t1, t2;

void *function1(void *arg)
{
	printf("First thread\n");
	return NULL;
}

void *function2(void *arg) 
{
	printf("Second thread\n");
	return NULL;
}

int main(void)
{	
	int err1 = pthread_create(&t1, NULL, &function1, NULL);
	printf("Thread1 created\n");
	int err2 = pthread_create(&t2, NULL, &function2, NULL);
	printf("Thread2 created\n");
	return 0;
}

