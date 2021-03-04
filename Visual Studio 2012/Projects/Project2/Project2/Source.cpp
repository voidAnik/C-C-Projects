
#include <stdio.h>
#include <stdlib.h>

int arr[100][70];

int findhighfreq(int row, int col);
void main() {
	int row, col;
	puts("Enter the row & column numbers:");
	scanf_s("%d %d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			arr[i][j] = rand() % 10;

		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}
	findhighfreq(row, col);
}
int findhighfreq(int row, int col)
{
	int count = 0;
	int fcount = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col-1; j++)
		{
			count = 0;
			for (int k = j + 1; k < col; j++)
			{
				if (arr[i][j] == arr[i][k])
				{
					count++;
				}
			}
			if (fcount < count)
			{
				fcount = count;
			}
		}
	}
	printf("%d", fcount);
	return 0;
}