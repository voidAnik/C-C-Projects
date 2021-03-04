
#include <stdio.h>
#include <stdlib.h>

int arr[100][60];
int grow, gcol;

int finder(int row, int col,int num);
void main4() {
	int row, col,num;
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
	puts("Enter the number:");
	scanf_s("%d", &num);
	int check=finder(row, col,num);
	if (check == 1)
	{
		puts("Found the number");
		printf("Row :%d & column:%d \n\n", grow, gcol);
	}
	else
	{
		puts("Number not found");
	}
}
int finder(int row, int col,int num)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (num == arr[i][j])
			{
				grow = i + 1;
				gcol = j + 1;
				return 1;
				break;
			}
		}
	}
}