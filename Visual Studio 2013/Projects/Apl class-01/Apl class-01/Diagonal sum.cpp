
#include<stdio.h>
#include<stdlib.h>
int arr[100][100];
int majordig(int row, int col);
int minordig(int row, int col);
void main2()
{
	int row, col;
	puts("Enter the row & column numbers:");
	scanf_s("%d %d", &row, &col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//arr[i][j] = rand();
			scanf_s("%d", &arr[i][j]);
		}
	}
	int majsum=majordig(row,col);
	int minsum=minordig(row, col);
	printf("Major sum:%d\nMinor sum:%d", majsum, minsum);

}
int majordig(int row,int col)
{
	int sum=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
			{
				sum += arr[i][j];
			}
		}
	}
	return sum;
}
int minordig(int row, int col)
{
	int sum=0;
	for (int i = 0; i < row; i++)
	{
		sum += arr[i][(col-1) - i];
	}
	return sum;
}
