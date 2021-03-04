#include<stdio.h>
int fun(int num){
	if (num == 0){
		return 0;
	}
	return (num%10 + fun(num / 10));
}
void main100(){
	int n,result;
	scanf_s("%d", &n);
	result = fun(n);
	printf("%d", result);
}