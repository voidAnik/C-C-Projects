#include<stdio.h>
void passByValue(int b, char s[]){
	b = 5;
	s[0] = 'F';
	printf("In passByValue and b = %d , s = %s\n", b, s);
}
void passByReference(int *b, char *t){
	*b = 5;
	t[0] = 'G';
	printf("In passByReference and b = %d, s = \n", *b);
	while (*t){
		printf("%c", *t);
		t++;
	}
	printf("\n");
}
int main6775483(){
	int k;
	printf("%d\n", sizeof(long));
	int a = 4;
	int *p = &a;
	char str[40] = "No one beats the wiz";
	char *t = str;
	printf("Before call: %d %s\n", a, str);
	passByValue(a, str);
	printf("After first call: %d %s\n", a, str);
	passByReference(p, t); //passByReference(&a,t);
	printf("After second call: %d %s\n", a, str);
	return 0;
}