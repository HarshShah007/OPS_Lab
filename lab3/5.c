#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

void remove_dir(char name[]);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Invalid arguments\n");
	} else {
		int i;
		for (i = 1; i < argc; ++i) {
			remove_dir(argv[i]);
		}
	}
	return 0;
}

void remove_dir(char path[]) 
{
	DIR *dp = opendir(path);
	struct dirent *file;
	while ((file = readdir(dp)) != NULL) {

		if (strcmp(file -> d_name, ".") == 0) {
			continue;
		}

		if (strcmp(file -> d_name, "..") == 0) {
			continue;
		}
		
		char newPath[512];
		strcpy(newPath, path);
		strcat(newPath, file -> d_name);
		
		if (file -> d_type == DT_DIR) {
			remove_dir(newPath);
		} else {
			unlink(newPath);
		}
	}
	remove(path);	
}
