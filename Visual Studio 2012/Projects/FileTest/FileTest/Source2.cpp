#include<stdio.h>
#include<string.h>
int main ()
{
    char ch[100],temp;
    gets(ch);
    int i,n;
    n = strlen(ch);
    for (i=0 ; i<n/2 ; i++)
    {
        temp=ch[i];
        ch[i]=ch[(n-1)-i];
        ch[(n-1)-i]=temp;
    }
    puts(ch);
    getchar();
    return 0;
}