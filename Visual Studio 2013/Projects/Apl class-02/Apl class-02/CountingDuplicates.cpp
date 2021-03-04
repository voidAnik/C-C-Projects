
#include<stdio.h>
void main2() {
	char str[100];
	int n = 0, dup;
	printf("Enter a string: ");
	gets_s(str);
	while (str[n] != NULL)
		n++;

	for (int i = 0; i < n; i++) {
		dup = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (str[i] == str[j]) {
				dup++;
			}
		}
		if (dup!=0)
		printf("Character %c is repeated %d times\n", str[i], dup);
	}
}