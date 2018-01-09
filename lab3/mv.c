#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_SIZE 1000
#define MAX_FILE_LENGTH 255

void extract_filename(char path[], char filename[]) 
{
    int len = strlen(path);
    int pointer = 0;

    for (int i = 0; i < len; i++) {
        if (path[i] == '/') {
            pointer = 0;
        } else {
            filename[pointer++] = path[i];
        }
    }
    filename[pointer] = '\0';
}

// If path is absolute, don't prepend current directory
void check_absolute(char cwd[], char path[]) 
{
        if (path[0] == '/') {
            strcpy(cwd, path);
        } else {
            strcat(cwd, path);
        }
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage mv path1 path2\n");
    } else {
        char old[MAX_PATH_SIZE];
        char new[MAX_PATH_SIZE];

        getcwd(old, sizeof(old));
        getcwd(new, sizeof(new));

        strcat(old, "/");
        strcat(new, "/");

        check_absolute(old, argv[1]);
        check_absolute(new, argv[2]);

        // If destination is directory, add file to the path
        if (opendir(new) != NULL) {
            char filename[MAX_FILE_LENGTH];
            extract_filename(old, filename);
            int new_len = strlen(new);

            // If slash if not present at the end, append it
            if (new[new_len] != '/') {
                strcat(new, "/");
            }
            strcat(new, filename);
        }

        // System call to perform rename operation
        rename(old, new);
    }
    return 0;
}
