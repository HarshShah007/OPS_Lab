#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void filecopy(int ifd, int ofd);

int main(int argc, char *argv[])
{
	if (argc == 1) {
		//No arguments, take from stdin
		filecopy(0, 1);
	} else {
		int i;
		for (i = 1; i < argc; ++i) {
			int ifd = open(argv[i], O_RDONLY);
			if (ifd == -1) {
				fprintf(stderr, "Can't open %s\n", argv[i]);
			} else {
				//1 is ofd of stdout
				filecopy(ifd, 1);
				close(ifd);
			}
		}
	}
	return 0;
}

void filecopy(int ifd, int ofd)
{
	char buffer[512];
	ssize_t c;
	while ((c = read(ifd, buffer, 512)) != 0) {
		write(ofd, buffer, c);
	}
}
