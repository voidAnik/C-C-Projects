
#include<stdio.h>
void main3546()
{
	int tBoard[100][100];
	int ver0, ver1, hor0, hor1, digMj0 = 0, digMj1 = 0, digMn0 = 0, digMn1 = 0; //flags for counting
	int lim;

	printf("Enter the limit of board:_");
	scanf_s("%d", &lim);
	puts("Input results board:\n");

	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim; j++)
		{
			scanf_s("%d", &tBoard[i][j]);
		}
	}
	puts("");
	//Checking results

	for (int i = 0; i < lim; i++)
	{
		ver0 = 0;
		ver1 = 0;
		hor0 = 0;
		hor1 = 0;
		for (int j = 0; j < lim; j++)
		{
			if (tBoard[i][j] == 0)
			{
				hor0++;
			}
			if (tBoard[i][j] == 1)
			{
				hor1++;
			}
			if (tBoard[j][i] == 0)
			{
				ver0++;
			}
			if (tBoard[j][i] == 1)
			{
				ver1++;
			}
			if (tBoard[i][j - i - 1] == 0)
			{
				digMn0++;
			}
			if (tBoard[i][j - i - 1] == 1)
			{
				digMn1++;
			}
		}
		//Checking Major diagonal
		if (tBoard[i][i] == 0)
		{
			digMj0++;
		}
		if (tBoard[i][i] == 1)
		{
			digMj1++;
		}

		//Printing results
		if (hor0 == lim)
		{
			puts("0 win horizontally!");
		}
		if (hor1 == lim)
		{
			puts("1 win horizontally!");
		}
		if (ver0 == lim)
		{
			puts("0 win vertically!");
		}
		if (ver1 == lim)
		{
			puts("1 win vertically!");
		}
		if (digMj0 == lim || digMn0 == lim)
		{
			puts("0 win diagonally!");
		}
		if (digMj1 == lim || digMn1 == lim)
		{
			puts("1 win diagonally!");
		}
	}

}