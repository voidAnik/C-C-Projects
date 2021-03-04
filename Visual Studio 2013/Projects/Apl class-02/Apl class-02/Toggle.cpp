
#include <stdio.h>
void main1()
{
	char str[100];
	int i = 0;
	printf("Enter a string: ");
	gets_s(str);
	for (int i = 0; str[i] != NULL;i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
	puts(str);
}