
#include<stdio.h>
#include<string.h>
void main654()
{
	char str1[100];
	char str2[100];
	int n = 3;
	gets_s(str1);
	gets_s(str2);
	strncat_s(str1, str2, n);
	puts(str1);
}