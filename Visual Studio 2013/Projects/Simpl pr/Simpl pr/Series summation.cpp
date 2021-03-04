
#include<stdio.h>
void main54()
{
	int n;
	int fact=1,sum=0;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			fact *= j;
		}
		sum = sum + fact;
		fact = 1;
	}
	printf("Summation of %d series : %d\n", n, sum);
}