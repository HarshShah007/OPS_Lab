#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void filecopy(int ifd, int ofd);

int BUFFER_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        //No arguments, which means take input from stdin
        filecopy(STDIN_FILENO, STDOUT_FILENO);
    } else {
        int i;
        for (i = 1; i < argc; ++i) {
            int ifd = open(argv[i], O_RDONLY);
            if (ifd == -1) {
                fprintf(stderr, "Can't open %s\n", argv[i]);
            } else {                
                filecopy(ifd, STDOUT_FILENO);
                close(ifd);
            }
        }
    }
    return 0;
}

void filecopy(int ifd, int ofd)
{
    char buffer[BUFFER_SIZE];
    ssize_t c;
    while ((c = read(ifd, buffer, BUFFER_SIZE)) != 0) {
        write(ofd, buffer, c);
    }
}
