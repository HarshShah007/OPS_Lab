#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) 
{
    char currentDir[1024];
    if (argc == 1) {
        getcwd(currentDir, sizeof(currentDir));
    } else {
        strcpy(currentDir, argv[1]);
    }
    DIR *directory = opendir(currentDir);
    if (directory == NULL) {
        fprintf(stderr, "No such directory: %s\n", currentDir);
    } else {
        struct dirent *dr;
        while ((dr = readdir(directory)) != NULL) {
            if (dr -> d_name[0] != '.') {
                printf("%s\n", dr -> d_name);
            }
        }
    }
    return 0;
}

