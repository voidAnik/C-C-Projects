
#include<stdio.h>
#include<string.h>
void main4(){
	char str2[100], str1[100], str3[100];
	int j = 0;
	printf("Enter two string : \n");
	gets_s(str1);
	gets_s(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++)
	{
		str3[j] = str1[i];
		j++;
	}
	for (int i = 0; i < len2; i++)
	{
		str3[j] = str2[i];
		j++;
	}
	str3[j] = NULL;
	puts(str3);
}