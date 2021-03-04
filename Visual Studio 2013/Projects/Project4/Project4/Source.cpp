#include<stdio.h>
#include<string.h>
void main54654()
{
	char str1[100] = { "Bangladesh" };
	char str2[100] = { "YEAR" };
	int index = 2, j = 0;
	int k = index;
	for (int j = 0; j < strlen(str2); j++)
	{
		for (int i = strlen(str1); i >= index; i--)
		{
			str1[i + 1] = str1[i];
		}
	}
	for (int j = 0; j < strlen(str2); j++)
	{
		str1[k] = str2[j];
			k++;
	}
	puts(str1);
}