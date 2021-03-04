/*Question Number 5*/
#include<stdio.h>
#include<string.h>
void main5(){
	char str[100];
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] == ' '){
			puts("");
		}
		else {
			printf("%c",str[i]);
		}
	}
	puts("");
}