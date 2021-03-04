
#include<stdio.h>
#include<string.h>
void main123455()
{
	char str1[100]="I love you", str2[100]="I";
	/*if (strstr(str1, str2) <= 0)
	{
		puts("x");
	}*/
	if (strstr(str1, str2) == 0)
	{
		puts("y");
	}
	if (strstr(str1, str2) >= 0)
	{
		puts("z");
	}
}