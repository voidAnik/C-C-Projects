//Problem-01

#include<stdio.h>
const int SIZE = 100;

void Ascending(char str[]);
void main1()
{
	char str[SIZE];
	puts("Enter a string:");
	gets_s(str);
	puts("After ascending order:");
	Ascending(str);
	puts(str);
}
void Ascending(char str[])
{
	int len = 0;
	while (str[len] != NULL)
		len++;

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (str[j] < str[i])
			{
				char tempCh = str[j];
				str[j] = str[i];
				str[i] = tempCh;
			}
		}
	}
}