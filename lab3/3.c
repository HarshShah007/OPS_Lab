#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("Invalid arguments\n");
	} else {
		int ifd = open(argv[1], O_RDONLY);
		size_t size = lseek(ifd, (size_t)0, SEEK_END);
		close(ifd);
		printf("Size is %d\n", size);
	}
	return 0;
}
