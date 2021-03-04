#include<stdio.h>
#include<string.h>
int palindrome(char ch1[]);
void mai235n()
{
	char ch[100], ch1[100] = { NULL };
	int i, n, j = 0;
	gets_s(ch);
	//getchar();
	n = strlen(ch);
	ch[n] = ' ';
	ch[n+1] = NULL;
	n = strlen(ch);
	for (i = 0; i < n; i++)
	{
		ch1[j] = ch[i];
		j++;
		if (ch[i] == ' ')
		{
			ch1[--j] = NULL;
			puts(ch1);
			//puts("try");
			palindrome(ch1);
			if (palindrome(ch1))
			{
				printf("Palindrom\n");
			}
			j = 0;
		}
		
	}
}
int palindrome(char ch1[])
{
	int count = 0, k;
	int m = strlen(ch1) - 1;
	int l = m;
	for (k = 0; k < m; k++)
	{
		if (ch1[k] == ch1[l])
		{
			count++;
		}
		l--;
	}
	
	if (count == m)
	{
		return 1;
	}
	else
		return 0;
}