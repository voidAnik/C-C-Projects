#include<stdio.h>
void main5678()
{
	int A[100][100], n, i, j, count = 0;
	scanf_s("%d", &n);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			scanf_s("%d", &A[i][j]);
		}
	}
	puts("");
	
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (A[i][j] == 1)
			{
				count++;
			}
			if (count == n)
			{
				printf("1 Won horizentally !!!");
			}
		}
		count = 0;
	}
	puts("");
	puts("");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (A[i][j] == 0)
			{
				count++;
			}
			if (count == n)
			{
				printf("0 Won horizentally !!!");
			}
		}
		count = 0;
	}
	puts("");
	puts("");
	int k = 0;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (A[k][i] == 1)
			{
				count++;
			}
			if (count == n)
			{
				printf("1 Won Vertically !!!");
			}
			k++;
		}
		k = 0;
		count = 0;
	}
	puts("");
	puts("");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (A[k][i] == 0)
			{
				count++;
			}
			if (count == n)
			{
				printf("0 Won Vertically !!!");
			}
			k++;
		}
		k = 0;
		count = 0;
	}
	puts("");
	puts("");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (A[i] == A[j])
			{
				if (A[i][j] == 1)
				{
					count++;
				}
				if (count == n)
				{
					printf("1 Won diagonally !!!");
				}
			}
		}
	}
	count = 0;
	puts("");
	puts("");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (A[i] == A[j])
			{
				if (A[i][j] == 0)
				{
					count++;
				}
			}
			if (count == n)
			{
				printf("0 Won diagonally !!!");
			}
		}
	}
	count = 0;
	for (i = 0; i<n; i++)
	{
		if (A[i][n - i - 1] == 1)
			count++;
		if (count == n)
			printf("1 won diagonally");
	}
	count = 0;
	for (i = 0; i<n; i++)
	{
		if (A[i][n - i - 1] == 0)
			count++;
		if (count == n)
			printf("0 won diagonally");
	}
	puts("");
	puts("");

}
