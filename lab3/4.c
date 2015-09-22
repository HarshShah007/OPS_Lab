#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

void reverse(char s[], int length);
void copy(int ifd, int ofd);

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Invalid arguments\n");
	} else {
		int i;
		int ifd = open(argv[1], O_RDONLY);
		for (i = 2; i < argc; ++i) {
			int ofd = open(argv[i], O_WRONLY);
			copy(ifd, ofd);
			close(ofd);
		}
		close(ifd);
	}
	return 0;
}

void copy(int ifd, int ofd)
{
	char buffer[512];
	ssize_t c;
	while ((c = read(ifd, buffer, sizeof(buffer))) != 0) {
		reverse(buffer, c);
		write(ofd, buffer, c);
	}
}

void reverse(char s[], int length) 
{
	int i;
	char reverse[length];
	for (i = 0; i < length; ++i) {
		reverse[i] = s[length - i - 1];
	}
	for (i = 0; i < length; ++i) {
		s[i] = reverse[i];
	}
}
