
#include <stdio.h>
void main3() {

	char str[100];
	int n = 0, vowel = 0, cons = 0;
	printf("Enter a string: ");
	gets_s(str);
	while (str[n] != NULL)
		n++;

	for (int i = 0; i < n; i++) {

		if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u') || (str[i] == 'A') 
			|| (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U')) 
		{
			printf("Vowel: %c\n", str[i]);
			vowel++;
		}
		else {
			printf("Consonant: %c\n", str[i]);
			cons++;
		}

	}
	printf("Here is %d vowels & %d consonant!!\n\n", vowel, cons);
}
