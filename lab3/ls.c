#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) 
{
	char currentDir[100];
	if (argc == 1) {
		getcwd(currentDir, sizeof(currentDir));
	} else {
		strcpy(currentDir, argv[1]);
	}
	DIR *directory = opendir(currentDir);
	struct dirent *dr;
	while ((dr = readdir(directory)) != NULL) {
		if (dr -> d_name[0] != '.') {
			printf("%s\t", dr -> d_name);
		}
	}
	printf("\n");
	return 0;
}

