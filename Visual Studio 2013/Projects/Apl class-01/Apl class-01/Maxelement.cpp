
#include <stdio.h>
#include <stdlib.h>

int arr[100][50];
int frow, fcol;

int findmax(int row, int col);
void main3() {
	int row, col;
	puts("Enter the row & column numbers:");
	scanf_s("%d %d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			arr[i][j] = rand()%10;

		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}
	int max=findmax(row,col);

	printf("\nThe maximum element is %d in row: %d and column: %d\n\n", max, frow, fcol);

}
int findmax(int row,int col)
{
	int max=arr[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (max < arr[i][j])
			{
				max = arr[i][j];
				frow = i+1;
				fcol = j+1;
			}

		}
	}
	return max;
}