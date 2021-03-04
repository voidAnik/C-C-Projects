/*Question number 8*/
#include <stdio.h>
void main8()
{
	char str[100];
	int count=1;
	gets_s(str);
	for(int i=0;str[i]!=NULL;i++)
	{
		if(str[i]==' ')
		{
			count++;
		}
	}
	printf("Number of words: %d",count);
}