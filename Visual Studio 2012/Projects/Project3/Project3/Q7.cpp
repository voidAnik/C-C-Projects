
#include<stdio.h>
#include<string.h>
void main7(){
	char str2[100], str1[100];
	int flag = 0;
	printf("Enter two string : \n");
	gets_s(str1);
	gets_s(str2);
	int len = strlen(str1);
	for (int i = 0; i < len; i++)
	{
		if (str1[i] == str2[i])
		{
		}
		else
		{
			flag = 1;
		}

		if (flag == 1)
			break;
	}
	if (flag == 0)
		puts("Strings are same");

	else
		puts("Strings are not same");
}