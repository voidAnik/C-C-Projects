//Question number 9
#include <stdio.h>
#include <string.h>


void main9()
{
	char str1[100], str2[100];
	int j = 0, flag = 0;
	printf("Enter first string: ");
	gets_s(str1);
	int len = strlen(str1);
	for (int i = len-1; i >= 0; i--){
		str2[j] = str1[i];
		j++;
	}

	str2[j] = '\0';
	
	for (int i = 0, j = 0; i < len; i++, j++) {
		if (str1[i] != str2[j])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		printf("The word is Palindrom");
	}
	else{
		printf("The word is not Palindrom");
	}
	puts("");
}


	