
/*C program to count total number of words in a string
*/

#include <stdio.h>

#define MAX_SIZE 100 //Maximum size of the string

void main3()
{
	char string[MAX_SIZE];
	char prevChar;
	int i, words;

//Reads a string from user
	printf("Enter any string: ");
	gets_s(string);

	i = 0;
	words = 0;
	prevChar = '\n'; // The previous character of string[0] is null

	/* Runs loop infinite times */
	while (1)
	{
		if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t' || string[i] == '\0')
		{
			/**
			* It is a word if current character is whitespace and
			* previous character is non-white space.
			*/
			if (prevChar != ' ' && prevChar != '\n' && prevChar != '\t' && prevChar != '\0')
			{
				words++;
			}
		}

		/* Make the current character as previous character */
		prevChar = string[i];

		/*
		* If current character is null then terminate else move to next character
		*/
		if (string[i] == '\0')
		{
			break;
		}
		else
		{
			i++;
		}
	}

	printf("Total number of words = %d\n", words);
}
