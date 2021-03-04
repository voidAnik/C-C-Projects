#include <stdio.h>

#define MAXCHAR 1000
int main476576() {
	FILE *fp;
	char str[MAXCHAR];
	char* filename = "reading.txt";

	fopen_s(&fp,filename, "r");
	if (fp == NULL){
		printf("Could not open file %s", filename);
		return 1;
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		printf("%s", str);
	}
	fclose(fp);
	return 0;
}