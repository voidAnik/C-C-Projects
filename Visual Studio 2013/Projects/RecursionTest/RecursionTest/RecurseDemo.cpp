
#include<stdio.h>
void recursePrint(int i)
{
	if (i == 1)
		printf("1\n");
	else{
	recursePrint(i - 1);
	printf("%d\n", i);
	}
}
void main()
{
	recursePrint(4);
}