
#include <stdio.h>
#include <string.h>
void main1() {

	int i;
	int j;
	int alphabets = 0;
	int digits = 0;
	int special = 0;
	char sentence[100];
	gets_s(sentence);
	int SIZE = strlen(sentence);

	for (i = 0; i < SIZE; i++) {

		if ((sentence[i] >= 'A') && (sentence[i] <= 'Z') || (sentence[i] >= 'a') && (sentence[i] <= 'z')) {

			alphabets++;
		}
		else if ((sentence[i] >= '0') && (sentence[i] <= '9')) {

			digits++;
		}
		else {
			special++;
		}
	}

	printf("Alphabets:%d\t", alphabets);
	printf("Digits:%d\t", digits);
	printf("Special characters:%d\t", special);
}
