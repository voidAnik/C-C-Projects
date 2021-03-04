#include<stdio.h>
#include<string.h>
void mai456n()
{
	char ch1[100] = { "nayan" };
	int count = 0, k;
	int m = strlen(ch1) - 1;
	int l = m;
	for (k = 0; k < m; k++)
	{
		if (ch1[k] == ch1[l])
		{
			count++;
		}
		l--;
	}
	if (count == m)
	{
		printf("PALINDROME\n");
	}
	else
		printf("Not\n");
}