
#include<stdio.h>
void main1()
{
	int arr[100];
	int size;
	scanf_s("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		if (i == size)
		{
			for (int j = 1; j <= size; j++)
			{
				printf("%d", j);
			}
		}
		else
		{
			for (int j = 1; j <= size; j++)
			{
				if (j == 1 || j == size)
				{
					printf("%d", j);
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}