
#include <stdio.h>
const int SIZE = 100;
void main10234()
{
	int arr[SIZE];
	int size, i, j, count=0,occur=0;
	int index = -1;
	printf("Enter size of array: ");
	scanf_s("%d", &size);
	printf("Enter elements in array: ");
	for (i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	for (i = 0; i < size; i++)
	{
		count = 0;
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}

		if (occur<count)
		{
			occur = count;
			index = i;
		}
	}
	printf("\nMostly repeated number is : %d\n",arr[index]);
}