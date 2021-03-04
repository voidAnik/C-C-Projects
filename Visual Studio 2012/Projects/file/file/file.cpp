#include<stdio.h>
void main()
{
	FILE *fp;
	int c = 0;
	char str[100];
	fopen_s(&fp, "reading.txt", "r");
	while (!feof(fp))
	{
		fscanf_s(fp, "%s", str);
		puts(str);
	}
	fclose(fp);
}