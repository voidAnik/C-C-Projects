
#include <stdio.h>
#include <stdlib.h>

int arr[100][70];
int fcount = 0;
int brow, bcol;
int findhighfreq(int row, int col);
void main6() {
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
	int maxElement=findhighfreq(row, col);
	printf("First highest frequency element is:%d && it's repeated : %d times\n", maxElement,fcount-1);
	printf("This elements row no: %d & column no: %d: \n\n", brow, bcol);
}
int findhighfreq(int row, int col)
{
	int maxElement=0;
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			count = 0;
			for (int l = 0; l < row; l++)
			{
				for (int k = 0; k < col; k++)
				{
					if (arr[i][j] == arr[l][k])
					{
						count++;
					}
				}
			}
			//printf("e:%d c:%d ", arr[i][j], count);
			if (fcount < count)
			{
				fcount = count;
				maxElement = arr[i][j];
				brow = i + 1;
				bcol = j + 1;
			}
			//printf("%d m:%d ", fcount, maxElement);
		}
	}
	//printf("%d m:%d", fcount,maxElement);
	return maxElement;
}