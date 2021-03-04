	//Problem-03
//Right rotation

#include<stdio.h>
const int SIZE = 100;

void cycleOne(char str[]);
void main3()
{	
	char str[SIZE];
	int l;
	puts("Enter a word:");
	gets_s(str);
	puts("Enter the length to cycle:");
	scanf_s("%d", &l);
	for (int i = 0; i < l; i++)
	{
		cycleOne(str);
	}
	puts(str);
}
void cycleOne(char str[])
{
	int length = 0;
	while (str[length] != NULL)
		length++;
	char last_ch = str[length - 1];
	for (int i = length - 1; i > 0; i--)
	{
		str[i] = str[i - 1];
	}
	str[0] = last_ch;
}