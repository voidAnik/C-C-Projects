

#include < stdio.h>
#include < string.h>
void main()
{
	char str[100];
	int t = 0, flag = 0;
	char ch;
	printf("Enter a string : \n");
	gets_s(str);
	ch=getchar();
	//scanf("%c",&ch);
	int len = strlen(str);

	str[len] = ' ';

	for (int i = 0; i <= len; i++)
	{
		if ((str[i] == ' ') && (str[i - 1] == ch))
		{
			for (int j = t; j < i; j++)
				printf("%c", str[j]);

			t = i + 1;
			flag=1;
			printf("\n");
		}
		else
		{
			if (str[i] == ' ')
			{
				t = i + 1;
			}
		}
	}
	if(flag==0)
		puts("No word with k");
}