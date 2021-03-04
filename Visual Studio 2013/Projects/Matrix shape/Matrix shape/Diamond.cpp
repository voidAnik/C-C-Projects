
#include<stdio.h>
void main2()
{
	int size;
	scanf_s("%d", &size);
	int k = 0;
	for (int i = 1; i <= size; i++)
	{
		for (int j = size; j >= i; j--)
		{
			printf("_");
		}
		for (int j = 1; j <= (2 * i - 1); j++)
		{
			if (j == 1 || j == (i * 2 - 1))
			{
				printf("#");
			}
			else
			{
				printf("_");
			}
		}
		puts("");
	}
	for (int i = 1; i <size ; i++)
	{
		for (int j =0; j <= i;j++)
		{
			printf("_");
		}
		for (int j =k ; j < (size * 2 - 3);j++)
		{
			if (j == k || j == (size * 2 - 3)-1)
			{
				printf("#");
			}
			else
			{
				printf("_");
			}
		}
		k += 2;
		printf("\n");
	}
}