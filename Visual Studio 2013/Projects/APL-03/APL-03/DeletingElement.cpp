//Problem-02

#include<stdio.h>
const int SIZE = 100;

void Del_Element(char str[],int del);
void main2()
{
	char str[SIZE];
	int del;
	puts("Enter string:");
	gets_s(str);
	puts("Enter a index to delete:");
	scanf_s("%d", &del);

	Del_Element(str,del);
	
	puts(str);
}
void Del_Element(char str[],int del)
{
	int len = 0;
	while (str[len] != NULL)
		len++;

	for (int i = del; i < len; i++)
	{
		str[i] = str[i + 1];
	}
}