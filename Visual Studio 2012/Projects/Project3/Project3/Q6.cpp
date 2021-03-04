
#include<stdio.h>
#include<string.h>
void main6(){
	char str2[100], str1[100];
	printf("Enter two string : \n");
	gets_s(str1);
	gets_s(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len2; i++)
	{
		str1[len1] = str2[i];
		len1++;
	}
	str1[len1] = NULL;
	puts(str1);
}