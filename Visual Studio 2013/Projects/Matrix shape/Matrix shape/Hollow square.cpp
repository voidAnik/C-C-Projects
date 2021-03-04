

#include<stdio.h>
void main3()
{
	int size;
	scanf_s("%d", &size);
	for (int i = 1; i <= size; i++)
	{
			for (int j = 1; j <= size; j++)
			{
				if (i==1 || i== size || j == 1 || j == size)
				{
					printf("%d", j);
				}
				else
				{
					printf(" ");
				}
			}

		printf("\n");
	}
}