#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void filecopy(int ipd, int opd);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Invalid arguments\n");
	} else {
		int i;
		for (i = 1; i < argc; ++i) {
			int ipd = open(argv[i], O_RDONLY);
			open("_temp", O_CREAT, 00600);
			int opd = open("_temp", O_WRONLY);
			filecopy(ipd, opd);
			close(ipd);
			close(opd);
			rename("_temp", argv[i]);
		}
	}
	return 0;
}

void filecopy(int ipd, int opd)
{
	char buffer[5];
	ssize_t c;
	while ((c = read(ipd, buffer, sizeof(buffer))) != 0) {
		write(opd, buffer, c - 1);
	}
}
