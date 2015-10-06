#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("in.txt","r+");
	int n = 0;
	int a;
	int i = 0;
	while ((a = fgetc(fp)) != EOF) {
		n++;
		if(n % 5 != 0) {
			fseek(fp,i,SEEK_SET);
			fputc(a,fp);
			i++;
			fseek(fp,n,SEEK_SET);
		}
	}
	truncate("in.txt",i);
	fclose(fp);
	return 0;
}

