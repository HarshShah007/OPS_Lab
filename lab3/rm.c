#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1000
#define MAX_FILENAME_LENGTH 255

void remove_dir(char name[]);
void check_absolute(char path[]);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage rm path...\n");
    } else {
        for (int i = 1; i < argc; ++i) {
            check_absolute(argv[i]);
            
            if (opendir(argv[i]) == NULL) {
                unlink(argv[i]);
            } else {
                remove_dir(argv[i]);
            }
        }
    }
    return 0;
}

void remove_dir(char path[]) 
{
    if (path[strlen(path) - 1] != '/') {
        strcat(path, "/");
    }
    DIR *dp = opendir(path);
    if (dp == NULL) {
        fprintf(stderr, "Invalid directory: %s\n", path);
        return;
    }
    struct dirent *file;
    while ((file = readdir(dp)) != NULL) {

        if (strcmp(file -> d_name, ".") == 0) {
            continue;
        }

        if (strcmp(file -> d_name, "..") == 0) {
            continue;
        }

        char newPath[MAX_PATH_LENGTH];
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

// Checks if the given path is absolute, prepend cwd if its not
void check_absolute(char path[]) 
{
    if (path[0] != '/') {
        char cwd[MAX_FILENAME_LENGTH];
        getcwd(cwd, sizeof(cwd));
        strcat(cwd, "/");
        strcat(cwd, path);
        strcpy(path, cwd);
    }
}

