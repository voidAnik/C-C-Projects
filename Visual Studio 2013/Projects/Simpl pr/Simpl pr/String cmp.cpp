/*
C program to count total number of alphabets, digits and special characters in a string
*/

#include <stdio.h>
#include<ctype.h>
#define MAX_SIZE 100 //Maximum size of the string

void main2()
{
	char string[MAX_SIZE];
	int alphabets, digits, others, i;

	alphabets = digits = others = i = 0;


	/* Reads a string from user */
	printf("Enter any string : ");
	gets_s(string);

	/* Checks each character of string*/
	while (string[i] != '\0')
	{
		if (isalpha(string[i]))
		{
			alphabets++;
		}
		else if (isdigit(string[i]))
		{
			digits++;
		}
		else
		{
			others++;
		}

		i++;
	}

	printf("Alphabets = %d\n", alphabets);
	printf("Digits = %d\n", digits);
	printf("Special characters = %d\n", others);
}