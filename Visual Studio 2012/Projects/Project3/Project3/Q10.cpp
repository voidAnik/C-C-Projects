//Question number 10
#include <stdio.h>
#include <string.h>


void main10()
{
	char str1[100];
	printf("Enter first string: ");
	gets_s(str1);
	int len = strlen(str1);
	for (int i = 0; i < len - 1; i++){

		for (int j = i+1; j < len; j++){
			if (str1[i] == str1[j])
			{
				//str1[i] = '#'; 
				str1[j] = '#';
			}

		}
	}
	puts(str1);

}
	
	