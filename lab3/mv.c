#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Invalid arguments\n");
	} else {
		char old[100];
		char new[100];
		getcwd(old, sizeof(old));
		getcwd(new, sizeof(new));

		strcat(old, "/");
		strcat(new, "/");

		strcat(old, argv[1]);
		strcat(new, argv[2]);

		rename(old, new);
	}
	return 0;
}
