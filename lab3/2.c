#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void filecopy(int fpd, int opd);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Invalid arguments\n");
	} else {
		int i;
		int ipd = open(argv[1], O_RDONLY);
		for (i = 2; i < argc; ++i) {
			open(argv[i], O_CREAT, 00600);
			int opd = open(argv[i], O_WRONLY);
			filecopy(ipd, opd);
			close(opd);
		}
		close(ipd);
	}
	return 0;
}

void filecopy(int ipd, int opd)
{
	char buffer[512];
	ssize_t c;
	while ((c = read(ipd, buffer, sizeof(buffer))) != 0) {
		write(opd, buffer, c);
	}
}

