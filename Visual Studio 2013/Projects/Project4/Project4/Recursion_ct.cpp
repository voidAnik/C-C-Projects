
#include<stdio.h>

int power(int num, int pow)
{
	if (pow == 0)
	{
		return 1;
		
	}
	return (num * power(num, pow - 1));
}
void mainrr()
{
	int number = 0, pow = 0, ans = 0;
	scanf_s("%d", &number);
	scanf_s("%d", &pow);
	ans = power(number, pow);
	printf("%d\n", ans);
}