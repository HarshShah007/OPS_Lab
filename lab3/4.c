#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

void reverse(char s[], int length);
void copy(int ifd, int ofd);
void strcat_modified(char one[], char two[], int length);

char all_characters[100000] = "";

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
		strcat_modified(all_characters, buffer, c);	
	}
	reverse(all_characters, strlen(all_characters));
	write(ofd, all_characters, strlen(all_characters));
}

void reverse(char s[], int length) 
{
	int i;
	int j;
	i = 0;
	j = length - 1;
	while (i < j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

void strcat_modified(char one[], char two[], int length) 
{
	int i = strlen(one);
	int j = 0;
	while (j < length) {
		one[i] = two[j];
		i++;
		j++;
	}
	one[i] = '\0';
}

