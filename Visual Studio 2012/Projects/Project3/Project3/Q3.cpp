//Question number 3
#include<stdio.h>
#include<string.h>
void main3(){
	char str1[100];
	int index = 0;
	gets_s(str1);
	int len1 = strlen(str1);
	for (int i = 0; i < len1; i++){
		if (i % 2 == 1){
			printf("%c", str1[i]);
		}
	
	}
	puts("");
}