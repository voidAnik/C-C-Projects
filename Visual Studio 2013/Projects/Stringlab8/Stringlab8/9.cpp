
#include<stdio.h>
const int SIZE = 100;
int find_substr(char a[], char b[]);
void main()
{
	char a[SIZE];
	char b[SIZE];
	gets_s(a);
	gets_s(b);
	int ret=find_substr(a, b);
	printf("%d\n\n", ret);

}
int find_substr(char a[], char b[])
{
	int i, j = 0, count, length = 0,k=0;
	for (int i = 0; b[i] != NULL; i++)
	{
		length++;
	}
	for (i = 0; a[i] != NULL; i++)
	{
		count = 0;
		k = 0;
		if (a[i] == b[0])
		{
			for (j = i; a[j] != NULL; j++, k++)
			{
				if (a[j] == b[k])
				{
					count++;
				}
			}
				if (count == length)
				{
					break;
				}
		}
	}
	if (count == length)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}