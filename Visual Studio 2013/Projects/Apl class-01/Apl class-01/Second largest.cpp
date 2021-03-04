
#include <stdio.h>
#include<stdlib.h>

int findseclarge(int row, int col);

int arr[100][40];
int arow, acol;
int main()
{
	int row, col;
	puts("Enter the row & column numbers:");
	scanf_s("%d %d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			arr[i][j] = rand() % 20;

		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}
	int seclarge=findseclarge(row, col);
	printf("Second large elements in this array:%d\n\n", seclarge);
}
int findseclarge(int row, int col)
{
	int max1,max2;
	max1 = max2 = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (max1 < arr[i][j])
			{
				max1 = arr[i][j];
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (max2 < arr[i][j] && arr[i][j] < max1)
			{
				max2 = arr[i][j];
				arow = i + 1;
				acol = j + 1;

			}
		}
	}

	return max2;

}