
#include <stdio.h>
int main4()
{
	char str[100];
	gets_s(str);
	int n = 0;
	while (str[n] != NULL)
	{
		n++;
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = i + 1; j<n; j++)
		{
			if (str[i] == str[j])
			{
				for (int k = j; k<n; k++)
				{
					str[k] = str[k + 1];
				}
				n--;
				j--;
			}
		}
	}
	str[n] = NULL;
	printf("\nString after deleting duplicates : ");
	puts(str);
}